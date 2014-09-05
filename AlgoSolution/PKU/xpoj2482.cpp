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
long long px[8*maxn];
bool cmp(point a, point b){
  return a.y - b.y < 0;
}
int M[10*maxn], setv[10*maxn];

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
    setv[lc] = setv[rc] += setv[root];
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
    for(int i = 1; i <= n; i ++){
      scanf("%lld %lld %d", &p[i].x, &p[i].y, &p[i].bright);
      px[i] = p[i].x;  px[i+n] = p[i].x + w;
    }
    sort(px+1, px+2*n+1);
    int m = unique(px+1, px+2*n+1) - px - 1;
    sort(p+1, p+n+1, cmp);
    build(1, 1, m);
    int j = 1;
    long long ans = 0;
    for(int i = 1; i <= n; i ++){
      //cout << p[i].x << " " << p[i].y << endl;
      int l = lower_bound(px+1, px+m+1, p[i].x) - px ;
      int r = lower_bound(px+1, px+m+1, p[i].x+w) - px ;
      //cout << "range" << l << " " << r-1 << endl;
      modify(1, 1, n, l, r-1, p[i].bright);
      while(j <= i && p[j].y <= p[i].y - h){
        //cout << "j" << j << endl;
        int ll = lower_bound(px+1, px+m+1, p[j].x) - px ;
        int rr = lower_bound(px+1, px+m+1, p[j].x+w) - px;
        modify(1, 1, n, ll, rr-1, -p[j].bright);
        j ++;
      }
      //cout << "sum" << M[1] << endl;
      if(ans < M[1]) ans = M[1];
    }
    cout << ans << endl;
  }
  return 0;
}
