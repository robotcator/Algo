// Accepted 180K 16MS C++ 1057B 2014-05-06 23:19:48
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100+10;
const int inf = 0x3f3f3f3f;
int matrix[maxn][maxn];
int p[maxn];
int vis[maxn];

int prim(int n){
  int res = 0;
  memset(vis, 0, sizeof(vis));
  memset(p, 0, sizeof(p));
  for(int i = 0; i < n; i ++)
    p[i] = matrix[0][i];
  vis[0] = 1;
  for(int i = 1; i < n; i ++){
    int minn = inf;
    int minj = 0;
    for(int j = 0; j < n; j ++){
      if(vis[j] == 0 && p[j] < minn) { minn = p[j]; minj = j; }
    }
    if(minn == inf) -1;
    res += minn;  vis[minj] = 1;
    for(int j = 0; j < n; j ++){
      if(vis[j] == 0 && matrix[minj][j] < p[j]) {
        p[j] = matrix[minj][j];
      }
    }
  }
  return res;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    memset(matrix, 0, sizeof(matrix));
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++){
        scanf("%d", &matrix[i][j]);
      }
    }
    int ans = prim(n);
    printf("%d\n", ans);
  }
  return 0;
}



