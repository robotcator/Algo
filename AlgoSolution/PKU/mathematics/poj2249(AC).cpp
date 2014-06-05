// Accepted
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

long long C1(int n, int k)
{
  long long c[100];
  c[0] = 1;
  c[1] = n;
  k = k > n/2 ? n-k : k;
  for(int i = 1; i < k; i ++){
    c[i+1] = c[i]*(n-i)/(i+1);
    //printf("%d\n", c[i+1]);
  }
  return c[k];
}

long long C(int n, int k)
{
  k = k > n/2 ? n-k : k;
  long long a = 1;
  for(int i = 0; i < k; i ++)
    a = a*(n-i)/(i+1);
  //printf("%lld\n", a);
  return a;
}

int main()
{
  int n, k ;
  while(scanf("%d%d", &n, &k) != EOF){
    if(n == 0 && k == 0) break;
    long long ans = C(n, k);
    printf("%lld\n", ans);
  }
  return 0;
}
