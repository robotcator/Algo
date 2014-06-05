#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  int data[70];
  int sum;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    sum = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d", &data[i]);
      sum += data[i];
    }

  }
  return 0;
}
