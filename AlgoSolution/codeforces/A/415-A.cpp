// robotcator 	415A - Mashmokh and Lights 	GNU C++0x 	Accepted 	15 ms 	0 KB
// 没有调试，但是话了比较久理解题意
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, m;
  int vis[100+10], index[100+10];
  while(scanf("%d%d", &n, &m) != EOF){
    memset(index, 0, sizeof(index));
    memset(vis, 0, sizeof(vis));
    int x;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &x);
      for(int j = x; j <= n; j ++)
        if(vis[j] == 0) vis[j] = x;
    }
    for(int i = 1; i <= n; i ++){
      printf("%d", vis[i]);
      if(i != n) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
