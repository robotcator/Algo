#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int data[100005];
int sum[100005];
int dp[100005];

const int inf = 0x3f3f3f3f;

int main()
{
  int n, m;
  freopen("in.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) != EOF){
    sum[0] = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
      sum[i] = sum[i-1] + data[i];
    }
    int maxn = -inf;
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= m; j ++){
          if(i-j+1 >= 1 && maxn < sum[i] - sum[i-j])
            maxn = sum[i] - sum[i-j];
      }
      dp[i] = maxn;
    }

    cout << dp[n] << endl;

  }
  return 0;
}
