//Time Limit Exceeded
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[105];

/*
int LSM(int data[][105], int n)
{
  int Array[105];
  memset(Array, 0, sizeof(Array));
  memset(dp, 0, sizeof(dp));
  int sum[105][105];
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      if(i == 0) sum[i+1][j] = data[i][j];
      else sum[i+1][j] = sum[i][j] + data[i][j];
    }
  }

  for(int i = 0; i <= n; i ++){
      for(int j = 0; j < n; j ++)
        printf("%d ", sum[i][j]);
      printf("\n");
  }

  int maxn = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = i; j <= n; j ++){
      for(int k = 0; k < n; k ++){
        Array[k] = sum[j][k] - sum[i-1][k];
        if(Array[k] > 0 && k > 0) dp[k] = dp[k-1] + Array[k];
        else dp[k] = Array[k];
      }
      for(int l = 0; l < n; l ++)
        if(dp[l] > maxn) maxn = dp[l];
    }
  }
  return maxn;
}
*/

int LSM(int data[][105]; int n)
{

}

int main()
{
  int n;
  int data[105][105];
  while(scanf("%d", &n) != 0){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++)
          scanf("%d", &data[i][j]);
    }
    /*
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++)
        printf("%d ", data[i][j]);
      printf("\n");
    }
    */

    int ans = LSM(data, n);
    printf("%d\n", ans);
  }
  return 0;
}
