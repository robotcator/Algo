#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int sg[1005];
int vis[1005];

int main()
{
  int n;
  sg[1] = 1;
  sg[2] = 1;
  for(int i = 3; i <= 1000; i ++){
    memset(vis, 0, sizeof(vis));
    for(int j = 1; j <= i; j *= 2){
        vis[sg[i-j]] = 1;
        // i-j为后继状态，vis[sg[i-j]]收录S集合
    }
    for(int j = 0; ; j ++){
      if(vis[j] == 0){
        sg[i] = j; break;
        // 求没有出现在集合中的非负最小值
      }
    }
    //cout << sg[i] << endl;
  }
  // for(int i = 1; i <= 100; i ++)
 //   cout << sg[i] << endl;
  while(scanf("%d", &n) != EOF){
    if(sg[n] == 0) printf("Cici\n");
    else printf("Kiki\n");
  }
  return 0;
}
