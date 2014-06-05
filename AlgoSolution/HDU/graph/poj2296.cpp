#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100;

struct node{
  int x, y;
}city [maxn];

int main()
{
  int t, m;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
      scanf("%d%d", &city[i].x, &city[i].y);
    }
  }
  return 0;
}
