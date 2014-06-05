#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Point{
 int x, y;
};

int cmp(Point a, Point b) {
  if(a.y == b.y) return a.x < b.x;
  else return a.y < b.y;
}

int main()
{
  Point p[15005];
  int n;
  for(int i = 0; i < 100; i ++){
      int n = rand()%14900;
      n ++;
      printf("%d\n", n);
      for(int j = 0; j < n; j ++){
         p[j].x = rand()%32000;
         p[j].y = rand()%32000;
      }
      sort(p, p+n, cmp);
      for(int j = 0; j < n; j ++)
        printf("%d %d\n", p[j].x, p[j].y);
  return 0;
  }
  return 0;
}
