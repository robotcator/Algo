// 0MS 276K 1996 B
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


// f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
// 矩阵构造列要从小到大
const int maxn = 15;
int row[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int size = 10;
int modu;

struct matrix{
  int elem[maxn][maxn];
  matrix(){
    memset(elem, 0, sizeof(elem));
  }
  matrix operator*(const matrix& a)const{
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
    p >>= 1;
    a = a*a;
  }
  return ans;

}

void init(matrix &x, int *a){
  for(int i = 0; i < size; i ++){
    x.elem[i][i+1] = 1;
  }
  for(int i = 0; i < size; i ++){
    x.elem[9][i] = a[size-i-1];
    // fn-10 对应的是a9
  }
  // 如何快速构造
}

int main()
{
  int k, m;
  int a[10];
  matrix x;
  while(scanf("%d%d", &k, &m) != EOF){
    for(int i = 0; i <= 9; i ++){
      scanf("%d", &a[i]);
    }
    if(k < 10){
      printf("%d", row[k]);
    }
    else {
      modu = m;
      init(x, a);
      /*
      for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j ++){
          cout << x.elem[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      */
      matrix ans = power(x, k-10+1);
      /*
      for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j ++){
          cout << ans.elem[i][j] << " ";
        }
        cout << endl;
      }
      */
      int sum = 0;
      for(int i = 0; i < 10; i ++){
          sum += row[i]*ans.elem[9][i];
          sum %= modu;
      }
      printf("%d\n", sum);
    }

  }
  return 0;
}
