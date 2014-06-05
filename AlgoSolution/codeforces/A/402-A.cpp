// 402A - Nuts 	GNU C++0x 	Accepted 	15 ms 	0 KB
// 多做此类题，提高思维的缜密性
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int k, a, b, v;
  while(scanf("%d%d%d%d", &k, &a, &b, &v) != EOF){
   int x = b%(k-1);
   int y = b/(k-1);
   int left1, left2;
   if(y*k*v >= a) {
     if(a%(k*v) == 0) printf("%d\n", a/(k*v));
     else printf("%d\n", a/(k*v)+1);
   }
   else {
     left1 = a-(y*k*v);
     if(left1 <= (x+1)*v && x != 0) printf("%d\n", y+1);
     else {
      left2 = left1 - (x+1)*v;
      if(left2 % v == 0) printf("%d\n", y+1+left2/v);
      else printf("%d\n", y+2+left2/v);
     }
   }
  }
  return 0;
}
