// 	robotcator 	404A - Valera and X 	GNU C++0x 	Accepted 	15 ms 	100 KB
// 要熟悉左对角线
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  char gaze[300+10][300+10];
  while(scanf("%d", &n) != EOF){
   for(int i = 0; i < n; i ++){
    scanf("%s", gaze[i]);
   }
   int flag1, flag2;
   flag1 = flag2 = 1;
   for(int i = 1; i < n; i ++){
    if(gaze[i][i] != gaze[0][0])  flag1 = 0;
    if(gaze[i][n-1-i] != gaze[0][n-1])  flag1 = 0;
   }
   for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      if(i == j || i == n-1-j) continue;
      if(gaze[i][j] != gaze[0][1]) flag2 = 0;
    }
   }
   //cout << flag1 << flag2 << endl;
   if(flag1 == 0 || flag2 == 0) printf("NO\n");
   else if(gaze[0][0] != gaze[0][1] && gaze[0][n-1] == gaze[0][0] && flag1 == 1
           && flag2 == 1)
    printf("YES\n");
   else printf("NO\n");
   // 要x的元素相，其他不同
  }
  return 0;
}
