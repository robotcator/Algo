// 10798861	2014-05-25 16:50:27	Accepted	1171	531MS	1268K	881 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 50+10;
int value[maxn], num[maxn];
int dp[250000];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(n < 0) break;
    int sum = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &value[i], &num[i]);
      sum += value[i]*num[i];
    }
    int vol = sum/2;
    //cout << vol << endl;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i ++){
      for(int j = 1; j <= num[i]; j ++){
        for(int k = vol; k >= value[i]; k --){
          if(dp[k-value[i]] + value[i] > dp[k])
            dp[k] = dp[k-value[i]] + value[i];
        }
      }
    }
    int ans = dp[vol] > sum - dp[vol] ? dp[vol] : sum-dp[vol];
    printf("%d %d\n",  ans, sum-ans);
  }
  return 0;
}
