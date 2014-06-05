// Accepted 236K 0MS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
/*
double C(unsigned int n, unsigned int k){
  if(k > n) return 0;
  if(k > 2/n) k = n-k;
  double s1, s2;
  s1 = s2 = 0;
  for(int i = k+1; i <= n; i ++){
    s1 += log((double)i);
  }
  for(int i = 1; i <= n-k; i ++){
    s2 += log(double(i));
  }
  return exp(s1-s2);
}
*/
double C(unsigned int n, unsigned int k){
  if(k > n) return 0;
  if(k > n/2) k = n-k;
  double s = 1.0;
  while(k > 0) s *= 1.0*(n--)/(k--);
  return s;
}

int main()
{
  unsigned int a, b;
  while(scanf("%d%d", &a, &b) != EOF){
    if(a == 0 && b == 0) return 0;
    long long ans = (long long)(C(a+b, a)+0.5);
    cout << ans << endl;
  }
  return 0;
}
