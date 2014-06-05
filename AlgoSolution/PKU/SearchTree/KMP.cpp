#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int getFail(char *p, int *f)
{
  f[0] = 0;
  f[1] = 0;
  // f数组从1开始，p数组从0开始
  int k = 0;
  for(int i = 1; i < (int)strlen(p); i ++){
    int j = f[i];
    // 上一次失配的地方
    while(j && p[i] != p[j]) j = p[j];
    f[i+1] = p[i] == p[j] ? j+1 : 0;
  }
}

int kmp(char *T, char *p, int *f)
{
  int n = strlen(T);
  int m = strlen(p);
  printf("%d %d\n", n, m);
  getFail(p, f);
  int j = 0;
  for(int i = 0; i < n; i ++){
    while(j && p[j] != T[i]) j = f[j];
    if(p[j] == T[i]) j ++;
    if(j == m) printf("%d\n", i-m+1);
  }
}
/*
abababa
abcddcabababa
*/
int main()
{
  //char p[15] = {'0','a','b','a','b','a','b','a','b','c','a'};
  char p[15];
  int pi[15];
  scanf("%s", p);
  char T[20];
  getchar();
  scanf("%c", T);
  getFail(p, pi);
  for(int i = 0; i <= 7; i ++)
    printf("%d ", pi[i]);
  kmp(T, p, pi);

/*
  int m = 10;

  pi[1] = 0;
  int k = 0;
  memset(pi, 0, sizeof(pi));

  for(int i = 2; i <= m; i ++){
    while(k > 0 && p[k+1] != p[i]){
     // printf("=%d", k);
      k = pi[k];
    }
    // printf("\n");
    // printf("~%d %d %c\n", k, pi[k], p[k]);
    if(p[k+1] == p[i]) k = k + 1;
    pi[i] = k;
  }


  for(int i = 1; i <= m; i ++)
    printf("%c ", p[i]);
  printf("\n");
  for(int i = 1; i <= m; i ++)
    printf("%d ", pi[i]);
*/
  return 0;
}
