/*
    ID: problem6
    PROG : ride
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];

void floyd(int n){
  for(int k = 1; k <= n; k ++){
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        if(graph[i][j] > graph[i][k]+graph[k][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }
}

int main(){
  int n, t;
  int flag = 1;
  while(scanf("%d", &n) != EOF){
    memset(graph, inf, sizeof(graph));
    for(int i = 0; i <= 20; i ++) graph[i][i] = 0;
    for(int i = 0; i < n; i ++) {
      scanf("%d", &t);
      graph[1][t] = graph[t][1] = 1;
    }
    for(int i = 2; i < 20; i ++){
      scanf("%d", &n);
      for(int j = 0; j < n; j ++){
        scanf("%d", &t);
        graph[i][t] = graph[t][i] = 1;
      }
    }
    floyd(20);
    scanf("%d", &t);
    printf("Test Set #%d\n", flag++);
    int a, b;
    for(int i = 0; i < t; i ++){
      scanf("%d%d", &a, &b);
      printf("%2d to %2d: %d\n", a, b, graph[a][b]);
    }
    printf("\n");
  }
  return 0;
}
