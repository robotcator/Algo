/*
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a[10000];
  int b[10000];
  for(int i = 0; i < 100; i ++){
    int n = rand()%1000;
    for(int i = 1; i < n; i ++) a[i] = b[i] = i;
    for(int j = n-1; j > 1; j --) {
      swap(a[j], a[rand()%j]);
      swap(b[j], b[rand()%j]);
    }
    printf("%d\n", n-1);
    for(int i = 1; i < n; i ++){
      printf("%d %d\n", a[i], b[i]);
    }
  }

  printf("0\n");
  return 0;
}
*/

/*
  1.如何产生互不相同的随机数
  2.如何产生在nc以内的数
*/

/*
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a[10000];
  for(int i = 0; i < 100; i ++){
    int n = rand()%100;
    int nc = rand()%256;
    printf("%d %d\n", n, nc);
    int len = rand()%16000000;
    for(int i = 1; i < nc; i ++) a[i] = i;
    for(int j = nc-1; j > 1; j --) {
      swap(a[j], a[rand()%j]);
    }
    // nc内互不相同的数
    for(int i = 0; i < len; i ++){
     int temp = rand()%nc;
     printf("%c\n", a[temp]+'a');
    }
  }

  printf("0\n");
  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  for(int i = 0; i < 64; i ++)
    printf("p");
  return 0;
}
