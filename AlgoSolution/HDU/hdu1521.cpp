// 10792196	2014-05-24 11:23:46	Accepted	1521	0MS	300K	1143 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 15;
int num[maxn];
int f[maxn];

void get_factorial(){
  f[0] = f[1] = 1;
  for(int i = 1; i < 15; i ++)
    f[i] = f[i-1]*i;
}

double coefficient[10*maxn];
double temp[10*maxn];

int main(){
  int n, m;
  get_factorial();
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 0; i < n; i ++)
      scanf("%d", &num[i]);
    memset(coefficient, 0, sizeof(coefficient));
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i <= num[0]; i ++){
      coefficient[i] = 1.0/f[i];
      //printf("%lf\n", coefficient[i]);
    }
    for(int i = 1; i < n; i ++){
      for(int j = 0; j < 10*maxn; j ++){
          //  这里maxn去最高次位数
        for(int k = 0; k <= num[i] && j+k < 10*maxn; k ++){
          temp[j+k] += coefficient[j]*(1.0/f[k]);
        }
      }
      for(int j = 0; j <= 10*maxn; j ++)
        coefficient[j] = temp[j];
      memset(temp, 0, sizeof(temp));
    }
    printf("%.0lf\n", coefficient[m]*f[m]);
  }
  return 0;
}
