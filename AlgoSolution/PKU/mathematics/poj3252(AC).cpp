// Time Limit Exceeded
/*
#include <cstdio>
#include <cstring>

using namespace std;

bool isRound(int x) {
  int num0, num1;
  num0 = num1 = 0;
  while(x) {
    if(x & 1) num1 ++;
    else num0 ++;
    //printf("%d\n", x&1);
    x = x >> 1;
  }
  return num0 >= num1 ? 1 : 0;
}

int main()
{
  int st, ed;
  while(scanf("%d%d", &st, &ed) != EOF){
    int num = 0;
    for(int i = st; i <= ed; i ++)
      if(isRound(i)) {
          num ++;
       //   printf("%d\n", i);
      }
    printf("%d\n", num);
  }
  return 0;
}
*/
// 统计1---n的round数

#include <cstdio>
#include <cstring>

using namespace std;

int c[35][35];

void Com()
{
  memset(c, 0, sizeof(c));
  c[0][0] = 1;
  for(int i = 0; i < 35; i ++) c[i][0] = 1;
  for(int i = 1; i < 35; i ++){
    for(int j = 1; j <= i; j ++){
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
}

int solve(int n)
{
  int digt[35];
  int len = 0;
  while(n) {
    digt[len++] = n&1;
    n = n >> 1;
  }
  int num = 0;
  for(int i = 1; i < len; i ++){
    for(int j = (i+1)/2; j < i; j ++)
    num += c[i-1][j];
  }
  // j > i/2 理清思路
  // printf("%d\n", num);
  // 位数小于len
  // 下面为位数相等时
  int one = 1;
  int zero = 0;
  for(int i = len-2; i >= 0 ; i --){
      if(digt[i]) {
        for(int k = i; k >= 0 && k+zero+1 >= i-k+one; k --){
          // 小于或等于
          num += c[i][k];
         // printf("k %d\n", k);
        }
          one ++;
      }
      else zero ++;
  }

  // printf("%d\n", num);
  return num;
}

int main()
{
  int st, ed;
  Com();
  while(scanf("%d%d", &st, &ed) != EOF){
    int ans = solve(ed+1) - solve(st);
   // if(isRound(st)) ans ++;
    printf("%d\n", ans);
  }
  return 0;
}

/*
1 000
1 001
1 010
1 011
1 100
1 101
1 110 15

1 111
*/
