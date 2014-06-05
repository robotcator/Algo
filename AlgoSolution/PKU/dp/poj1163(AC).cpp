//Accepted 248K 16MS
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int maxn(int a, int b) { return a > b ?  a : b; }

int main()
{
  int n;
  int data[105][105];
  int dp[105][105];
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++)
      for(int j = 0; j <= i; j ++)
        scanf("%d", &data[i][j]);
    memset(dp, 0, sizeof(dp));

    for(int i = n-1; i >= 0; i --){
      // 阶段,从n-1开始，注意要加边界，或者n-2开始，第n-1行data赋给dp
      for(int j = 0; j <= i; j ++)
      // 每个状态
      dp[i][j] = maxn(dp[i+1][j], dp[i+1][j+1]) + data[i][j];
    }
    /*
    for(int i = 0; i < n; i ++){
      for(int j = 0; j <= i; j ++)
        printf("%d ", dp[i][j]);
        printf("\n");
    }
    */
     printf("%d\n", dp[0][0]);
  }
  return 0;
}
