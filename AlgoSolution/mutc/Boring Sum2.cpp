#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100000+10;
const int inf = 0x3f3f3f3f;
int a[maxn];
int index[maxn];
int b[maxn], c[maxn];

vector<int> G[maxn];
// 存每个数的约数

int main(){
  int n;
  for(int i = 1; i < maxn; i ++){
    for(int j = 1; j < maxn/i; j ++){
      G[i*j].push_back(i);
    }
  }
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &a[i]);
    }
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(index, -1, sizeof(index));
    for(int i = 1; i <= n; i ++){
      if(index[a[i]] == -1) b[i] = a[i];
      else b[i] = index[a[i]];
      for(int j = 0; j < G[a[i]].size(); j ++){
        int temp = G[a[i]][j];
        index[temp] = a[i];
      }
    }
    memset(index, -1, sizeof(index));
    for(int i = n; i >= 1; i --){
      if(index[a[i]] == -1) c[i] = a[i];
      else c[i] = index[a[i]];
      for(int j = 0; j < G[a[i]].size(); j ++){
        int temp = G[a[i]][j];
        index[temp] = a[i];
      }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i ++){
      ans += (long long)b[i]*(long long)c[i];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
