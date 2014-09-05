//Accepted 164K 0MS
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[50][2];
void table()
{
  a[1][0] = a[1][1] = 1;
  for(int i = 2; i <= 50; i ++){
    a[i][0] = a[i-1][0] + a[i-1][1];
    a[i][1] = a[i-1][0];
  }
}
// 第n个数时0或1进行分类做加法
int main()
{
  int n, t;
  int flag = 1;
  table();
  scanf("%d", &t);
  while(t --){
     scanf("%d", &n);
     printf("Scenario #%d:\n%d\n\n", flag ++, a[n][0]+a[n][1]);
  }
  return 0;
}
