/*
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    int x, ans;
    ans = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      ans ^= x;
    }
    cout << ans << endl;
  }
  return 0;
}
*/
