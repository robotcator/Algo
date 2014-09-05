//Accepted 228K 0MS
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int m[25][25][25];

int w(int a, int b, int c)
{
  if(a <= 0 || b <= 0 || c <= 0)
    return 1;
  else if(a > 20 || b > 20 || c > 20)
    return w(20, 02, 20);
  else if(a < b && b < c){
    if(m[a][b][c-1] <= -1)
      m[a][b][c-1] = w(a, b, c-1);
    if(m[a][b-1][c-1] <= -1)
      m[a][b-1][c-1] = w(a, b-1, c-1);
    if(m[a][b-1][c] <= -1)
      m[a][b-1][c] = w(a, b-1, c);
    return m[a][b][c-1] + m[a][b-1][c-1] - m[a][b-1][c];
  }
  else {
    if(m[a-1][b][c] <= -1)
      m[a-1][b][c] = w(a-1, b, c);
    if(m[a-1][b-1][c] <= -1)
      m[a-1][b-1][c] = w(a-1, b-1, c);
    if(m[a-1][b][c-1] <= -1)
      m[a-1][b][c-1] = w(a-1, b, c-1);
    if(m[a-1][b-1][c-1] <= -1)
      m[a-1][b-1][c-1] = w(a-1, b-1, c-1);
    return  m[a-1][b][c] + m[a-1][b-1][c] + m[a-1][b][c-1] - m[a-1][b-1][c-1];
  }
}

int main()
{
  int a, b, c;
  // 加上一个备忘数组，如果已经算过则直接使用，如果没有算过，则递归。以空间换取时间
  memset(m, -1, sizeof(m));
  for(int i = 0; i < 25; i ++)
      for(int  j = 0; j < 25; j ++)
        for(int k  = 0; k < 25; k ++)
          if(i == 0 || j == 0 || k == 0) m[i][j][k] = 1;
  while(scanf("%d%d%d", &a, &b, &c) != EOF){
    if(a == -1 && b == -1 && c == -1) break;
    int ans = w(a, b, c);
    printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
  }
  return 0;
}
