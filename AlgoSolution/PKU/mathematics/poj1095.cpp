#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int catlan[50];
// n = 19 70000000+
// catlan(n) = sigma(catlan(i)*catlan(n-i+1))  i = 2 to n-1
// catlan(n+1) = (4*n-6)/n*catlan(n)
void table() {
  long long f[50];
  catlan[1] = f[3] = 1;
  catlan[2] = f[4] = 2;
  for(int i = 4; i < 20; i ++){
    catlan[i-1] = f[i+1] = (4*i-6)*f[i]/i;
  }
 // for(int i = 1; i < 20; i ++)
 //   printf("%d\n", catlan[i]);
}

void solve(int n)
{
  int i = 1;
  while(catlan[i] < n) { i ++ ; n -= catlan[i]; }
  printf("%d %d\n", i, n);


}

int main()
{
  int n;
  table();
  while(scanf("%d", &n), n){
    solve(n);
  }
  return 0;
}
