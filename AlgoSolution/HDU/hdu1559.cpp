/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000+10;
int data[maxn][maxn];
int dp[maxn][maxn];

int main(){
  int m, n, x, y, t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d%d", &m, &n, &x, &y);
    memset(data, 0, sizeof(data));
    for(int i = 1; i <= m; i ++){
      for(int j = 1; j <= n; j ++){
        scanf("%d", &data[i][j]);
        data[i][j] += data[i-1][j];
      }
    }
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = x; i <= m; i ++){
      for(int j = 1; j <= n; j ++){
        if(j >= y)
          dp[i][j] = (dp[i][j-1]+(data[i][j]-data[i-x][j]))-(data[i][j-y]-data[i-x][j-y]);
        else
          dp[i][j] = (dp[i][j-1]+(data[i][j]-data[i-x][j]));
      }
    }
    for(int i = 1; i <= m; i ++){
      for(int j = 1; j <= n; j ++){
       // cout << dp[i][j] << " ";
        ans = max(ans, dp[i][j]);
      }
     // cout << endl;
    }
    printf("%d\n", ans);
  }
  return 0;
}

/*
退而求其次，从一维入手
*/
