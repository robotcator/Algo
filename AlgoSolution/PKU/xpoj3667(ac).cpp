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

// 分解操作后同时更新左右子树
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
  int len = (r-l+1); // 区间长度
  lsum[root] = lsum[lc];
  if(lsum[lc] == len-len/2) lsum[root] += lsum[rc];
  // 如果左端连续区间超过中指，即左子树全为相同区间
  rsum[root] = rsum[rc];
  if(rsum[rc] == len/2) rsum[root] += rsum[lc];
  //是否超过mid的连续区间
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
    // 不要修改叶子节点，只是合并根节点
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
1：懒标记一分解后就要更新叶子节点，
2：还有就是维护根节点不要，而不是叶子节点，
  所以不是所有递归结束
3：单纯的不要用更新父节点的就维护一下就好,改成这种风格
  更好理解代码
*/
