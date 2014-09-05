/*
    ID: problem6
    PROG : Leftmost Digit
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    double sum = n*log10((double)n);
    sum = sum - floor(sum);
    double temp = pow(10.0, sum);
    printf("%.0f\n", floor(temp));
  }
  return 0;
}
