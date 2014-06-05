#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 100000+10;
int n, m;
int vis[maxn], mark[maxn], leader[maxn];


int main()
{
  int id;
  char op[2];
  while(scanf("%d %d", &n, &m) != EOF){
    int num = 0;
    memset(mark, 0, sizeof(mark));
    memset(vis, 0, sizeof(vis));
    int flag = 0;
    for(int i = 0; i < m; i ++){
      scanf("%s%d", op, &id);
      vis[id] = 1;
      if(strcmp(op, "+") == 0){
          num ++;
          mark[id] = 1;
      }
      else{
          mark[id] = 0;
          num --;
      }
      //for(int i = 0; i < m; i ++)
      //  printf("%d ", mark[i]);
      //cout << endl;
      if(num >= 1) {
        flag = 1; // 出现两个人的时候
        for(int i = 0; i < n; i ++){
            leader[i] = mark[i];
        }
      }
     // for(int i = 0; i < n; i ++){
     //   printf("%d ", leader[i]);
     // }
     // printf("\n");
    }
    for(int i = 1; i <= n; i ++){
      if(vis[i] == 0) printf("%d ", i);
      else if(flag == 1){
        if(mark[i] == 1) printf("%d ", i);
      }
    }
  }
  return 0;
}
