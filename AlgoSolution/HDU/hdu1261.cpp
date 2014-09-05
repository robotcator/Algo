#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int num[30];
double fac[15];

double solve(int *num, int n){
  double f1, f2;
  f1 = f2 = 0;
  int cnt = 0;
  for(int i = 0; i < n; i ++){
    cnt += num[i];
    for(int j = 1; j <= num[i]; j ++){
      f1 += log(j);
    }
  }
  for(int i = 1; i <= cnt; i ++)
    f2 += log(i);
  return exp(f2-f1);
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    for(int i = 0; i < n; i ++)
      scanf("%d", &num[i]);
      double ans = solve(num, n);
      printf("%.0lf\n", ans);
    /*
    memset(temp, 0, sizeof(temp));
    // 对于求具体某一项时用母函数，但是如果是总数可以用公式
    for(int i = 0; i < num[0]; i ++)
      coefficient[i] = 1.0/fac[i];
    for(int i = 1; i < n; i ++){
      for(int j = 0; j < 450; j ++){
        for(int k = 0; k < num[i] && k+j < 450; k ++)
          temp[j+k] += coefficient[j]*(1.0/fac[k]);
      }
      for(int j = 0; j < 450; j ++)
        coefficient[j] = temp[j];
      memset(temp, 0, sizeof(temp));
    }
    */
  }
  return 0;
}
