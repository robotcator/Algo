/*
    ID: problem6
    PROG : find the safest road
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000+5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
double graph[maxn][maxn];
double dp[maxn][maxn];

void floyd(int n){
  for(int k = 1; k <= n; k ++){
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        if(dp[i][j] < dp[i][k]*dp[k][j])
          // 一直是用dp数组，即在图上做
          dp[i][j] = dp[i][k]*dp[k][j];
      }
    }
  }
}
/*
tle
*/
int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        scanf("%lf", &graph[i][j]);
        dp[i][j] = graph[i][j];
      }
    }
    int q, x, y;
    scanf("%d", &q);
    floyd(n);
    for(int i = 0; i < q; i ++){
      scanf("%d%d", &x, &y);
      if(dp[x][y] == 0) printf("What a pity!\n");
      else printf("%.3f\n", dp[x][y]);
    }
  }
  return 0;
}
