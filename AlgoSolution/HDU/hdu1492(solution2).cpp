// 10795812	2014-05-24 23:22:59	Accepted	1492	250MS	340K	659 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100;
int fac[5] = {2, 3, 5, 7};
int num[5];

int main(){
  long long n;
  while(cin >> n){
    if(n == 0) break;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < 4; i ++){
      if(n % fac[i] == 0){
        while(n % fac[i] == 0){ n /= fac[i]; num[i] ++; };
      }
    }
    int ans = 1;
    for(int i = 0; i < 4; i ++)
      ans *= (num[i]+1);
    cout << ans << endl;
  }
  return 0;
}
