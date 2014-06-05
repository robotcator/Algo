#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int dp[105][105];
const int inf = 50000;
/*
int LIS(int data[][105], int f, int v)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < v; i ++)
      dp[0][i] = data[0][i];
    for(int i = 1; i < f; i ++)
      dp[i][0] = -inf;

    for(int i = 1; i < f; i ++){
      for(int j = 0; j < v; j ++){
        if(j >= i){
          for(int k = 0; k <= j; k ++)
            if(dp[i][j] < dp[i-1][k] + data[i][j])
              dp[i][j] = dp[i-1][k] + data[i][j];
        }
      }
    }

    printf("\n");
    for(int i = 0; i < f; i ++){
        for(int j = 0; j < v; j ++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    return dp[f-1][v-1];
}
*/

int solve(int data[][105], int f, int v)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= v; i ++) dp[1][i] = data[1][i];
    // 列数必须依次增大
    for(int i = 2; i <= f; i ++){
      for(int j = i; j <= v; j ++){
        int temp = -inf;
        for(int k = i-1; k < j; k ++)
          if(dp[i-1][k] + data[i][j] > temp)
          temp = dp[i-1][k] + data[i][j];
        dp[i][j] = temp;
      }
    }
  //  for(int i = 1; i <= f; i ++){
  //    for(int j = 1; j <= v; j ++)
  //      printf("%d ", dp[i][j]);
  //    printf("\n");
  //  }
    return dp[f][v];
}

int main()
{
    int f, v;
    int data[105][105];
    while(scanf("%d %d", &f, &v) != EOF){
        for(int i = 1; i <= f; i ++){
            for(int j = 1; j <= v; j ++)
                scanf("%d", &data[i][j]);
        }
        int ans = solve(data, f, v);
        printf("%d\n", ans);
    }
    return 0;
}
