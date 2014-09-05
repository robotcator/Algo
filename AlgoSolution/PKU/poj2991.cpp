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
#include <cmath>

using namespace std;

struct point{
  double x, y;
  double deg;
};
point p[10010];
// 2^14 与 10000数量级相当
const int maxn = (1LL) << 15;
const double eps = 1e-8;
point st[maxn];
double setv[maxn];

void init(){
  memset(p, 0, sizeof(p));
  memset(setv, -1, sizeof(setv));
}

void build(int root, int l, int r){
  if(l == r){
    st[root].x = p[l].y;
    st[root].y = p[l].y;
    st[root].deg = 0;
  }else{
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
    st[root].x = st[2*root].x + st[2*root+1].x;
    st[root].y = st[2*root].y + st[2*root+1].y;
  }
}

void pushdown(int root){
  if(setv[root] > 0){
    setv[2*root] = setv[2*root+1] = setv[root];
    setv[root] = -1;
  }
}

void Rotate(point& node, double z){
  double x = node.x;
  double y = node.y;
  node.x = x*cos(z) - y*sin(z);
  node.y = y*cos(z) + x*sin(z);
  node.deg = (int)(node.deg + z) % 360 + eps;
}

void maintain(int root, int l, int r){
  point& fa = st[root];
  point& lc = st[2*root];
  point& rc = st[2*root+1];
  if(setv[root] > 0){
    Rotate(lc, fa.deg);
    Rotate(rc, fa.deg);
  }
}

int query(int root, int l, int r, int pos){
  if(pos == 0) return 0;
  else if(l == r){
    return st[root].deg;
  }else{
    pushdown(root);
    maintain(root, l, r);
    int mid = (l+r)/2 ;
    if(pos <= mid) return query(2*root, l, mid, pos);
    if(pos > mid) return query(2*root+1, mid+1, r, pos);
  }
}

void modify(int root, int l, int r, int x, int y, double a){
  if(x <= l && r <= y){
    Rotate(st[root], a);
    setv[root] += a;
  }else{
    pushdown(root);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, a);
    //else maintain(2*root, l, mid);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, a);
    //else maintain(2*root+1, mid+1, r);
  }
  st[root].x = st[2*root].x + st[2*root+1].x;
  st[root].y = st[2*root].y + st[2*root+1].y;
}

int main(){
  int n, c;
  while(scanf("%d%d", &n, &c) != EOF){
    init();
    int x, s, a;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &x);
      p[i].y = p[i-1].y + x;
    }
    build(1, 1, n);
    for(int i = 0; i < c;i ++){
      scanf("%d%d", &s, &a);
      double temp = query(1, 1, n, s-1) + 180 + a - query(1, 1, n, s);
      modify(1, 1, n, s, n, temp);
      printf("%.2f %.2f\n", st[1].x, st[1].y);
    }
  }
  return 0;
}
