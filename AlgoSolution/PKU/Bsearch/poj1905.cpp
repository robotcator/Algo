// Accepted 164K 0MS
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
const double eps = 1E-4;
// 精度会影响比较的时间，所以精度要适中
// 一般去精度多一位即可
// 首先要利用手上已有的公式
// 构造单调函数，然后再确定
// 上下界进行二分

int main()
{
  double L, n, c;
  while(scanf("%lf%lf%lf", &L, &n, &c) != EOF){
    if(L == -1 && n == -1 && c == -1) break;
    double L1 = (1+n*c)*L;
    double high = L/2;
    double low = 0;
    double mid;
    while(high - low > eps){
      mid = (low+high)/2;
      double r = (L*L+4*mid*mid)/(8*mid);
      if( L1 < 2*r*(asin(L/(2*r))) )
      //只需要比较大小，不需要求不等式右边的单调性
        high = mid;
      else low = mid;
      // 对于double类型如果-1操作有可能误差会变大
    }
    printf("%.3lf\n", mid);
  }
  return 0;
}
