/*
    ID : problem6
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
int data[maxn];
int setv[4*maxn];
int lb[4*maxn], rb[4*maxn], sb[4*maxn];
int lw[4*maxn], rw[4*maxn], sw[4*maxn];

void pushup(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  int len = r-l+1;
  // 处理黑连块
  lb[root] = lb[lc];
  if(lb[lc] == len-len/2) lb[root] += lb[rc];
  rb[root] = rb[rc];
  if(rb[root] == len/2) rb[root] += rb[lc];
  sb[root] = max(rb[lc]+lb[rc], max(sb[lc], sb[rc]));
  // 右孩子的左边，左孩子的右边
  // 处理白连块
  lw[root] = lw[lc];
  if(lw[lc] == len-len/2) lw[root] += lw[rc];
  rw[root] = rw[rc];
  if(rw[root] == len/2) rw[root] += rw[lc];
  sw[root] = max(rw[lc]+lw[rc], max(sw[lc], sw[rc]));
}

void build(int root, int l, int r){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(l < r){
    build(lc, l, mid);
    build(rc, mid+1, r);
    pushup(root, l, r);
  }else{
    if(data[l] == 1){
      lb[root] = rb[root] = sb[root] = 1;
      lw[root] = rw[root] = sw[root] = 0;
    }else{
      lb[root] = rb[root] = sb[root] = 0;
      lw[root] = rw[root] = sw[root] = 1;
    }
  }
}

void exchange(int root){
  swap(lb[root], lw[root]);
  swap(rb[root], rw[root]);
  swap(sb[root], sw[root]);
}

void pushdown(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  if(setv[root]){
    setv[lc] ^= 1; setv[rc] ^= 1;
    setv[root] = 0;
    exchange(lc);  exchange(rc);
  }
}

void modify(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    setv[root] ^= 1;
    exchange(root);
  }else{
    pushdown(root, l, r);
    if(x <= mid) modify(lc, l, mid, x, y);
    if(y > mid) modify(rc, mid+1, r, x, y);
    pushup(root, l, r);
  }
}

// 区间查询
int query(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    return sb[root];
  }else{
    pushdown(root, l, r);
    int lsum, rsum;
    lsum = rsum = 0;
    if(y <= mid) return query(lc, l, mid, x, y);
    if(x > mid) return query(rc, mid+1, r, x, y);
    lsum = query(lc, l, mid, x, y);
    // 完全在左子树的
    rsum = query(rc, mid+1, r, x, y);
    // 完全在右子树的
    int len = r-l+1;
    int b1 = min(mid-x+1, rb[lc]);
    int b2 = min(y-mid, lb[rc]);
    // 横跨左右子树的，但是右不能重复计算
    return max(max(lsum, rsum), b1+b2);
  }
}


template <class T>
inline void Input(T &x){
  char c; x = 0;
  while((c = getchar()) < '0' || c > '9');
  while(c >= '0' && c <= '9') x = x*10 + (c-'0'), c = getchar();
}

template <class T>
inline void Output(T x){
  if(x > 9) Output(x/10);
  putchar(x%10+'0');
}

int main(){
  int n, m;
  while(scanf("%d", &n) != EOF){
    memset(setv, 0, sizeof(setv));
    for(int i = 1; i <= n; i ++){
      //scanf("%d", &data[i]);
      Input(data[i]);
    }
    build(1, 1, n);
    int a, b, c;
    //scanf("%d", &m);
    Input(m);
    for(int i = 1; i <= m; i ++){
     // scanf("%d%d%d", &a, &b, &c);
     Input(a); Input(b); Input(c);
      if(a == 0){
        int ans = query(1, 1, n, b, c);
        //printf("%d\n", ans);
         Output(ans);  puts("");
      }else{
        modify(1, 1, n, b, c);
      }
    }
  }
  return 0;
}
