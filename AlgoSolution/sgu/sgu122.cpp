#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1000+10;
int graph[maxn][maxn];
int n, x, y;
int vis[maxn];

void Init(){
  memset(graph, 0, sizeof(graph));
  memset(vis, 0, sizeof(vis));
}

void dfs(int u){
  vis[u] = 1;
  printf("%d\n", u);
  for(int v = 1; v <= n; v ++){
    if(graph[u][v] > 0 && vis[v] == 0){
      dfs(v);
    }
  }
}

int main(){
  while(scanf("%d", &n) != EOF){
      Init();
      for(int i = 0; i < n; i ++){
        scanf("%d%d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
      }
      for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
          printf("%d ", graph[i][j]);
        }
        printf("\n");
      }
      dfs(1);
  }
  return 0;
}
