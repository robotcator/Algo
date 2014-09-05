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
  double sx, sy;
  double ex, ey;
  // 线段的其实和结束位置
};

const double PI = 3.141592653589793238462;
const double eps = 1e-8;
int p[10010];
// 2^14 与 10000数量级相当
const int maxn = (1LL) << 15;
point st[maxn];
int ang[maxn];
// 该线段与y轴正半轴角度
int pre[maxn];

void init(int n){
  memset(p, 0, sizeof(p));
  memset(ang, 0, sizeof(ang));
}

void build(int root, int l, int r){
  int mid = (l + r) >> 1, ls = root << 1, rs = (root << 1) | 1;
  ang[root] = 0;
  st[root].sx = 0, st[root].sy = p[l-1];
  st[root].ex = 0, st[root].ey = p[r];
  if(l < r){
    build(ls, l, mid);
    build(rs, mid+1, r);
  }
}

void Rotate(int root, int a){
  double x = st[root].sx;
  double y = st[root].sy;
  double x1 = st[root].ex - x;
  double y1 = st[root].ey - y;
  double deg = a/180.0*PI;
  st[root].ex = x + x1*cos(deg) - y1*sin(deg);
  st[root].ey = y + y1*cos(deg) + x1*sin(deg);

  //cout << st[root] << endl;
}

void update(int root){
 // if(ang[root] > 0){
    int lc = 2*root;
    int rc = 2*root+1;
    // 更改右子树
    ang[lc] = (ang[lc]+ang[root])%360;
    st[lc].ex = st[root].sx + st[lc].ex-st[lc].sx;
    st[lc].ey = st[root].sy + st[lc].ey-st[lc].sy;
    st[lc].sx = st[root].sx;
    st[lc].sy = st[root].sy;
    Rotate(lc, ang[root]);
    // 更改左子树
    ang[rc] = (ang[rc]+ang[root])%360;
    st[rc].ex = st[lc].ex + st[rc].ex-st[rc].sx;
    st[rc].ey = st[lc].ey + st[rc].ey-st[rc].sy;
    st[rc].sx = st[lc].ex;
    st[rc].sy = st[lc].ey;
    Rotate(rc, ang[root]);
    ang[root] = 0;
 // }
}

void modify(int root, int l, int r, int x, int y, int a){
  if(x <= l && r <= y){
    ang[root] += a;
    Rotate(root, a);
  }else{
    update(root);
    int mid = (l+r) >> 1;
    int lc = 2*root, rc = 2*root+1;
    if(x <= mid) modify(lc, l, mid, x, y, a);
    // 因为左子树的节点更改，所以右节点也必须跟着更改
    st[rc].ex = st[lc].ex + (st[rc].ex-st[rc].sx);
    st[rc].ey = st[lc].ey + (st[rc].ey-st[rc].sy);
    st[rc].sx = st[lc].ex;
    st[rc].sy = st[lc].ey;
    if(y > mid) modify(rc, mid+1, r, x, y, a);
    st[root].ex = st[rc].ex;
    st[root].ey = st[rc].ey;
  }
}


int main(){
  int n, c;
  bool flag = false;
  while(scanf("%d%d", &n, &c) != EOF){
    if(flag) printf("\n");
    flag = true;
    //init(n);
    int x, s, a;
    p[0] = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &x);
      p[i] = p[i-1] + x;
    }
    build(1, 1, n);
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i < c; i ++){
      scanf("%d%d", &s, &a);
      modify(1, 1, n, s+1, n, pre[s]-a);
      pre[s] = a;
      //for(int i = 1; i <= 7; i ++){
      //  printf("%lf %lf %lf %lf\n", st[i].sx, st[i].sy, st[i].ex, st[i].ey);
      //}
      printf("%.2f %.2f\n", st[1].ex+eps, st[1].ey+eps);
    }
  }
  return 0;
}
