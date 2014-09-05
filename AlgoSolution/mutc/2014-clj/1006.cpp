/*
    ID: problem6
    PROG : ride
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000;
// 2^17 = 131072 跟 100000同数量级
int data[maxn];
// 原来的序列
long long setv[5*maxn];
// 标记
int M[5*maxn];
// 记录最大值
int n;

int build(int root, int l, int r){
  if(l == r){
    //st[root] = data[l];
    M[root] = data[l];
    return M[root];
  }else{
    int mid = (l+r)/2;
    int lc = build(2*root, l, mid);
    int rc = build(2*root+1, mid+1, r);
    M[root] = max(lc, rc);
    return M[root];
  }
}

void pushdown(int root, int l, int r){
  if(r > l){
    M[root] = max(M[2*root], M[2*root+1]);
  }
  if(setv[root] > -inf){
    setv[2*root] = setv[2*root+1] = setv[root];
    M[root] = M[2*root] = M[2*root+1] = setv[root];
    setv[root] = -inf;
  }
}

void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] = z;
    M[root] = z;
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, z);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, z);
    M[root] = max(M[2*root], M[2*root+1]);
  }
  //pushdown(root, l, r);
}

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

void update(int root, int l, int r, int x, int y, int z){
  if(l == r) { if(M[root] > z) M[root] = gcd(M[root], z); }
  if(x <= l && r <= y){
    if(M[root] > z){
      int mid = (l+r)/2;
      if(l == r && M[root] > z) {
        int temp = gcd(z, M[root]);
        M[root] = temp;
      }
      update(2*root, l, mid, x, y, z);
      update(2*root+1, mid+1, r, x, y, z);
    }
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) update(2*root, l, mid, x, y, z);
    if(y > mid) update(2*root+1, mid+1, r, x, y, z);
  }
}

void print_ans(int root, int l, int r){
  if(l == r){
   // printf("%d ", M[root]);
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    print_ans(2*root, l, mid);
    print_ans(2*root+1, mid+1, r);
  }
}

void print(int root, int l, int r){
  if(l == r){
    printf("%d ", M[root]);
  }else{
    int mid = (l+r)/2;
    print(2*root, l, mid);
    print(2*root+1, mid+1, r);
  }
}

void flag(int root, int l, int r){
  if(setv[root] > -inf) printf("%lld %lld\n", root, setv[root]);
  if(l < r){
    int mid = (l+r)/2;
    flag(2*root, l, mid);
    flag(2*root, mid+1, r);
  }
}


int main(){
  int t, c;
  scanf("%d", &t);
  while(t --){
    for(int i = 0; i < maxn; i ++)
      setv[i] = -inf;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
    }
    build(1, 1, n);
    scanf("%d", &c);
    int T, l, r, x;
    for(int i = 0; i < c; i ++){
      scanf("%d%d%d%d", &T, &l, &r, &x);
      if(T == 1){
        modify(1, 1, n, l, r, x);
        flag(1, 1, n);
        printf("\n");
        print_ans(1, 1, n);
       // printf("\n");

        printf("\n");
      }else if(T == 2){
        update(1, 1, n, l, r, x);
       // print_ans(1, 1, n);
       // printf("\n");
      }
    }
    //print_ans(1, 1, n);
    print(1, 1, n);
    printf("\n");
  }
  return 0;
}
