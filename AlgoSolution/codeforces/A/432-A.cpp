/*
注意：题意是指要所选的队伍至少要能参加K次比赛
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    int x, cnt;
    cnt = 0;
    for(int i = 0; i < n; i ++){
     scanf("%d", &x);
     if(5-x >= k) cnt ++;
    }
    printf("%d\n", cnt/3);
  }
  return 0;
}
