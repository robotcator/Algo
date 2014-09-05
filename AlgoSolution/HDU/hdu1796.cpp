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

const int maxn = 20+10;
int M[maxn];

__int64 gcd(__int64 a, __int64 b){
  return (b == 0)  ? a : gcd(b, a%b);
}
__int64 lcm(__int64 a, __int64 b){
  return a/(gcd(a, b))*b;
}

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    int num = 0;
    int x;
    for(int i = 1; i <= m; i ++){
      scanf("%d", &x);
      if(x > 0) M[num++] = x;
    }
    n --;
    // 要小于n
    __int64 ans = 0;
    // 注意枚举范围，不然很难查找处错误
    for(int i = 1; i < (1 << num); i ++){
      int temp = 0;
      __int64 base = 1;
      for(int j = 0; j < num; j ++){
        if(i & (1<<j)){
          temp ++;
          base = lcm(base, (__int64)M[j]);
        }
      }
      if(temp%2 == 1) ans += n/base;
      else ans -= n/base;
    }
    cout << ans << endl;
  }
  return 0;
}




/*
11466957	2014-08-16 23:30:03	Accepted
1796	984MS	368K	1048 B	G++	robotcator
*/
