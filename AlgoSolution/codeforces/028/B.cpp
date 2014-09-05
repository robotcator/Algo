/*
    ID: problem6
    PROG : pSort
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int data[maxn];
int f[maxn];
bool w[maxn][maxn];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
    }
    memset(w, 0, sizeof(w));
    int d;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &d);
      w[i][i] = 1;
      if(i-d >= 1) w[i][i-d] = w[i-d][i] = 1;
      if(i+d <= n) w[i][i+d] = w[i+d][i] = 1;
    }
    for(int k = 1; k <= n; k ++){
      for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
          w[i][j] |= w[i][k]&&w[k][j];
        }
      }
    }
    bool flag = true;
    for(int i = 1; flag && i <= n; ++i) {
      flag &= w[i][data[i]];
    }
    // 所有都是可达的
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
