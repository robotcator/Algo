#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int m[20][20];
int s[20][20];

int mcm(int *row, int *col, int n)
{
  for(int i = 0; i <= n; i ++){
    for(int j = 0; j <= n; j ++){
      m[i][j] = i == j ? 0 : inf;
      s[i][j] = i == j ? i : 0;
    }
  }
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      printf("%d ", s[i][j]);
    }
    printf("\n");
  }
  for(int l = 2; l <= n; l ++){
    for(int i = 1; i <= n-l+1; i ++){
      int j = i+l-1;
      for(int k = s[i][j-1]; k <= s[i+1][j]; k ++){
      //for(int k = s[i-1][j]; k < s[i][j+1]; k ++){
        int temp = m[i][k] + m[k+1][j] + row[i]*col[k]*col[j];
        printf("A\n");
        if(temp < m[i][j]){
          m[i][j] = temp;
          s[i][j] = k;
          printf("x\n");
        }
      }
    }
  }
 // s[i][j] <= s[i][j+1] <= s[i+1][j+1]
 // s[i][j] <= s[i+1][j] <= s[i+1][j+1]
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++)
      //if(m[i][j] != inf) {
          printf("%d ", m[i][j]);
      //}
    printf("\n");
  }
  return m[1][n];
}

/*
int mcm(int *row, int *col, int n)
{
  for(int i = 0; i <= n; i ++){
    for(int j = 0; j <= n; j ++)
      m[i][j] = i == j ? 0 : inf;
  }
  for(int l = 2; l <= n; l ++){
    for(int i = 1; i <= n-l+1; i ++){
      int j = i+l-1;
      for(int k = i; k <= j-1; k ++){
        int temp = m[i][k] + m[k+1][j] + row[i]*col[k]*col[j];
        if(temp < m[i][j]) m[i][j] = temp;
      }
    }
  }

  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++)
      if(m[i][j] != inf) printf("%d ", m[i][j]);
    printf("\n");
  }
  return m[1][n];
}
*/

int main()
{
  int col[20];
  int row[20];
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d %d", &row[i], &col[i]);
    }
    memset(m, 0, sizeof(m));
    int ans = mcm(row, col , n);
    /*
    for(int l = 2; l <= n; l ++){
      for(int i = 1; i <= n-l+1; i ++){
          int j = i+l-1;
          m[i][j] = inf;
          for(int k = i; k <= j-1; k ++){
            int temp = m[i][k] + m[k+1][j] + row[i-1]*col[k]*col[j];
          }
      }
    }
    */
  }
  return 0;
}

/*
6
30 35
35 15
15 5
5 10
10 20
20 25
*/
