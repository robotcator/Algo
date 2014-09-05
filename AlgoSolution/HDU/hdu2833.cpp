/*
    ID: problem6
    PROG : WuKong
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 300+5;
int graph[maxn][maxn];
int path[maxn][maxn];
int dist[maxn][maxn];
int num[maxn][maxn];
// graph 为图，path为路径矩阵，dist为最短路路径矩阵，num为定点数矩阵

void floyd(int n){
  memset(path, 0, sizeof(path));
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      dist[i][j] = graph[i][j];
      if(i != j && graph[i][j] < inf) path[i][j] = i;
      if(i == j || graph[i][j] >= inf) path[i][j] = -1;
    }
  }
  for(int k = 1; k <= n; k ++){
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = path[k][j];
          num[i][j] = num[i][k] + num[k][j];
        }else if(dist[i][j] == dist[i][k] + dist[k][j]
              && num[i][j] < num[i][k] + num[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = path[k][j];
          num[i][j] = num[i][k] + num[k][j];
        }
      }
    }
  }
}


int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
      if(n == 0 && m == 0) break;
      int a, b, c;
      memset(num, 0, sizeof(num));
      memset(graph, inf, sizeof(graph));
      for(int i = 0; i <= n; i ++) graph[i][i] = 0;
      for(int i = 0; i < m; i ++){
        scanf("%d%d%d", &a, &b, &c);
        if(c > graph[a][b]) continue;
        graph[a][b] = graph[b][a] = c;
        num[a][b] = num[b][a] = 1;
      }
      floyd(n);
      int A, B, C, D;
      scanf("%d%d%d%d", &A, &B, &C, &D);
      int ans = -1;
      /*
      for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
          printf("%d ", num[i][j]);
        }
        printf("\n");
      }
      */
      for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
          if(num[i][j] > ans &&
             (dist[A][B] == dist[A][i] + dist[i][j] + dist[j][B])
             && (dist[C][D] == dist[C][i] + dist[i][j] + dist[j][D]))
              ans = num[i][j];
        }
      }
      printf("%d\n", ans+1);
    }
    return 0;
}

/*
conclusion:
11193946	2014-07-26 10:01:45	Accepted
2833	796MS	1624K	2357 B	G++	robotcator
邻接矩阵不支持重边，所以单纯最短路还是要取最短的边
path[i][j] 有两种选择，通过k+1到达，和不通过k+1到
*/
