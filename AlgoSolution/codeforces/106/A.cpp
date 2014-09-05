/*
    ID: problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 15;
int T[maxn];

int cmp(int a, int b){
  return a > b ;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= 12; i ++){
      scanf("%d", &T[i]);
    }
    sort(T+1, T+13, cmp);
    int sum = 0;
    int i;
    for(i = 1; i <= 12; i ++){
      if(sum + T[i] >= n) { break; }
      else sum += T[i];
    }
    if(i > 12) printf("-1\n");
    else if(n == 0) printf("0\n");
    else printf("%d\n", i);
  }
  return 0;
}
