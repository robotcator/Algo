// 2604 171MS 280K
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// fn = fn-1 + fn-3 + fn-4
const int maxn = 5;
int size = 4;
int modu;
struct matrix{
  int elem[maxn][maxn];
  matrix(){
    memset(elem, 0, sizeof(elem));
  }
  matrix operator*(const matrix a)const{
    matrix c;
    for(int i = 0; i < size; i ++){
      for(int j = 0; j < size; j ++){
        for(int k = 0; k < size; k ++){
          c.elem[i][j] += (elem[i][k]*a.elem[k][j])%modu;
          c.elem[i][j] %= modu;
        }
      }
    }
    return c;
  }
};

matrix power(matrix a, int p){
  matrix ans;
  for(int i = 0; i < size; i ++) ans.elem[i][i] = 1;
  while(p){
    if(p & 1) ans = ans*a;
    a = a * a;
    p >>= 1;
    //cout << p << endl;
  }
  return ans;
}


int main()
{
  int l, m;
  int row[5] = {0, 2, 4, 6, 9};
  int a[5] = {1, 1, 0, 1};
  while(scanf("%d%d", &l, &m) != EOF){
    modu = m;
    // 还要注意如何处理递推式小数据
    if(l > 4){
      matrix x;
      for(int i = 0; i < size-1; i ++){
        x.elem[i][i+1] = 1;
      }
      for(int i = 0; i < size; i ++)
        x.elem[3][i] = a[i];
      /*
      for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j ++){
          cout << x.elem[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      */
      matrix ans = power(x, l-4);
      // 递推式中有d项，那么初始从d开始，然后乘以l-d+1次幂
      int sum = 0;
      /*
      for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j ++){
          cout << ans.elem[i][j] << " ";
        }
        cout << endl;
      }
*/
      for(int i = 0; i < size; i ++){
        sum += row[i+1]*ans.elem[3][i];
        // 一定要注意从哪项开始
        sum %= modu;
      }
      printf("%d\n", sum);
    }
    else {
      printf("%d\n", row[l]%modu);
    }
  }
  return 0;
}
