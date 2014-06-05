/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int price[105], weight[105], bag[105];
int dp[105];

int main()
{
  int t;
  scanf("%d", &t);
  while(t --){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &price[i], &weight[i], &bag[i]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < m; i ++){
      for(int j = 0; j < bag[i]; j ++){
        for(int k = n; k >= price[i]; k --){
          if(dp[k] < dp[k-price[i]] + weight[i])
            dp[k] = dp[k-price[i]] + weight[i];
        }
        for(int l = 0; l <= n; l ++)
          cout << dp[l] << " ";
        cout << endl;
      }
    }
    cout << dp[n] << endl;
  }
  return 0;
}
*/


/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int price[105], weight[105], bag[105];
int dp[105];

int main()
{
  int t;
  scanf("%d", &t);
  while(t --){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &price[i], &weight[i], &bag[i]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < m; i ++){
      int left = bag[i];
      for(int j = 1; j <= left; j <<= 1){
          for(int k = n; k >= j*price[i]; k --){
            if(dp[k] < dp[k-j*price[i]] + j*weight[i])
              dp[k] = dp[k-j*price[i]] + j*weight[i];
          }
          left -= j;
      }
      if(left > 0){
        for(int k = n; k >= left*price[i]; k --){
            if(dp[k] < dp[k-left*price[i]] + left*weight[i])
              dp[k] = dp[k-left*price[i]] + left*weight[i];
          }
      }

    }
    cout << dp[n] << endl;
  }
  return 0;
}

*/


#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int minn(int a, int b) { return a < b : a ? b; }
int price[105], weight[105], bag[105];
int dp[105];

int main()
{
  int t;
  scanf("%d", &t);
  while(t --){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &price[i], &weight[i], &bag[i]);
    }
    memset(dp, 0, sizeof(dp));
    int head , tail;
    for(int i = 0; i < m; i ++){
      int num = minn(bag[i], m/price[i]);

      for(int j = 0; j < price[i]; j ++){
        head = tail = 0;

        for(int k = 0; k <= (m-j)/c; k ++){
          int x = j;
          int y = f[k*c+j]-k*w;
          while(head < tail && y >= b[tail-1])
            tail --;
          a[tail] = x;
          b[tail] = y;
          tail ++;
          while(a[head] < k-bag[i])
        }
      }

    }
    cout << dp[n] << endl;
  }
  return 0;
}
