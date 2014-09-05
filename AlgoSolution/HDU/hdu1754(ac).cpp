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

const int maxn = 200000+10;
int score[maxn];
int mm[4*maxn];

void build(int root, int l, int r){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(l < r){
    build(lc, l, mid);
    build(rc, mid+1, r);
    mm[root] = max(mm[lc], mm[rc]);
  }else{
    mm[root] = score[l];
  }
}

void modify(int root, int l, int r, int p, int z){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(l == r){ mm[root] = z; }
  else {
    if(p <= mid) modify(lc, l, mid, p, z);
    else modify(rc, mid+1, r, p, z);
    mm[root] = max(mm[lc], mm[rc]);
  }
}

int ans = 0;
void query(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    ans = max(ans, mm[root]);
  }else{
    if(x <= mid) query(lc, l, mid, x, y);
    if(y > mid) query(rc, mid+1, r, x, y);
  }
}

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &score[i]);
    }
    build(1, 1, n);
    char comm[10];
    int x, y;
    for(int i = 1; i <= m; i ++){
      scanf("%s%d%d", comm, &x, &y);
     // printf("%s %d %d\n", comm, x, y);
      if(strcmp(comm, "U") == 0){
        modify(1, 1, n, x, y);
      }else{
        ans = 0;
        query(1, 1, n, x, y);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
