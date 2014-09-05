/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1000+10;
const int inf = 0x3f3f3f3f;
const int mod = 6;

class matrix{
  public:
  int **elem;
  int n, m;
  matrix(int n, int m){
    this->n = n;
    this->m = m;
    elem = new int*[n];
    for(int i = 0; i < n; i ++)
      elem[i] = new int[m];
  }
};

matrix multi(matrix a, matrix b){
  matrix c(a.n, b.m);
  for(int i = 0; i < a.n; i ++){
    for(int j = 0; j < b.m; j ++){
      for(int k = 0; k < a.m; k ++){
        c.elem[i][j] += a.elem[i][k]*b.elem[k][j];
      }
      c.elem[i][j] %= mod;
    }
  }
  return c;
}

matrix power(matrix a, int n){
  if(n == 1) return a;
  matrix ans = power(a, n/2);
  ans = multi(ans, ans);
  if(n % 2) ans = multi(ans, a);
  return ans;
}

int main(){
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    if(n == 0 && k == 0) break;
    matrix a(n, k);
    matrix b(k, n);
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < k; j ++){
        scanf("%d", &a.elem[i][j]);
      }
    }
    for(int i = 0; i < k; i ++){
      for(int j = 0; j < n; j ++){
        scanf("%d", &b.elem[i][j]);
      }
    }

    matrix c = multi(b, a);
    matrix mid = power(c, n*n-1);
    matrix left = multi(a, mid);
    matrix right = multi(left, b);
    int ans = 0;
    for(int i = 0; i < right.n; i ++){
      for(int j = 0; j < right.m; j ++){
        ans += right.elem[i][j];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
