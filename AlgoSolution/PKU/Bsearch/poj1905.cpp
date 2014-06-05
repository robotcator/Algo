// Accepted 164K 0MS
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
const double eps = 1E-4;
// ���Ȼ�Ӱ��Ƚϵ�ʱ�䣬���Ծ���Ҫ����
// һ��ȥ���ȶ�һλ����
// ����Ҫ�����������еĹ�ʽ
// ���쵥��������Ȼ����ȷ��
// ���½���ж���

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
      //ֻ��Ҫ�Ƚϴ�С������Ҫ�󲻵�ʽ�ұߵĵ�����
        high = mid;
      else low = mid;
      // ����double�������-1�����п���������
    }
    printf("%.3lf\n", mid);
  }
  return 0;
}
