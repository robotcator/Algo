#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int power(int n, int p, int modu){
  if(p == 0) return 1;
  int ans = power(n, p/2, modu);
  ans = ans*ans%modu;
  if(p % 2 == 1) ans = ans*n%modu;
  return ans;
}

int main(){
  int m, n, k;
  while(scanf("%d%d%d", &n, &m, &k) != EOF){
    int x, cnt;
    cnt = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      int ans = power(x, m, k);
      //cout << ans << endl;
      if(ans == 0) cnt ++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
/*
整数快速幂
1561522	13.05.14 15:13	robotcator	117 	.CPP	Accepted 	15 ms	62 kb
*/
