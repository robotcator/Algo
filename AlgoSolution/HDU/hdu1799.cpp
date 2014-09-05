// 10793111	2014-05-24 15:02:20	Accepted	1799	31MS	16116K	634 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int modu = 1007;
const int maxn = 2000+10;
int C[maxn][maxn];

void combination(){
  memset(C, 0, sizeof(C));
  C[1][0] = C[1][1] = 1;
  for(int i = 2; i <= 2000; i ++){
    C[i][0] = 1;
    for(int j = 1; j <= i; j ++){
      C[i][j] = (C[i-1][j] + C[i-1][j-1])%modu;
    }
  }
}

int main(){
  int n, m, T;
  combination();
  scanf("%d", &T);
  for(int test = 1; test <= T; test ++){
    scanf("%d%d", &m, &n);
    printf("%d\n", C[n][m]);
    // m > n 输出0
  }
  return 0;
}
