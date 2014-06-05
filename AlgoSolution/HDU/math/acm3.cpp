// Accepted	660 MS	2452 KB
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100000+10;
int data[maxn];
int cnt[maxn];

int cmp(int a, int b){
  return a > b;
}
int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
      cnt[data[i]] ++;
    }
    long long res = (long long)(n)*(long long)(n-1)/2;
    for(int i = 1; i <= 100000; i ++){
      if(cnt[i] == 0) continue;
      res -= (cnt[i])*(cnt[i]-1)/2;
      for(int j = i+i; j <= 100000; j += i)
        res -= (cnt[i])*(cnt[j]);
    }
    cout << res << endl;
//    暴力
//    int cnt = 0;
//    for(int i = 0; i < n; i ++){
//      for(int j = i+1; j < n; j ++){
//        if(i == j) continue;
//        if(data[i] > data[j] && data[i] % data[j] != 0) cnt ++;
//        else if (data[i] < data[j] && data[j] % data[i] != 0) cnt ++;
//      }
//    }
//    cout << cnt << endl;
  }
  return 0;
}
