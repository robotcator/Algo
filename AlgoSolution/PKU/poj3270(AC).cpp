//Accepted 1024K 0MS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int cmp(int a, int b) { return a < b; }
int minx(int a, int b) { return a < b ? a : b; }

int main()
{
  int n, flag ;
  int cow[10005];
  int id[100005];
  int End[10005];
  int vis[100005];
  // 用于记录是否在同一个等价类中
  while(scanf("%d", &n) != EOF){
    int minn = inf;
    // 记录全局最小值
    int sum = 0;
    // 记录代价
    for(int i = 1; i <= n; i ++){
      scanf("%d", &cow[i]);
      id[cow[i]] = i;
      // 记录每个脾气对应的
      //Each cow has a unique "grumpiness" level
      End[i] = cow[i];
      // 末态
      sum += cow[i];
      if(cow[i] < minn) minn = cow[i];
    }
    sort(End+1, End+n+1, cmp);
    // 注意元素开始位置和结束位置后一位
    flag = 1;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
      int temp = cow[i];
      if(vis[temp] == 0){
        int num = 0;
        // 循环中元素个数
        int tempmin = inf;
        if(temp < tempmin) tempmin = temp;
        num ++;
        vis[temp] = flag ;
        temp = End[id[temp]];
        while(vis[temp] == 0 && temp != cow[i]){
          //vis判断可有可无
          if(temp < tempmin) tempmin = temp;
          num ++;
          vis[temp] = flag;
          temp = End[id[temp]];
        }
        flag ++;
       // printf("~%d %d\n", num, tempmin);
        sum = sum + minx((num-2)*tempmin , minn*(num+1)+tempmin);
      }
    }
    printf("%d\n", sum);

  //  for(int i = 0; i < 10; i ++)
  //    printf("%d %d\n", i, vis[i]);

  }
  return 0;
}
