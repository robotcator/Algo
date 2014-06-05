// Accepted 8164K 1672MS
#include <cstdio>
#include <cstring>

using namespace std;

int d[50005][20];
int dmax[50005][20];

int minn(int a, int b) { return a > b ? b : a; }
int maxn(int a, int b) { return a < b ? b : a; }

void Init(int *a, int n) {
  for(int i = 1; i <= n; i ++) {
      d[i][0] = a[i];
      dmax[i][0] = a[i];
  }
  for(int j = 1; 1 << j <= n; j ++){
    for(int i = 1; i + (1<<j)-1 <= n; i ++){
      d[i][j] = minn(d[i][j-1], d[i+(1<<(j-1))][j-1]);
      dmax[i][j] = maxn(dmax[i][j-1], dmax[i+(1<<(j-1))][j-1]);
    }
   }

//  for(int j = 0; (1<<j) <= n; j ++){
//    for(int i = 1; (i +(1<<j)-1) <= n; i ++)
//      printf("%d ", d[i][j]);
//    printf("\n");
//  }

}

void RMQ(int l, int r, int& Maxn, int& Minn) {
  int k = 0;
  // 2^k <= (r-l+1)的最大整数
  while((1<<(1+k)) <= r-l+1) k ++;
  Minn =  minn(d[l][k], d[r-(1<<k)+1][k]);
  Maxn =  maxn(dmax[l][k], dmax[r-(1<<k)+1][k]);
  return ;
}

int main()
{
  int n, q;
  int a[50005];
  while(scanf("%d%d", &n, &q) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &a[i]);
    }
    Init(a, n);
    for(int i = 0; i < q; i ++){
        int x, y;
        scanf("%d%d", &x, &y);
        int Max , Min;
        RMQ(x, y, Max, Min);
        printf("%d\n", Max - Min);
    }
  }
  return 0;
}
