#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long ULL;

int main(){
  int k;
  while(scanf("%d", &k) != EOF){
    ULL f1, f2;
    f1 = f2 = 1;
    for(int i = 2; i <= k+2; i ++){
      f2 = f1 + f2;
      f1 = f2 - f1;
    }
    cout << f1-1 << endl;
  }
  return 0;
}
/*
1561429	12.05.14 18:54	robotcator	123 	.CPP	Accepted 	15 ms	58 kb
*/
