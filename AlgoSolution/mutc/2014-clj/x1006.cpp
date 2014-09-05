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

const int maxn = 100000+10;
// 2^17 = 131072 跟 100000同数量级
int data[maxn];
// 原来的序列
int setv[4*maxn];
// 标记
int M[4*maxn];
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
  if(setv[root] > -1){
    setv[2*root] = setv[2*root+1] = setv[root];
    setv[root] = -1;
  }
}

void maintain(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  if(r > l){
    M[root] = max(M[lc], M[rc]);
  }
  if(setv[root] > -1) {
    M[root] = setv[root];
  }
}

void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] = z;
   // cout << "root" << root << endl;
    // M[root] = setv[root];
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, z);
    maintain(2*root, l, mid);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, z);
    maintain(2*root+1, mid+1, r);
  }
  maintain(root, l, r);
}

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

void update(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    if(setv[root] > z && l != r){
      int temp = gcd(setv[root], z);
      setv[root] = temp;
    }else if(l == r){
      if(setv[root] > z){
        int temp = gcd(setv[root], z);
        M[root] = temp;
        setv[root] = -1;
      }else if(setv[root] == -1){
        if(M[root] > z){
          int temp = gcd(M[root], z);
          M[root] = temp;
        }
      }
      // 注意
    }else if(setv[root] == -1 && M[root] > z){
      pushdown(root, l, r);
      int mid = (l+r)/2;
      if(x <= mid) update(2*root, l, mid, x, y, z);
      maintain(2*root, l, mid);
      if(y > mid) update(2*root+1, mid+1, r, x, y, z);
      maintain(2*root+1, mid+1, r);
    }
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) update(2*root, l, mid, x, y, z);
    maintain(2*root, l, mid);
    if(y > mid) update(2*root+1, mid+1, r, x, y, z);
    maintain(2*root+1, mid+1, r);
  }
  maintain(root, l, r);
}

/*
void update(int root, int l, int r, int x, int y, int z){
    if(x <= l && r <= y){
      if(l == r){
        if(M[root] > z) {
          int temp = gcd(M[root], z);
          M[root] = temp;
          setv[root] = -1;
          // 一定要重新重置标记
        }
      }else{
        pushdown(root, l, r);
        int mid = (l+r)/2;
        if(x <= mid) update(2*root, l, mid, x, y, z);
        maintain(2*root, l, mid);
        if(y > mid) update(2*root+1, mid+1, r, x, y, z);
        maintain(2*root+1, mid+1, r);
      }
    }else{
      pushdown(root, l, r);
      int mid = (l+r)/2;
      if(x <= mid) update(2*root, l, mid, x, y, z);
      else maintain(2*root, l, mid);
      if(y > mid) update(2*root+1, mid+1, r, x, y, z);
      else maintain(2*root+1, mid+1, r);
    }
}
*/
void print(int root, int l, int r){
  if(l == r){
    printf("%d %d\n", root, M[root]);
  }else{
    int mid = (l+r)/2;
    print(2*root, l, mid);
    print(2*root+1, mid+1, r);
  }
}

void ans(int root, int l, int r){
  if(setv[root] > -1){
    for(int i = l; i <= r; i ++){
      printf("%d ", setv[root]);
    }
  }else if(l == r){
    printf("%d ", M[root]);
  }else{
    int mid = (l+r)/2;
    pushdown(root, l, r);
    ans(2*root, l, mid);
    ans(2*root+1, mid+1, r);
  }
}

int main(){
  int t, c;
  scanf("%d", &t);
  while(t --){
    memset(setv, -1, sizeof(setv));
    memset(M, 0, sizeof(M));
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
    }
    build(1, 1, n);
    //print(1, 1, n);
    scanf("%d", &c);
    int T, l, r, x;
    for(int i = 0; i < c; i ++){
      scanf("%d%d%d%d", &T, &l, &r, &x);
      if(T == 1){
        modify(1, 1, n, l, r, x);
        //print(1, 1, n);
      }else if(T == 2){
        update(1, 1, n, l, r, x);
       //print(1, 1, n);
      }
    }
    ans(1, 1, n);
    printf("\n");
  }
  return 0;
}
