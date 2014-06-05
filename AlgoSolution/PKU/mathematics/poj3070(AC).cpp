/*
// 对于封装度更高的可以使用结构体更好
// Accepted 700K 0MS
#include <cstdio>
#include <iostream>
using namespace std;

struct matrix{
  int elem[2][2];
};

int modu = 10000;
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

void solve(int n) {
  matrix f = {1, 1, 1, 0};
//  matrix ans = multi_matrix(f, e);
//  for(int i = 0; i < 2; i ++){
//    for(int j = 0; j < 2; j ++)
//      printf("%d ", ans.elem[i][j]);
//    printf("\n");
//  }
  matrix ans = power_matrix(f, n);
  printf("%d\n", ans.elem[0][1]%modu);
}

int main()
{
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == -1) break;
    solve(n);
  }
  return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct F_Matrix{
  public :
  int elem[10][10];
  int size;
  // 只对于此题fibinacci数列
  F_Matrix();
  void unit();
  F_Matrix operator*(F_Matrix &new_matrix);
  F_Matrix power(int n);
};

F_Matrix e;

F_Matrix::F_Matrix() {
  memset(elem, 0, sizeof(elem));
}

void F_Matrix::unit() {
  for(int i = 0; i < 2; i ++)
    this->elem[i][i] = 1;
}

F_Matrix F_Matrix::operator*(F_Matrix &new_matrix) {
  F_Matrix product;
  for(int i = 0; i < 2; i ++){
    for(int j = 0; j < 2; j ++){
      for(int k = 0; k < 2; k ++){
        product.elem[i][j] += (*this).elem[i][k]*new_matrix.elem[k][j];
      }
    }
  }
  return product;
}

F_Matrix F_Matrix:: power(int n) {
  if(n == 0) return e;
  F_Matrix ans = (*this).power(n/2);
  ans = ans * ans;
  if(n % 2 == 1) ans = ans * (*this);
  return ans;
}

int cal_F(F_Matrix a){
  int x[5] = {1, 1};
  int ans[10];
  for(int i = 0; i < 2; i ++){
    for(int j = 0; j < 1; j ++){
      ans [i] = 0;
      for(int k = 0; k < 2; k ++)
        ans[i] += a.elem[i][k]*x[k];
    }
  }
  return ans[0];
}

void Init(F_Matrix &a){
  a.elem[0][0] = 0;
  a.elem[0][1] = 1;
  a.elem[1][0] = 1;
  a.elem[1][1] = 1;
}

int main()
{
  e.unit();
  F_Matrix a;
  Init(a);
  // Fibonacci的前两项
  int n;
  while(scanf("%d", &n) != EOF){
    F_Matrix ans = a.power(n);
    int res = cal_F(ans);
    cout << res << endl;
  }
  return 0;
}


