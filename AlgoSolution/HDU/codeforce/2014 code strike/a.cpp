#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100+10;
int n, a, b;
int a1[maxn], b1[maxn];

int main()
{
  while(scanf("%d%d%d", &n, &a, &b) != EOF){
    for(int i = 1; i <= a; i ++){
      scanf("%d", &a1[i]);
    }
    for(int i = 1; i <= b; i ++){
      scanf("%d", &b1[i]);
    }
    sort(a1, a1+a);
    sort(b1, b1+b);
    int j, k;
    j = k = 1;
    for(int i = 1; i <= n; i ++){
      if(a1[j] == i) {
          printf("1");
          j ++;
          if(b1[k] == i) k ++;
      }
      else if(b1[k] == i){
        printf("2");
        k ++;
      }
      if(i != n) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
