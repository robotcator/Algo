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

const int maxn = 100000+10;
int setv[4*maxn];
//long long sum[4*maxn];
long long sum[4*maxn];
int data[maxn];

void build(int root, int l, int r){
  setv[root] = 0;
  if(l < r){
    int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    sum[root] = sum[lc] + sum[rc];
  }else if(l == r){
    sum[root] = data[l];
  }
}

void pushdown(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1, mid = (l+r)/2;
  if(setv[root]){
    // 注意懒标记的使用
    setv[lc] += setv[root];
    setv[rc] += setv[root];
    sum[lc] += (long long)(mid-l+1)*(long long)setv[root];
    sum[rc] += (long long)(r-mid)*(long long)setv[root];
    setv[root] = 0;
  }
}

void pushup(int root, int l, int r){
    int lc = 2*root, rc = 2*root+1;
    sum[root] = sum[lc]+ sum[rc];
}

void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] += z;
    sum[root] += (long long)(r-l+1)*(long long)z;
  }else{
    int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
    pushdown(root, l, r);
    if(x <= mid) modify(lc, l, mid, x, y, z);
    if(y > mid) modify(rc, mid+1, r, x, y, z);
    pushup(root, l, r);
  }
}

long long ans;
void query(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    ans += sum[root];
  }else{
    pushdown(root, l, r);
    if(x <= mid) query(lc, l, mid, x, y);
    if(y > mid) query(rc, mid+1, r, x, y);
    pushup(root, l, r);
  }
}


void print(int root, int l, int r){
  //if(l == r)
    cout << root << " " << sum[root] << endl;
  if(l < r){
    int mid = (l+r)/2;
    print(2*root, l, mid);
    print(2*root+1, mid+1, r);
  }
}

int main(){
  int n, q;
  while(scanf("%d%d", &n, &q) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
    }
    memset(sum, 0, sizeof(sum));
    memset(setv, 0, sizeof(setv));
    build(1, 1, n);
    char comm[5];
    int x, y, z;
    for(int i = 0; i < q; i ++){
      scanf("%s %d %d", comm, &x, &y);
      if(strcmp(comm, "Q") == 0){
        ans = 0;
        query(1, 1, n, x, y);
        //printf("%lld\n", ans);
        printf("%I64d\n", ans);
      }else{
        scanf("%d", &z);
        modify(1, 1, n, x, y, z);
      }
    }

  }
  return 0;
}

// 注意两个非int的数据可能会爆long long所以要强制类型转换
