#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  int n, m;
  printf("%d\n", 1000);
  for(int i = 0; i < 1000; i ++){
    n = (rand()%999) + 1;
    m = rand()%(6000);
    printf("%d %d\n", n, m);
    int x, y, h;
    for(int j = 0; j < m; j ++){
      x = rand()%(n-1) + 1;
      y = rand()%(n-1) + 1;
      //h = rand()%1000;
      printf("%d %d\n", x, y);
    }
    /*
    int a, b;
    int q = rand()%100;
    printf("%d\n", q);
    for(int k = 0; k < q; k ++){
      a = rand()%(n-1) + 1;
      b = rand()%(n-1) + 1;
      printf("%d %d\n", a, b);
    }
    */
    printf("\n\n");
  }
  return 0;
}
