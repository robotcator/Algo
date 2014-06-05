// robotcator 	405A - Gravity Flip 	GNU C++0x 	Accepted 	15 ms 	0 KB
// 没有调试，题意也很简单
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int a[100+10];
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++)
      scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i = 0; i < n; i ++){
        printf("%d", a[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
