#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int dp[120000];

int maxn(int x, int y) { return x > y ? x : y; }

int multiPack(int *a, int n, int vol)
{
  memset(dp, 0, sizeof(dp));

  for(int i = 1; i <= n; i ++){

    for(int j = vol; j >= i; j --){
      // ±³°üµÄÈÝÁ¿
      if(a[i] > 0)
      for(int k = 0; k <= a[i]; k ++)
        if(k*i >= j)
        dp[j] = maxn(dp[j], dp[j-k*i]+k*i);
    }
    for(int i = 1; i <= vol; i ++)
      printf("%d ", dp[i]);
    printf("\n");
  }
  for(int i = 1; i <= n; i ++)
    printf("%d ", dp[i]);
  printf("\n");
  return dp[vol] == vol ? 1 : 0;
}

int main()
{
  int a[10];
  int flag = 1;
  while(scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3],
               &a[4], &a[5], &a[6]) != EOF){
    if(a[1] == 0 && a[2] == 0 && a[3] == 0 &&
       a[4] == 0 && a[5] == 0 && a[6] == 0) break;
    int vol = 0;
    for(int i = 1; i <= 6; i ++)
      vol += a[i] * i;
    // printf("%d\n", vol);
    printf("Collection #%d:\n", flag ++);
    if(vol % 2 != 0) printf("Can't be divided.\n");
    else {
      vol /= 2;
      int ans = multiPack(a, 6, vol);
      if(ans == 0)  printf("Can't be divided.\n");
      else printf("Can be divided.\n");
    }
  }
  return 0;
}
