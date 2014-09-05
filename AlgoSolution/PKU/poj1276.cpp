#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[100005];

int maxn(int a, int b){ return a > b ? a : b; }

int main()
{
  int n, cash;
  int bill[15], num[15];
  while(scanf("%d%d", &cash, &n) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d%d", &num[i], &bill[i]);
    }

    memset(dp, 0, sizeof(dp));
    /*
    for(int i = 1; i <= n; i ++){
        for(int x = 0; x < num[i];  x ++){
         for(int j = cash; j >= bill[i]; j --){
          if(dp[j] < dp[j-bill[i]]+bill[i])
           dp[j] =  dp[j-bill[i]] + bill[i];
        }
      }
    }
    */

    for(int i = 1; i <= n; i ++){
      int j = 1;
      while( j < num[i]){
        for(int k = cash; k > j*bill[i]; k --){
          if(dp[k-j*bill[i]]) dp[k] = 1;
        }
        num[i] -= j;
        j <<= 1;
      }

    }


    cout << dp[cash] << endl;

  }
  return 0;
}
