//Accepted 256K 0MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int dp[105][105];
int path[105][105];
// 路径用0表示原地，1表示左上，2向左，3向上
int num1, num2;

int LCS(char x[][35], char y[][35], int num1, int num2)
{
  memset(dp, 0, sizeof(dp));
  memset(path, 0, sizeof(path));
  for(int i = 1; i <= num1; i ++){
    for(int j = 1; j <= num2; j ++){
      if(strcmp(x[i-1], y[j-1]) == 0){
        dp[i][j] = dp[i-1][j-1] + 1;
        path[i][j] = 1;
      }
      else{
        if(dp[i-1][j] > dp[i][j-1]) {
          dp[i][j] = dp[i-1][j];
          path[i][j] = 2;
        }
        else {
          dp[i][j] = dp[i][j-1];
          path[i][j] = 3;
        }
      }
    }
  }
  return dp[num1][num2];
}

void print_path(char x[][35], int n1, int n2)
{
  if(n1 == 0 || n2 == 0) return;
  else if(path[n1][n2] == 1){
    print_path(x,  n1-1, n2-1);
    // 递归输出，看是自顶向下还是自底向上，输出地方可以动手脚
    printf("%s", x[n1-1]);
    if(!(n1 == num1 && n2 == num2)) printf(" ");
  }
  else if(path[n1][n2] == 2)
    print_path(x, n1-1, n2);
  else print_path(x, n1, n2-1);
}

int main()
{
  char x[105][35];
  char y[105][35];
  char data[30];
  while(scanf("%s", data) != EOF){
    num1 = num2 = 0;
    strcpy(x[num1++], data);
    while(scanf("%s", data)){
      if(strcmp(data, "#") == 0) break;
      strcpy(x[num1++], data);
    }
    while(scanf("%s", data)){
      if(strcmp(data, "#") == 0) break;
      strcpy(y[num2++], data);
    }
    // for(int i = 0; i < num2; i ++)
    //  printf("~%d %s\n", i, y[i]);

    int ans = LCS(x, y, num1, num2);
    //printf("%d\n", ans);
    /*
    for(int i = 0; i <= num1; i ++){
      for(int j = 0; j <= num2; j ++)
        printf("%d ", path[i][j]);
      printf("\n");
    }
    */
    //printf("\n");
    print_path(x, num1, num2);
    printf("\n");

  }
  return 0;
}
