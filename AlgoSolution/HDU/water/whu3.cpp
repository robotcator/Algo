#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
const int modu = 1000000007;

struct matrix{
  int elem[2][2];
};

matrix e = {1, 0, 0, 1};

matrix multi_matrix(matrix a, matrix b)
{
  matrix pro;
  for(int i = 0; i < 2; i ++) {
    for(int j = 0; j < 2; j ++){
      pro.elem[i][j] = 0;
      for(int k = 0; k < 2; k ++)
        pro.elem[i][j] += ((a.elem[i][k]%modu)*(b.elem[k][j]%modu))%modu;
    }
  }
  return pro;
}

matrix power_matrix(matrix a, int n)
{
  if(n == 0) return e;
  matrix ans = power_matrix(a, n/2);
  ans = multi_matrix(ans, ans);
  if(n % 2 == 1) ans = multi_matrix(a, ans);
  return ans;
}

LL f(int n) {
  matrix f = {1, 1, 1, 0};
  matrix ans = power_matrix(f, n);
  return ans.elem[0][1]%modu;
}

int main()
{
  int n;
  while(scanf("%d", &n) != EOF){
      if(n == 0) break;
      long long sum = 0;

      cout << sum << endl;
  }
  return 0;
}
