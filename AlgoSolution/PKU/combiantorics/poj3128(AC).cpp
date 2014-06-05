// Accepted 164K 16MS
// 置换T^2，如果置换长度为n && gcd(n, 2) == 1
// 则T^2长度仍然为n
// 若置换长度n 满足2 | n,则T^2分裂为 2个长度为
// n/2的循环的并
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
  int t;
  int vis[30];
  int cnt[30];
  //  统计循环个数为i的循环个数
  char B[30];
  scanf("%d", &t);
  while(t--){
    scanf("%s", B);
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < 26; i ++){
      if(vis[i] == 0){
        vis[i] = 1;
        int temp = B[i] - 'A';
        int num = 1;
        while(temp >= 0 && temp != i){
          vis[temp] = 1;
          temp = B[temp] - 'A';
          num ++;
        }
        cnt[num] ++;
      }
    }
    int ok = 1;
    for(int i = 2; i <= 26; i += 2)
      if(cnt[i] % 2 == 1) ok = 0;
    if(ok == 1) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
