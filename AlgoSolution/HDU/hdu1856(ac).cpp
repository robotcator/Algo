// 328MS	2180K
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200000+10;
struct node{
  int x, y;
};
node data[maxn];
// 原来数据中的元素
int num[maxn];
// 对元素进行离散化
int Set[maxn];
int Rank[maxn];

int maxx(int a, int b) { return a > b ? a : b; }

void Init(int n){
  for(int i = 0; i <= n; i ++){
    Set[i] = i;
    Rank[i] = 1;
  }
}

int Find(int x){
  if(x != Set[x]){
    int fa = Set[x];
    Set[x] = Find(Set[x]);
   // Rank[x] = Rank[x]+Rank[fa];
  }
  return Set[x];
  // 要返回值啊！！！，真不知道前面怎么对的
}

void Unoin(int fa, int fb, int& d){
  Set[fa] = fb;
  Rank[fb] = (Rank[fa]+Rank[fb]);
  d = maxx(d, Rank[fb]);
}

int main()
{
  int n;
  int a, b;
  while(scanf("%d", &n) != EOF){
    int pos = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &data[i].x, &data[i].y);
      num[pos++] = data[i].x;
      num[pos++] = data[i].y;
    }
    sort(num, num+pos);
    int size = 1; // 离散化后元素的个数
    for(int i = 1; i < pos; i ++){
        // 剔除重复元素
      if(num[i] != num[i-1])
        num[size++] = num[i];
    }
    //for(int i = 0; i < size; i ++){
    //  cout << num[i] << endl;
    //}
    Init(size);
    // 对并查集初始化
    int d = 0;
    for(int i = 0; i < n; i ++){
      int index1 = lower_bound(num, num+size, data[i].x)-num+1;
      int index2 = lower_bound(num, num+size, data[i].y)-num+1;
     // cout << index1 << " " << index2 << endl;
      int f1 = Find(index1);
      int f2 = Find(index2);
      if(f1 != f2){
        Unoin(f1, f2, d);
      }
    }
    printf("%d\n", n == 0 ? 1 : d);

  }
  return 0;
}
