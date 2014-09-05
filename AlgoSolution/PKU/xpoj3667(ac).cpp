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
// sum Ϊ��������������������
//lsumΪ��˵��������������䣬rsumΪ�Ҷ˵�������������������
// cover��0��ʾ��ռ�ã�1��ʾռ��
void build(int root, int l, int r){
  sum[root] = lsum[root] = rsum[root] = r-l+1;
  if(l < r){
    int mid = (l+r)/2;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
  }
}

// �ֽ������ͬʱ������������
void pushdown(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  int len = r-l+1;
  if(cover[root] > -1){
    cover[lc] = cover[rc] = cover[root];
    lsum[lc] = rsum[lc] = sum[lc] = cover[root] ? 0 : len-len/2;
    lsum[rc] = rsum[rc] = sum[rc] = cover[root] ? 0 : len/2;
    cover[root] = -1;
  }
}

void pushup(int root, int l, int r){
  int lc = 2*root, rc = 2*root+1;
  int len = (r-l+1); // ���䳤��
  lsum[root] = lsum[lc];
  if(lsum[lc] == len-len/2) lsum[root] += lsum[rc];
  // �������������䳬����ָ����������ȫΪ��ͬ����
  rsum[root] = rsum[rc];
  if(rsum[rc] == len/2) rsum[root] += rsum[lc];
  //�Ƿ񳬹�mid����������
  sum[root] = max(rsum[lc]+lsum[rc], max(sum[lc], sum[rc]));
}

void modify(int root, int l, int r, int x, int y, int s){
  if(x <= l && r <= y){
    if(s == 0)
      sum[root] = lsum[root] = rsum[root] = r-l+1;
    else
      sum[root] = lsum[root] = rsum[root] = 0;
    cover[root] = s;
  }else{
    pushdown(root, l, r);
    int mid = (l+r)/2;
    if(x <= mid) modify(2*root, l, mid, x, y, s);
    if(y > mid) modify(2*root+1, mid+1, r, x, y, s);
    pushup(root, l, r);
    // ��Ҫ�޸�Ҷ�ӽڵ㣬ֻ�Ǻϲ����ڵ�
  }
}

int query(int root, int l, int r, int z){
  int lc = 2*root, rc = 2*root+1 , mid = (l+r)/2;
  if(l == r){
    return l;
  }else{
    pushdown(root, l, r);
    if(sum[lc] >= z) return query(2*root, l, mid, z);
    else if(rsum[lc] + lsum[rc] >= z) {
      return mid-rsum[lc]+1;
    }else return query(2*root+1, mid+1, r, z);
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
          //print(1, 1, n);
        }else{
          printf("0\n");
        }
      }else{
        scanf("%d%d", &b, &c);
        modify(1, 1, n, b, b+c-1, 0);
      //  print(1, 1, n);
      }
    }
  }
  return 0;
}
/*
conclusion:
13224437	robotcator	3667	Accepted
2188K	657MS	C++	2955B	2014-08-01 16:23:13
1�������һ�ֽ���Ҫ����Ҷ�ӽڵ㣬
2�����о���ά�����ڵ㲻Ҫ��������Ҷ�ӽڵ㣬
  ���Բ������еݹ����
3�������Ĳ�Ҫ�ø��¸��ڵ�ľ�ά��һ�¾ͺ�,�ĳ����ַ��
  ����������
*/
