/*
    ID: problem6
    PROG : 最大连续子序列
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10000+10;
int data[maxn];
int dp[maxn];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    for(int i = 0; i < n; i ++){
      scanf("%d", &data[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = data[0];
    int st = 0, ed = 0;
    for(int i = 1; i < n; i ++){
       if(data[i] < dp[i-1] + data[i]) dp[i] = dp[i-1] + data[i];
       else dp[i] = data[i];
    }
    int ans = -0x3f3f3f3f;
    for(int i = 0; i < n; i ++){
      if(ans < dp[i]) {
        ans = dp[i];
        ed = i;
      }
    }
    for(int i = ed; i >= 0; i --){
      if(data[i] == dp[i]){
        st = i;
        break;
      }
    }
    if(ans >= 0) printf("%d %d %d\n", ans, data[st], data[ed]);
    else printf("%d %d %d\n", 0, data[0], data[n-1]);
  }
    return 0;
}
