/*
    ID: problem6
    PROG : Girls and Boys
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int n;
int graph[maxn][maxn];
int Mx[maxn], My[maxn];
int vis[maxn];

bool dfs(int u){
  for(int v = 0; v < n; v ++){
    if(graph[u][v] && !vis[v]){
      vis[v] = 1;
      if(My[v] == -1 || dfs(My[v])){
        Mx[u] = v; My[v] = u;
        return true;
      }
    }
  }
  return false;
}

int MaxMatch(){
  memset(Mx, -1, sizeof(Mx));
  memset(My, -1, sizeof(My));
  int ans = 0;
  for(int u = 0; u < n; u ++){
    if(Mx[u] == -1){
      memset(vis, 0, sizeof(vis));
      if(dfs(u)) ans ++;
    }
  }
  return ans;
}

int main(){
  char data[10*maxn];
  while(scanf("%d", &n) != EOF){
    memset(graph, 0, sizeof(graph));
    int a, num, b;
    for(int i = 0; i < n; i ++){
      scanf("%d: (%d)", &a, &num);
      for(int j = 0; j < num; j ++){
        scanf("%d", &b);
        graph[a][b] = 1;
      }
    }
    // 可能输入中有多个空格
    int ans = MaxMatch();
    printf("%d\n", n-ans/2);
  }
  return 0;
}
