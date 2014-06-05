// robotcator 	401A - Vanya and Cards 	GNU C++0x 	Accepted 	15 ms 	0 KB
// 还是不行
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, x;
  while(scanf("%d%d", &n, &x) != EOF){
    int y, cnt;
    int sum = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d", &y);
      sum += y;
    }
    sum = abs(sum);
    printf("%d\n", sum%x == 0 ? sum/x : sum/x + 1);
  }
  return 0;
}
