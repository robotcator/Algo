//Accepted 168K 204MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void getCircle(int *code, int n, int *vis)
{
  for(int i = 1; i <= n; i ++){
    int temp = code[i];
    int flag = 1;
    while(i != temp){
      flag ++;
      temp = code[temp];
    }
    vis[i] = flag;
  }
 // for(int i = 1; i <= n; i ++)
 //   printf("%d %d\n", i, vis[i]);
}

int main()
{
  int n, k;
  int code[205];
  int vis[205];
  char data[205];
  char encode[205];
  while(scanf("%d", &n) , n){
    for(int i = 1; i <= n; i ++)
      scanf("%d", &code[i]);
    while(scanf("%d", &k), k){
      getchar();
      gets(data+1);
     // printf("%d\n", (int)strlen(data+1));
      for(int i = strlen(data+1)+1; i <= n; i ++)
        data[i] = ' ';
      data[n+1] = '\0';
      // 补全空格
      memset(vis, 0, sizeof(vis));
      getCircle(code, n, vis);
      // 计算每个循环节的个数
      for(int i = 1; i <= n; i ++){
        int pos = i;
        for(int j = 1; j <= k%vis[i]; j ++){
            pos = code[pos];
        }
        encode[pos] = data[i];
        // 1 ---> 4
        // en[1] = H ---> de[4] = H
      }
      for(int i = 1; i <= n; i ++)
        printf("%c", encode[i]);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
