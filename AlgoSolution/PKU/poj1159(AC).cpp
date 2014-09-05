// Accepted 220K 1360MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int maxn(int a, int b) { return a > b ? a : b; }

/*
//int dp[5005][5005];
//int path[5005][5005];

int LCS(char *data, char *vdata)
{
  int len1 = strlen(data);
  int len2 = strlen(vdata);
  memset(dp, 0, sizeof(dp));
//  memset(path, 0, sizeof(path));
  for(int i = 1; i <= len1; i ++){
    for(int j = 1; j <= len2; j ++){
      if(data[i-1] == vdata[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
//          path[i][j] = 1;
      }
      else {
          dp[i][j] = maxn(dp[i-1][j], dp[i][j-1]);
  //        path[i][j] = dp[i-1][j] > dp[i][j-1] ? 2 : 3;
      }
    }
  }
  return dp[len1][len2];
}

void print_path(char *data, int len1, int len2)
{
  if(len1 == 0 || len2 == 0) return ;
  else if(path[len1][len2] == 1){
      print_path(data, len1-1, len2-1);
      printf("%c\n", data[len1-1]);
    }
  else if(path[len1][len2] == 2)
    print_path(data, len1-1, len2);
  else print_path(data, len1, len2-1);
}
*/

int dp[2][5005];

int LCS(char *data, char *vdata)
{
  int len1 = strlen(data);
  int len2 = strlen(vdata);
  int k1 = 0;
  int k2 = 1;
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= len1; i ++){
    for(int k = 0; k <= len2; k ++) dp[k2][k] = 0;
    for(int j = 1; j <= len2; j ++){
      dp[k2][j] = maxn(dp[k1][j], dp[k2][j-1]);
      if(data[i-1] == vdata[j-1])
      dp[k2][j] = maxn(dp[k2][j], dp[k1][j-1]+1);
    }
    int temp = k1;
    k1 = k2;
    k2 = temp;
  }
  return dp[k1][len2];
  // why?
}

void Reverse(char *data, char *vdata)
{
  for(int i = 0; i < (int)strlen(data); i ++){
    vdata[i] = data[strlen(data)-1-i];
  }
  vdata[strlen(data)] = '\0';
}

int main()
{
  int n;
  char data[5005];
  char vdata[5005];
  while(scanf("%d", &n) != EOF){
    scanf("%s", data);
    Reverse(data, vdata);
    //printf("%s\n%s\n", data, vdata);
    int ans = LCS(data, vdata);
    printf("%d\n", strlen(data) - ans);
   // print_path(data, strlen(data), strlen(vdata));
  }
  return 0;
}

