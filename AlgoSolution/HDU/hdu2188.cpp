#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int c;
  scanf("%d", &c);
  while(c --){
    int m, n;
    scanf("%d%d", &n, &m);
    if(n <= m) printf("Grass\n");
    else {
      if(n%(m+1) == 0) printf("Rabbit\n");
      else printf("Grass\n");
    }
  }
  return 0;
}
