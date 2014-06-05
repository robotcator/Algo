// Accepted 960K 172MS
#include <cstdio>
#include <cstring>

using namespace std;

const int magnitude = 32001;

typedef struct Node{
  int left, right;
  int sum;
  // 小于等于right的个数
}segment_tree;

// segment_tree s[97000];
segment_tree s[70000];

void build(int root, int l, int r) {
  s[root].sum = 0;
  s[root].left = l;
  s[root].right = r;
  if(r-l > 0){
    int mid = (l+r)/2;
    build(root*2, l, mid);
    build(root*2+1, mid+1, r);
  }
}

void update(int root, int l, int r, int p, int v) {
  //修改A[p],所以先查找p的位置
  if(l == r) {
    s[root].sum += v;
  }
  else {
    int mid = (l+r)/2;
    if(p <= mid) update(root*2, l, mid, p, v);
    else update(root*2+1, mid+1, r, p, v);
    s[root].sum = s[root*2].sum + s[root*2+1].sum;
    // 非叶子节点则是左右子树之和更改
  }
}

int query(int root, int l, int r, int ql, int qr) {
  if(ql <= l && r <= qr) return s[root].sum;
  else {
    int mid = (l+r)/2;
    int Lans = 0, Rans = 0;
    if(ql <= mid) Lans = query(root*2, l, mid, ql, qr);
    if(qr > mid)  Rans = query(root*2+1, mid+1, r, ql, qr);
    return Lans + Rans;
  }
}


int main()
{
  int n;
  int x, y;
  int cnt[15005];
  freopen("in.txt", "r", stdin);
  // level为i的个数。下标为层数，值为层数的个数
  while(scanf("%d", &n) != EOF){
    memset(cnt, 0, sizeof(cnt));
    build(1, 1, magnitude);
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &x, &y);
      //  由x,y的从0开始计数
      update(1, 1, magnitude, x+1, 1);
      int num = query(1, 1, magnitude, 1, x+1);
      // 此处是小于等于x+1的个数
      // printf("%d\n", num);
      cnt[num-1] ++;
      // 层数为num的数目,除去自己
    }
    for(int i = 0; i < n; i ++)
      //printf("%d %d\n", i, cnt[i]);
     printf("%d\n", cnt[i]);
  }
  return 0;
}
/*
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct Node{
  int left, right;
  // 区间，并不是左右子树指针
  int sum;
  // 区间l, r的最小值
}segmentTree;

segmentTree s[2000];
int n;
// 区间的长度
// 先写单点修改

//叶子区间是长度为0的区间
void build(int root, int st, int ed) {
  s[root].sum = 0;
  s[root].left = st;
  s[root].right = ed;
  if(ed-st > 0){
    int mid = (st+ed)/2;
   // printf("%d\n", mid);
    build(root*2, st, mid);
    build(root*2+1, mid+1, ed);
  }
}

void update(int root, int l, int r, int p, int v) {
  if(l == r) {
    s[root].sum += v;
  }
  else {
    int mid = (l+r)/2;
    if(p <= mid) update(root*2, l, mid, p, v);
    else update(root*2+1, mid+1, r, p, v);
    s[root].sum = s[root*2].sum + s[root*2+1].sum;
  }
}


int query(int root, int l, int r, int ql, int qr){
  //查询范围内的区间信息
  if(ql <= l && r <= qr){
      // 要查询的区间将当前区间覆盖
    return  s[root].sum;
  }
  else {
    int mid = (l+r)/2;
    int Lans = 0, Rans = 0;
    if(ql <= mid)
       Lans = query(root*2, l, mid, ql, qr);
    if(qr > mid)
       Rans = query(root*2+1, mid+1, r, ql, qr);
    return Lans+Rans;
  }
}
/*
int ans = 0;
//利用全局变量变量所有可能的点
void query(int root, int l, int r, int ql, int qr){
  //查询范围内的区间信息
  if(ql <= l && r <= qr){
      // 要查询的区间将当前区间覆盖
    ans += s[root].sum;
    return ;
  }
  else {
    int mid = (l+r)/2;
    if(ql <= mid) query(root*2, l, mid, ql, qr);
    if(qr > mid) query(root*2+1, mid+1, r, ql, qr);
    //没有else判断
  }
}
*/
/*
void Traverse(int root, int l, int r, int n) {
  if(r-l >= 0 && root < 2*n){
    // 如果不限制编号，将无限递归
    printf("%d %d %d\n", s[root].left, s[root].right, s[root].sum);
    int mid = (l+r)/2;
    Traverse(root*2, l, mid, n);
    Traverse(root*2+1, mid+1, r, n);
  }
}

int main()
{
  int a[100];
  scanf("%d", &n);
  build(1, 1, n);
  // for(int i = 1; i <= 15; i ++)
  //  printf("%d %d\n", s[i].left, s[i].right);
  Traverse(1, 1, n, n);
  for(int i = 1; i <= n; i ++){
    scanf("%d", &a[i]);
    update(1, 1, n, i, a[i]);
  }
  Traverse(1, 1, n, n);
  int l, r;
  while(scanf("%d%d", &l, &r) != EOF){
    int res = query(1, 1, n, l, r);
    printf("%d\n", res);
  }

  return 0;
}
*/
