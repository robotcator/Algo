#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int dp[105][105];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int isIn(int x, int y, int r, int c)
{
  if(0 <= x && x < r && 0 <= y && y < r) return 1;
  else return 0;
}

int solve(int data[][105], int r, int c)
{
  for(int i = 0; i < r; i ++)
    for(int j = 0; j < c; j ++)
      dp[i][j] = 1;
  for(int i = 0; i < r; i ++){
    for(int j = 0; j < c; j ++){
      for(int k = 0; k < 4; k ++){
          if(isIn(i+dx[k], j+dy[k]) && data[i+dx[k][j+dy[k] < data[i][j])

      }
    }
  }
}

int main()
{
  int r, c;
  int data[105][105];
  while(scanf("%d%d", &r, &c) != EOF){
    for(int i = 0; i < r; i ++)
      for(int j = 0; j < c; j ++)
        scanf("%d", &data[i][j]);
    int ans = solve(data, r, c);
  }
  return 0;
}
