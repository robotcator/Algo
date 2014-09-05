#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while(t --){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (a%100+b%100)%100);
  }

  return 0;
}
