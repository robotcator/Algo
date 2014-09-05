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

const int maxn = 50000+10;
int sum[4*maxn];
int data[maxn];

void build(int root, int l, int r){
  if(l < r){
    int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    sum[root] = sum[lc] + sum[rc];
  }else if(l == r){
    sum[root] = data[l];
   // 注意root并不是叶子节点
  }
}

void modify(int root, int l, int r ,int p, int z){
    int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
    if(l == r) sum[root] += z;
    if(l < r){
      if(p <= mid) modify(lc, l, mid, p, z);
      else modify(rc, mid+1, r, p, z);
      sum[root] = sum[lc] + sum[rc];
    }
}

int query(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    return sum[root];
  }else{
    int lsum, rsum;
    lsum = rsum = 0;
    if(x <= mid) lsum = query(lc, l, mid, x, y);
    if(y > mid) rsum = query(rc, mid+1, r, x, y);
    return lsum+rsum;
  }
}

void print(int root, int l, int r){
  printf("%d %d\n", root, sum[root]);
  if(l < r){
    int mid = (l+r)/2;
    print(2*root, l, mid);
    print(2*root+1, mid+1, r);
  }
}

int main(){
  int t, n;
  scanf("%d", &t);
  for(int test = 1; test <= t; test ++){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
    }
    build(1, 1, n);
    //print(1, 1, n);
    printf("Case %d:\n", test);
    while(true){
      char comm[10];
      int x, y;
      scanf("%s", comm);
      if(strcmp(comm, "End") == 0) break;
      scanf("%d %d", &x, &y);
      if(strcmp(comm, "Sub") == 0) {
          modify(1, 1, n, x, -y);
      }else if(strcmp(comm, "Add") == 0) {
          modify(1, 1, n, x, y);
      }else if(strcmp(comm, "Query") == 0){
          int ans = query(1, 1, n, x, y);
          printf("%d\n", ans);
      }
    }
  }
  return 0;
}
