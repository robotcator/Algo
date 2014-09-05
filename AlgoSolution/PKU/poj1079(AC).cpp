// Compile Error
// Accepted 396K 0MS
#include <cstdio>
#include <cmath>
#include <cstdlib>
// 注意这里用c++时，c的头文件还是用c不用.h
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

void init(int &a, int &b) {
  int temp = gcd(a, b);
  a /= temp;
  b /= temp;
}
void solve(int a, int b)
{
  init(a, b);
  //printf("%d %d", a, b);
  int q = 0;
  int p = 1;
  for(int i = 1; i <= b; i ++){
    int x = ((double)(i*a)/(double)b+0.5);
    if(q*abs(a*i-b*x) < i*abs(a*q-b*p)){
      p = x; q = i;
      printf("%d/%d\n", p, q);
    }
  }
}

int main()
{
  int a, b;
  while(scanf("%d%d", &a, &b) != EOF){
    solve(a, b);
    printf("\n");
  }
  return 0;
}


