//Runtime Error   C++
//n ��
// Memory Limit Exceeded  һ�㲻�ܿ�5000*5000������
// Accepted 4128K 47MS
// gets���÷�����
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int dp[1005][1005];
int maxn(int m , int n) { return m > n ? m : n; }

int LCS(char *a, char *b)
{
  int len1 = strlen(a);
  int len2 = strlen(b);
  memset(dp, 0, sizeof(dp));
  // ���ӱ߽�
  for(int i = 1; i <= strlen(a); i ++){
    for(int j = 1; j <= strlen(b); j ++){
      if(b[j-1] == a[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = maxn(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[len1][len2];
}
/*
void init(char *data, char *x, char *y)
{
  int i, j, k;
  for(i = 0; data[i] != ' '; i ++)
    x[i] = data[i];
  x[i++] =  '\0';
  for(j = i-1; data[j] == ' '; j ++) ;
  for(i = j, k = 0; data[i] != '\0'; i ++, k ++)
    y[k] = data[i];
  y[k++] = '\0';
}
*/
int main()
{
  char x[1000], y[1000];
  while(scanf("%s %s", x, y) != EOF){
   // printf("%s %s", x, y);
    int ans = LCS(x, y);
    printf("%d\n", ans);
  }
  /*
  char data[100000];
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(data, 0, sizeof(data));
  while(gets(data)){
    printf("%s", data);
    init(data, x, y);
    //���������ַ�
    printf("%s %s\n", x, y);
    //int ans = LCS(x, y);
    //printf("%d\n", ans);
  }
  */
  return 0;
}
