/*
    ID: problem6
    PROG : A hard puzzle
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int modu = 10;

int power(int a, int n){
  if(n == 0) return 1;
  else {
    int ans = power(a, n/2);
    ans = (ans%modu)*(ans%modu);
    if(n % 2 == 1) ans = (ans*a%(modu))%modu;
    return ans%modu;
  }
}

int main(){
  int a, b;
  while(scanf("%d%d", &a, &b) != EOF){
    int ans = power(a, b);
    printf("%d\n", ans);
  }
  return 0;
}
