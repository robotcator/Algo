/*
    ID : problem6
    PROG : hdu3555
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

typedef unsigned long long ULL;
typedef long long LL;
ULL dp[25][3];
/*
  dp[i][0] 不含49
  dp[i][1] 不含49，但以9开头
  dp[i][2] 含49
*/
void init(){
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1; i <= 22; i ++){
    dp[i][0] = 10*dp[i-1][0] - dp[i-1][1];
    dp[i][1] = dp[i-1][0];
    dp[i][2] = 10*dp[i-1][2] + dp[i-1][1];
  }
}

int digit[25];
int cnt;
LL count(ULL x){
  cnt = 1;
  while(x){
    digit[cnt++] = x%10;
    x /= 10;
  }
  digit[cnt] = 0;
  LL ans = 0;
  int flag = 0;
  for(int i = cnt-1; i > 0; i --){
    ans += digit[i]*dp[i-1][2];
    if(flag) ans += digit[i]*dp[i-1][0];
    else{
      if(digit[i] > 4) ans += dp[i-1][1];
    }
    if(digit[i+1] == 4 && digit[i] == 9)
      flag = 1;
  }
  return ans;
}

int main(){
  init();
  int t;
  scanf("%d", &t);
  while(t--){
    ULL n;
    scanf("%I64d", &n);
    LL ans = count(n+1);
    printf("%I64d\n", ans);
  }
  return 0;
}
