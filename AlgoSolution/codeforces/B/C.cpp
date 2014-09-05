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
int cur[maxn][maxn];
// hang on second

int main(){
  int n, k, d;
  scanf("%d%d%d", &n, &k, &d);
  long long ans = 1;
  for(int i = 1; i <= d; i ++){
    ans *= k;
    if(ans >= n) break;
  }
  if(ans < n) {printf("-1\n"); return 0;}
  for(int i = 1; i <= d; i ++) cur[0][i] = 1;

  for(int i = 1; i < n; i ++){
    for(int j = 1; j <= d; j ++) cur[i][j] = cur[i-1][j];
    for(int j = 1; j <= d; j ++){
      cur[i][j] = cur[i-1][j]+1;
      if(cur[i][j] <= k) break;
      else {
        cur[i][j] = 1;
      }
    }
  }
  for(int i = 1; i <= d; i ++){
    for(int j = 0; j < n; j ++){
      printf("%d ", cur[j][i]);
    }
    printf("\n");
  }
  // 输出矩阵的转置
  return 0;
}
