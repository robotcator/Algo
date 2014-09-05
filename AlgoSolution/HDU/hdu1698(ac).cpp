/*
    ID: problem6
    PROG : Just a Hook
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1LL << 18;
// 2^17 = 131072 跟 100000同数量级
int st[maxn];
int setv[maxn];

int ans ;
void build(int root, int l, int r){
  if(l == r){
    st[root] = 1;
  }else{
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
    st[root] = st[2*root] + st[2*root+1];
  }
}

void init(int n){
  memset(st, 0, sizeof(st));
  memset(setv, 0, sizeof(setv));
  build(1, 1, n);
}
// 分解操作
void pushdown(int root){
  int l = 2*root, r = 2*root+1;
  if(setv[root] > 0){
    setv[l] = setv[r] = setv[root];
    setv[root] = 0;
  }
}
// 维护因为pushdown之后，，不用进行新修改的节点
void maintain(int root, int x, int y){
  int lc = 2*root, rc = 2*root+1;
  if(y > x){
    // 合并操作时，即对左右子树
    st[root] = st[lc] + st[rc];
  }
  if(setv[root] > 0) st[root] = setv[root]*(y-x+1);
  // 考虑标记节点
}


// 将x - y 的值修改为 z
void modify(int root, int l, int r, int x, int y, int z){
  if(x <= l && r <= y){
    setv[root] = z;
  }else{
    pushdown(root);
    int mid = (l+r)/2;
    // 分治减少低估次数
    if(x <= mid) modify(2*root, l, mid, x, y, z);
    else maintain(2*root, l, mid);
    // 不递归当前节点的子树节点
    if(y > mid) modify(2*root+1, mid+1, r, x, y, z);
    else maintain(2*root+1, mid+1, r);
  }
  maintain(root, l, r);
  // 由于pushdown操作，将setv[root]更改
}

void query(int root, int l, int r, int x, int y){
  if(setv[root] > 0){
    ans += (min(r, y)-max(l, x)+1)*setv[root];
  }else if(x <= l && r <= y){
    ans += st[root];
  }else{
    int mid = (l+r)/2;
    if(x <= mid) query(2*root, l, mid, x, y);
    if(y > mid) query(2*root+1, mid+1, r, x, y);
  }
}

int main(){
  int n, t, q;
  scanf("%d", &t);
  for(int test = 1; test <= t; test ++){
    scanf("%d", &n);
    init(n);
    scanf("%d", &q);
    int x, y, z;
    for(int i = 1; i <= q; i ++){
      scanf("%d%d%d", &x, &y, &z);
      modify(1, 1, n, x, y, z);
    }
    ans = 0;
    query(1, 1, n, 1, n);
    printf("Case %d: The total value of the hook is %d.\n", test, ans);
  }
  return 0;
}
/*
conclusion:
11229675	2014-07-29 10:44:49	Accepted
1698	1015MS	2280K	2320 B	C++	robotcato
1: 勤想多思考，然后争取越快越准
*/
