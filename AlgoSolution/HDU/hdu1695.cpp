#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int GCD(int a, int b)
{
  if(b == 0) return a;
  else return GCD(b, a%b);
}
/*
int solve(int a, int b, int c, int d, int k)
{
  int num = 0;
  for(int i = a; i <= b; i ++){
    for(int j = c; j <= d; j ++){
      if(k == GCD(i, j)) {
          num ++;
          printf("%d %d\n", i, j);
      }
    }
  }
  return num;
}
*/

int main()
{
  int a, b, c, d, k;
  int T;
  int flag = 1;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    int ans = solve(a, b, c, d, k);
    printf("Case %d: %d\n", flag ++, ans);
  }
  return 0;
}
