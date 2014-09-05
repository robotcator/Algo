/*
    ID: problem6
    PROG : 最少拦截系统
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10000+10;
int data[maxn];
int dp[maxn];
int b[maxn];
int path[maxn];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++){
      scanf("%d", &data[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    b[0] = data[0];
    /*
    int j = 1;
    int size = 1;
    for(int i = 1; i < n; i ++){
      if(data[i] <= b[0]) {
        j = 0;
      }
      if(b[size-1] < data[i]) {
        j = size ++;
      }else{
        j = lower_bound(b, b+size, data[i]) - b;
      }
      b[j] = data[i];
      dp[i] = j + 1;
    }
    */
    for(int i = 1; i < n; i ++){
      for(int j = 0; j < i; j ++){

      }
    }
    cout << size << endl;
  }
  return 0;
}
