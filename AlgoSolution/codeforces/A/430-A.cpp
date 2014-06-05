/*
  如何映射要注意不要溢出，还有对于题目要尝试自己的判断
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int p[maxn];
int mp[maxn];
int vis[maxn];

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    memset(vis, 0, sizeof(vis));
    memset(mp, -1, sizeof(vis));
    for(int i = 0; i < n; i ++){
      scanf("%d", &p[i]);
      mp[p[i]] = 1;
    }
    int a, b;
    for(int i = 0; i < m; i ++){
      scanf("%d%d", &a, &b);
    }
    int flag = 1;
    for(int i = 0; i <= 100; i ++){
      if(mp[i] == 1){
        vis[i] = flag;
        flag = -flag;
      }
    }
    for(int i = 0; i < n; i ++){
      if(vis[p[i]] == 1) printf("1");
      else if(vis[p[i]] == -1) printf("0");
      if(i != n-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
