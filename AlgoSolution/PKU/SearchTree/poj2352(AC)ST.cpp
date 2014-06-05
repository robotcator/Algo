// Accepted 960K 172MS
#include <cstdio>
#include <cstring>

using namespace std;

const int magnitude = 32001;

typedef struct Node{
  int left, right;
  int sum;
  // С�ڵ���right�ĸ���
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
  //�޸�A[p],�����Ȳ���p��λ��
  if(l == r) {
    s[root].sum += v;
  }
  else {
    int mid = (l+r)/2;
    if(p <= mid) update(root*2, l, mid, p, v);
    else update(root*2+1, mid+1, r, p, v);
    s[root].sum = s[root*2].sum + s[root*2+1].sum;
    // ��Ҷ�ӽڵ�������������֮�͸���
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
  // levelΪi�ĸ������±�Ϊ������ֵΪ�����ĸ���
  while(scanf("%d", &n) != EOF){
    memset(cnt, 0, sizeof(cnt));
    build(1, 1, magnitude);
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &x, &y);
      //  ��x,y�Ĵ�0��ʼ����
      update(1, 1, magnitude, x+1, 1);
      int num = query(1, 1, magnitude, 1, x+1);
      // �˴���С�ڵ���x+1�ĸ���
      // printf("%d\n", num);
      cnt[num-1] ++;
      // ����Ϊnum����Ŀ,��ȥ�Լ�
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
  // ���䣬��������������ָ��
  int sum;
  // ����l, r����Сֵ
}segmentTree;

segmentTree s[2000];
int n;
// ����ĳ���
// ��д�����޸�

//Ҷ�������ǳ���Ϊ0������
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
  //��ѯ��Χ�ڵ�������Ϣ
  if(ql <= l && r <= qr){
      // Ҫ��ѯ�����佫��ǰ���串��
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
//����ȫ�ֱ����������п��ܵĵ�
void query(int root, int l, int r, int ql, int qr){
  //��ѯ��Χ�ڵ�������Ϣ
  if(ql <= l && r <= qr){
      // Ҫ��ѯ�����佫��ǰ���串��
    ans += s[root].sum;
    return ;
  }
  else {
    int mid = (l+r)/2;
    if(ql <= mid) query(root*2, l, mid, ql, qr);
    if(qr > mid) query(root*2+1, mid+1, r, ql, qr);
    //û��else�ж�
  }
}
*/
/*
void Traverse(int root, int l, int r, int n) {
  if(r-l >= 0 && root < 2*n){
    // ��������Ʊ�ţ������޵ݹ�
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
