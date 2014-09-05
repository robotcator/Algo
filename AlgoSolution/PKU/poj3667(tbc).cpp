/*
    ID: problem6
    PROG : Hotel
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = (1LL) << 17;
int sum[maxn], lsum[maxn], rsum[maxn];
int cover[maxn];
// sum 为区间内最大的连续的区间
//lsum为左端点最大的连续的区间，rsum为右端点向左最大的连续的区间
// cover用0表示不占用，1表示占用
void build(int root, int l, int r){
  sum[root] = lsum[root] = rsum[root] = r-l+1;
  if(l < r){
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
  }
}

void pushdown(int root){
  int lc = 2*root, rc = 2*root+1;
  if(cover[root] > -1){
    cover[lc] = cover[rc] = cover[root];
    cover[root] = -1;
  }
}

void maintain(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  int len = (r-l+1); // 区间长度
  if(r > l){
    lsum[root] = lsum[lc];
    if(lsum[lc] == len-len/2) lsum[root] += lsum[rc];
    // 如果左端连续区间超过中指，即左子树全为相同区间
    rsum[root] = rsum[rc];
    if(rsum[rc] == len/2) rsum[root] += rsum[lc];
    //是否超过mid的连续区间
    sum[root] = max(rsum[lc]+lsum[rc], max(sum[lc], sum[rc]));
  }
  if(cover[root] > -1){
    if(cover[root] == 0) lsum[root] = rsum[root] = sum[root] = len;
    else if(cover[root] == 1) lsum[root] = rsum[root] = sum[root] = 0;
  }
}


void modify(int root, int l, int r, int x, int y, int s){
  if(x <= l && r <= y){
    cover[root] = s;
  }else{
    pushdown(root);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, s);
    maintain(2*root, l, mid);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, s);
    maintain(2*root+1, mid+1, r);
  }
  maintain(root, l, r);
}

int query(int root, int l, int r, int z){
  int lc = 2*root, rc = 2*root+1 , mid = (l+r)/2;
  if(l == r){
    return l;
  }else{
    pushdown(root);
    maintain(root, l, r);
    if(sum[lc] >= z) return query(2*root, l, mid, z);
    else if(rsum[lc] + lsum[rc] >= z){
      return mid-rsum[lc]+1;
    }
    else return query(2*root+1, mid+1, r, z);
  }
}

void print(int root, int l, int r){
    printf("%d %d %d %d %d\n", root, cover[root], lsum[root], rsum[root], sum[root]);
    if(l < r){
      int mid = (l+r)/2;
      print(2*root, l, mid);
      print(2*root+1, mid+1, r);
    }
}

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    memset(cover, -1, sizeof(cover));
    build(1, 1, n);
    int a, b, c;
    for(int i = 0; i < m; i ++){
      scanf("%d", &a);
      if(a == 1){
        scanf("%d", &b);
        if(sum[1] >= b){
          int temp = query(1, 1, n, b);
          printf("%d\n", temp);
          modify(1, 1, n, temp, temp+b-1, 1);
         // print(1, 1, n);
        }else{
          printf("0\n");
        }
      }else{
        scanf("%d%d", &b, &c);
        modify(1, 1, n, b, b+c-1, 0);
       // print(1, 1, n);
      }
    }
  }
  return 0;
}
