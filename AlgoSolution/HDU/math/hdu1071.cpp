// 1071 15MS 248K
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int t;
  double x[4], y[4];
  scanf("%d", &t);
  while(t --){
    for(int i = 1; i <= 3; i ++)
      scanf("%lf%lf", &x[i], &y[i]);
    double a = (y[2]-y[1])/pow(x[2]-x[1], 2);
    double b = -2*a*x[1];
    double c = y[1] + a*x[1]*x[1];
    double k = (y[3]-y[2])/(x[3]-x[2]);
    double m = y[2] - k*x[2];
    //printf("%lf %lf %lf %lf %lf\n", a, b, c, k, m);
    double f3 = a*pow(x[3], 3)/3 + (b-k)*x[3]*x[3]/2 + (c-m)*x[3];
    // 积分上限
    double f2 = a*pow(x[2], 3)/3 + (b-k)*x[2]*x[2]/2 + (c-m)*x[2];
    // 积分下限
    printf("%.2f\n", f3-f2);
  }
  return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int t;
  double x[4], y[4];
  scanf("%d", &t);
  while(t --){
    for(int i = 1; i <= 3; i ++)
      scanf("%lf%lf", &x[i], &y[i]);
    // double a = (y[3]-y[2])/((x[3]-x[2])*(x[3]+x[2]-2*x[1]));
    // 这样求会出现零的情况
    double a = (y[2]-y[1])/pow(x[2]-x[1], 2);
    double b = -2*a*x[1];
    double c = y[1] + a*x[1]*x[1];
    double k = (y[3]-y[2])/(x[3]-x[2]);
    double m = y[2] - k*x[2];
    printf("%lf %lf %lf\n", a, b, k);
    double f3 = a*pow(x[3]-x[1], 3)/3 - k*x[3]*x[3]/2 + (y[1]-m)*x[3];
    // 积分上限
    double f2 = a*pow(x[2]-x[1], 3)/3 - k*x[2]*x[2]/2 + (y[1]-m)*x[2];
    // 积分下限
    printf("%.2f\n", f3-f2);
  }
  return 0;
}
*/
