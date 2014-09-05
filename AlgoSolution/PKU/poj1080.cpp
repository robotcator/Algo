#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[105][105];
int path[105][105];

int table(char x, char y)
{
  switch(x) {
    case 'A': {
      switch(y){
        case 'A' : return 5;
        case 'C' : return -1;
        case 'G' : return -2;
        case 'T' : return -1;
        case '-' : return -3;
      }
    }
    case 'C': {
      switch(y){
        case 'A' : return -1;
        case 'C' : return 5;
        case 'G' : return -3;
        case 'T' : return -2;
        case '-' : return -4;
      }
    }
    case 'G': {
      switch(y){
        case 'A' : return -2;
        case 'C' : return -3;
        case 'G' : return 5;
        case 'T' : return -2;
        case '-' : return -2;
      }
    }
    case 'T': {
      switch(y){
        case 'A' : return -1;
        case 'C' : return -2;
        case 'G' : return -2;
        case 'T' : return 5;
        case '-' : return -1;
      }
    }
    case '-': {
      switch(y){
        case 'A' : return -3;
        case 'C' : return -4;
        case 'G' : return -2;
        case 'T' : return -1;
        case '-' : return 0;
      }
    }
  }
}

int maxn(int x, int y, int z)
{
  int temp = x > y ? x : y;
  return z > temp ? z : temp;
}

int LCS(char *x, char *y)
{
  int len1 = strlen(x);
  int len2 = strlen(y);
  dp[0][0] = 0;
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= len1; i ++)
    dp[i][0] = dp[i-1][0] + table(x[i-1], '-');
  for(int i = 1; i <= len2; i ++)
    dp[0][i] = dp[0][i-1] + table('-', y[i-1]);
  for(int i = 1; i <= len1; i ++){
    for(int j = 1; j <= len2; j ++){
      dp[i][j] = maxn(dp[i-1][j-1]+table(x[i-1], y[j-1]),
                      dp[i-1][j]+table('-', y[j-1]),
                      dp[i][j-1]+table(x[i-1], '-'));
    }
  }
  // 想想状态转移方程为什么这样子
  for(int i = 0; i <= len1; i ++){
    for(int j = 0; j <= len2; j ++)
      printf("%d ", dp[i][j]);
    printf("\n");
  }
  return dp[len1][len2];
}

int main()
{
  int t;
  int num1, num2;
  char data1[105];
  char data2[105];
  scanf("%d", &t);
  while(t --){
    scanf("%d %s", &num1, data1);
    scanf("%d %s", &num2, data2);
    printf("%s %s\n", data1, data2);
    int ans = LCS(data1, data2);
    printf("%d\n", ans);
  }
  return 0;
}
