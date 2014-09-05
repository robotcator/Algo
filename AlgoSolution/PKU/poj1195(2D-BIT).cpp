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

const int maxn = 1025+10;

int data[maxn][maxn];
int n;

int lowbit(int x){
  return x&(-x);
}

int sum(int x, int y){
  int ans = 0;
  for(int i = x; i > 0 ; i -= lowbit(i)){
    for(int j = y; j > 0; j -= lowbit(j)){
      ans += data[i][j];
    }
  }
  return ans;
}

void add(int x, int y, int val){
  for(int i = x; i <= n; i += lowbit(i)){
    for(int j = y; j <= n; j += lowbit(j)){
      data[i][j] += val;
    }
  }
}

int main(){
  int comm, x1, y1, x2, y2, z;
  while(true){
    scanf("%d", &comm);
    if(comm == 3) break;
    else if(comm == 0) {
      scanf("%d", &n);
      memset(data, 0, sizeof(data));}
    else if(comm == 1) {
      scanf("%d%d%d", &x1, &y1, &z);
      x1 ++; y1 ++;
      add(x1, y1, z);
    }else if(comm == 2){
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1 ++; y1 ++;
      x2 ++; y2 ++;
      int ans = sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
