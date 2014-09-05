/*
    ID: problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2000+10;
struct people{
  long long x, y;
};
people p[maxn];

bool cmp(people a, people b){
  return a.x - b.x < 0;
}
int st[8*maxn];
int setv[8*maxn];
long long py[2*maxn];


void build(int root, int l, int r){
  if(l < r){
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
  }else{
    st[root] = setv[root] = 0;
  }
}

void pushdown(int root, int l, int r){
  if(setv[root]){
    int lc = 2*root, rc = 2*root+1, mid = (l+r)/2;
    setv[lc] += setv[root];
    setv[rc] += setv[root];
    st[lc] += setv[root];
    st[rc] += setv[root];
    setv[root] = 0;
  }
}

void pushup(int root, int l, int r){
    int lc = 2*root, rc = 2*root+1;
    st[root] = max(st[lc], st[rc]);
}

void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] += z;
    st[root] += z;
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, z);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, z);
    pushup(root, l, r);
  }
}



int main(){
  int n, r;
  while(scanf("%d%d", &n, &r) != EOF){
    memset(setv, 0, sizeof(setv));
    memset(st, 0, sizeof(st));
    for(int i = 1; i <= n; i ++){
      scanf("%lld %lld", &p[i].x, &p[i].y);
      //cin >> p[i].x >> p[i].y ;
     // cout << p[i].x << " " << p[i].y << endl;
      py[i] = p[i].y; py[i+n] = p[i].y + r ;
    }
    sort(py+1, py+2*n+1);
    int m = unique(py+1, py+2*n+1)-py-1;
    build(1, 1, m);
    sort(p+1, p+n+1, cmp);
    int j = 1;
    int ans = 0;
    for(int i = 1; i <= n; i ++){
      int l1 = lower_bound(py+1, py+m+1, p[i].y)-py;
      int r1 = lower_bound(py+1, py+m+1, p[i].y+r)-py;
      modify(1, 1, m, l1, r1, 1);
      while(j <= i && p[j].x < p[i].x-r){
        int ll = lower_bound(py+1, py+m+1, p[j].y) - py;
        int rr = lower_bound(py+1, py+m+1, p[j].y+r) - py;
        modify(1, 1, m, ll, rr, -1);
        j ++;
      }
      if(st[1] > ans) ans = st[1];
    }
    printf("%d\n", ans);
  }
  return 0;
}

/*
命名一多不要重复命名以前习惯的命名
注意建树的区间和查询区间一致
*/
