#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int Uset[50005];

int main()
{
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    int cnt = 0;
    int d, x, y;
    for(int i = 1; i <= n; i ++) Uset[i] = i;
    for(int i = 0; i < n; i ++){
      scanf("%d%d%d", &d, &x, &y);
      if(x > n || y > n) cnt ++;
      else if(d == 2 && (x == y)) cnt ++;
      else {

      }
    }

  }
  return 0;
}
