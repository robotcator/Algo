// 6712594 	May 26, 2014 4:52:02 AM 	robotcator
// 426A - Sereja and Mugs 	GNU C++0x 	Accepted 	15 ms 	0 KB
// 争取不调试救过
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, s, x;
  while(scanf("%d%d", &n, &s) != EOF){
    int sum, maxn;
    sum = maxn = 0;
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      if(x > maxn) maxn = x;
      sum += x;
    }
    if(sum-maxn <= s) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
