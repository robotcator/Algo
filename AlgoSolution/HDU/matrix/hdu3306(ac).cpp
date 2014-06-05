//  500MS 276K
// 细节决定成败，所以昨天你一定是细节除了问题
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 7;
const int modu = 10007;
int size = 6;
int row[7] = {1, 1, 1, 1, 1, 2};

struct matrix{
  int elem[maxn][maxn];
  matrix operator*(const matrix& a)const{
    matrix c;
    for(int i = 0; i < size; i ++){
      for(int j = 0; j < size; j ++){
        c.elem[i][j] = 0;
        for(int k = 0; k < size; k ++){
          c.elem[i][j] += (elem[i][k])*(a.elem[k][j])%modu;
        }
        c.elem[i][j] %= modu;
      }
    }
    return c;
  }
};

void power(matrix a, int p){
  matrix ans;
  memset(ans.elem, 0, sizeof(ans.elem));
  for(int i = 0; i < size; i ++)
    ans.elem[i][i] = 1;
  while(p){
    if(p&1) ans = ans*a;
    a = a*a;
    p /= 2;
  }
  int sum = 0;
  for(int i = 0; i < size; i ++){
    sum += row[i]*ans.elem[i][5] % modu;
  }
  printf("%d\n", sum%modu);
}

void init(matrix& a, int x, int y){
    memset(a.elem, 0, sizeof(a.elem));
    x %= modu, y %= modu;
    a.elem[0][0] = a.elem[0][5] = x*x%modu;
    a.elem[1][0] = a.elem[1][5] = y*y%modu;
    a.elem[2][0] = a.elem[2][5] = 2*x*y%modu;
    a.elem[0][1] = a.elem[3][4] = a.elem[5][5] = 1;
    a.elem[0][2] = a.elem[3][3] = x;
    // 注意
    a.elem[2][2] = a.elem[4][3] = y;
}

int main()
{
  matrix m;
  int N, x, y;
  while(scanf("%d%d%d", &N, &x, &y) != EOF){
    init(m, x, y);
    N --;
    power(m, N);
  }
  return 0;
}
