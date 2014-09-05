#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int w(int a, int b, int c)
{
  if(a <= 0 || b <= 0 || c <= 0)
    return 1;
  else if(a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);
  else if(a < b && b < c)
    return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  else
    return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) != EOF){
    if(a == -1 && b == -1 && c == -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
  return 0;
}
