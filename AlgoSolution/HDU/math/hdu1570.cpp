// Accepted	1570	0MS	336K	905 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int permutation(int n, int m){
  int f1, f2;
  f1 = f2 = 1;
  for(int i = 1; i <= n; i ++)
    f1 *= i;
  for(int i = 1; i <= n-m; i ++)
    f2 *= i;
  return f1/f2;
}
// 可以用对数
int combination(int n, int m){
  int f1, f2;
  f1 = f2 = 1;
  for(int i = n-m+1; i <= n; i ++)
    f1 *= i;
  for(int i = 1; i <= m; i ++)
    f2 *= i;
  return f1/f2;
}

int main(){
  int t, n, m;
  char ch;
  scanf("%d", &t);
  for(int test = 1; test <= t; test ++){
      getchar();
      scanf("%c %d %d", &ch, &n, &m);
      int ans = 0;
      if(ch == 'A'){
         ans = permutation(n, m);
         cout << ans << endl;
      }
      else if(ch == 'C'){
         ans = combination(n, m);
         cout << ans << endl;
      }
  }
  return 0;
}
