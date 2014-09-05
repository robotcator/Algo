/*
// 能否算出最大范围和最小范围
// 但是如何确定能表示其中所有的数
// 如果遇到64还是用cin cout
// Time Limit Exceeded
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char data[65];
int res, k;
long long x;
char path[65];

void Reverse(char *data, int k)
{
  for(int i = 0; i < k/2; i ++){
    char temp = data[i];
    data[i] = data[k-i-1];
    data[k-i-1]  = temp;
  }
}

void print_path(int depth)
{
  for(int i = k-1; i >= depth; i --)
    printf("0");
  for(int i = depth-1; i >= 0; i --)
    printf("%c", path[i]);
  printf("\n");
}

void dfs(int depth, long long sum)
{
  if(sum == x) {
    res = 1;
    print_path(depth);
    return ;
    // 需要保存这个解
  }
  if(k == depth) {
      if(sum == x) res = 1;
      return;
  }
  if(data[depth] == 'p')
   {
     path[depth] = '1';
     dfs(depth+1, sum+1*1*(1 << depth));
     path[depth] = '0';
     dfs(depth+1, sum+1*0*(1 << depth));
   }
   else {
     path[depth] = '1';
     dfs(depth+1, sum+(-1)*1*(1 << depth));
     path[depth] = '0';
     dfs(depth+1, sum+(-1)*0*(1 << depth));
   }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &k);
    scanf("%s", data);
    cin >> x;
    Reverse(data, k);
    res = 0;
    memset(path, 0, sizeof(path));
    dfs(0, 0);
    if(res == 0) printf("Impossible\n");
  }
  return 0;
}
*/
// Accepted 248K 0MS
// 由于数的积偶性时由二进制
// 最后一位决定的
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int k;
char data[70];
long long x;

int main()
{
  int T;
  char ans[70];
  scanf("%d", &T);
  while(T--){
    scanf("%d", &k);
    scanf("%s", data);
    cin >> x;
    memset(ans, 0, sizeof(ans));
    for(int i = k-1; i >= 0; i --){
      if(x & 1){
        if(data[i] == 'n') x += 2;
        //由于-1，所以加上2
        ans[i] = '1';
      }
      else ans[i] = '0';
      x = x >> 1;
    }
    if(x == 0)
     printf("%s\n", ans);
    else printf("Impossible\n");
  }
  return 0;
}

/*
// 2^-63 --- 2^63-1
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int k;
char data[70];
long long x;

void calcu(char *data, long long &maxn, long long &minn, int pos){
  long long pow = 1;
  maxn = minn = 0;
  int len = strlen(data);
  // printf("%d\n", len);
  for(int i = pos; i < len && i < 63; i ++){
    if(data[i] == 'n') {
        minn = 2*minn-1;
        maxn *= 2;
    }
    if(data[i] == 'p') {
        minn *= 2;
        maxn = 2*maxn+1;
    }
  }
  //cout << minn << " " << maxn << endl;
}

void solve(char *data, long long x){
  char ans[70];
  memset(ans, 0, sizeof(ans));
  long long maxn, minn;
  int len = strlen(data);
  for(int i = 0; i < len; i ++){
    if(data[i] == 'p'){
      calcu(data, maxn, minn, i+1);
      // printf("%d\n", len-1);
      //cout << maxn << " " << minn << endl;
      long long pow = 1 << (len-1-i);
      if(x-pow >= minn && x-pow <= maxn){
         ans[i] = '1';
      //   printf("%d\n", x);
         x -= pow;
      }
      else ans[i] = '0';
    }
    else {
      // printf("n\n");
      calcu(data, maxn, minn, i+1);
      long long pow = 1 << (len-1-i);
      if(x+pow >= minn && x+pow <= maxn){
        ans[i] = '1';
        x += pow;
      }
      else ans[i] = '0';
    }
  }
  ans[len] = '\0';
  printf("%s\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &k);
    scanf("%s", data);
    cin >> x;
    long long maxn, minn;
    calcu(data, maxn, minn, 0);
    if((x > maxn && maxn >=0) || (x < minn && minn <= 0))
      printf("Impossible\n");
    else {
      solve(data, x);
    }
  }
  return 0;
}
*/
