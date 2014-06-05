

/*
// solution one
// 1561243	10.05.14 19:04	robotcator	102 	.CPP	Accepted 	15 ms	66 kb
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int euler(int n){
  int ans = n;
  int m = sqrt(n+0.5);
  // cout << m << endl;
  for(int i = 2; i <= m; i ++){
    if(n % i == 0){
      ans = ans/i*(i-1);
      // 防止溢出 coprime
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ans = ans/n*(n-1);
  return ans;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int ans = euler(n);
    printf("%d\n", ans);
  }
  return 0;
}
*/
