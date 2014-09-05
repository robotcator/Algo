// 有时转换为字符更好处理
// sprintf可以将数字转化为字符串
// sscanf 不能用错了
// Accepted 2328K 188MS
#include <cstdio>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

LL s[100005];
LL len[100005];

void table()
{
  s[1] = 1; len[1] = 1;
  int num = 1;
  LL pow = 10;
  for(int k = 2; k < 100005; k ++){
    if(k % pow == 0) { num ++; pow *= 10; }
    s[k] = s[k-1] + num ;
    len[k] = len[k-1] + s[k];
  }
 // for(int i = 1; i <= 100000; i ++)
 // cout << len[i] << endl;
}

void solve(int n)
{
  int i ;
  for(i = 1; len[i] - n < 0; i ++) ;
  //printf("%d\n", s[i]);
  int pos = n - len[i-1];
  // printf("%d\n", pos);
  char temp[100005];
  int num = 0;
  for(int i = 1; ; i ++){
    sprintf(temp, "%d", i);
    int len = strlen(temp);
  // printf("%s\n", temp);
  //  num += strlen(&(temp[num]));
    if(pos - len <= 0) break;
    pos -= len;
  //  printf("%d\n", num);
  }
  // for(int i = 0; i < pos; i ++)
  //  printf("%d %c\n", i, temp[i]);
  printf("%c\n", temp[pos-1]);
}

int main()
{
  int T;
  table();
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    solve(n);
  }
  return 0;
}
