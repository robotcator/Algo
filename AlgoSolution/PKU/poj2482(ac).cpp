/*
    ID: problem6
    PROG : Stars in Your Window
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 30000+10;
struct point{
  long long x, y;
  int bright;
};

point p[4*maxn];
long long py[4*maxn];
bool cmp(point a, point b){
  return a.x - b.x < 0;
}
int M[4*maxn], setv[4*maxn];

void build(int root, int l, int r){
  setv[root] = 0;
  M[root] = 0;
  if(l < r){
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
  }
}

void pushdown(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1, mid = (l+r)/2;
  if(setv[root]){
    setv[lc] += setv[root];
    setv[rc] += setv[root];
    M[lc] += setv[root];
    M[rc] += setv[root];
    setv[root] = 0;
  }
}

void pushup(int root, int l, int r){
    int lc = 2*root, rc = 2*root+1;
    M[root] = max(M[lc], M[rc]);
}

void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] += z;
    M[root] += z;
  }else{
    int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
    pushdown(root, l, r);
    if(x <= mid) modify(lc, l, mid, x, y, z);
    if(y > mid) modify(rc, mid+1, r, x, y, z);
    pushup(root, l, r);
  }
}

int main(){
  int n, w, h;
  while(scanf("%d %d %d", &n, &w, &h) != EOF){
    memset(M, 0, sizeof(M));
    memset(setv, 0, sizeof(setv));
    for(int i = 1; i <= n; i ++){
      scanf("%lld %lld %d", &p[i].x, &p[i].y, &p[i].bright);
      py[i] = p[i].y;  py[i+n] = p[i].y + h;
    }
    sort(py+1, py+2*n+1);
    int m = unique(py+1, py+2*n+1) - py - 1;
    sort(p+1, p+n+1, cmp);
    build(1, 1, m);
    int j = 1;
    int ans = 0;
    for(int i = 1; i <= n; i ++){
      //cout << p[i].x << " " << p[i].y << endl;
      int l = lower_bound(py+1, py+m+1, p[i].y) - py ;
      cout << p[i].y << " " << l << endl;
      int r = lower_bound(py+1, py+m+1, p[i].y+h) - py ;
      cout << p[i].y+r << " " << r << endl;
      //cout << "range" << l << " " << r-1 << endl;
      modify(1, 1, m, l, r-1, p[i].bright);
      while(j <= i && p[j].x <= p[i].x - w){
        //cout << "j" << j << endl;
        int ll = lower_bound(py+1, py+m+1, p[j].y) - py ;
        int rr = lower_bound(py+1, py+m+1, p[j].y+h) - py;
        modify(1, 1, m, ll, rr-1, -p[j].bright);
        // 一定要注意对谁建树
        j ++;
      }
      //cout << "sum" << M[1] << endl;
      if(ans < M[1]) ans = M[1];
    }
    cout << ans << endl;
  }
  return 0;
}
