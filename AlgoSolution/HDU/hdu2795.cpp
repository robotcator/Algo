/*
    ID : problem6
    PROG : Billboard
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
// 因为最多200000查询
int mm[4*maxn];

int w, h, n;

void build(int root, int l, int r){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(l < r){
    build(lc, l, mid);
    build(rc, mid+1, r);
    mm[root] = max(mm[lc], mm[rc]);
  }else{
    mm[root] = w;
  }
}

int ans ;
void query(int root, int l, int r, int val){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(l == r){
    ans = l;
    mm[root] -= val;
  }else{
    if(val <= mm[lc]) query(lc, l, mid, val);
    else query(rc, mid+1, r, val);
    mm[root] = max(mm[lc], mm[rc]);
  }
}

int main(){
  while(scanf("%d%d%d", &h, &w, &n) != EOF){
    int x;
    h = min(200000, h);
    build(1, 1, h);
    for(int i = 0; i < n; i ++){
      ans = -1;
      scanf("%d", &x);
      if(x > mm[1]) printf("%d\n", -1);
      else{
        query(1, 1, h, x);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}

/*
如果线段过多，看查询的次数和查询的作用
看是否是某个题目的变形
如果不能，则想其他算法

*/
