// Accepted 328K 157MS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int check(int *rock, int n, int mid, int m) {
  int num, sum;
  num = sum = 0;
  for(int i = 1; i <= n; i ++){
    if(sum+(rock[i]-rock[i-1]) <= mid){
      sum += rock[i]-rock[i-1];
      num ++;
    }
    // 注意check函数每次都写错
    else if(sum+(rock[i]-rock[i-1]) > mid) {
      sum = 0;
      //num ++;
    }
  }
  if(num <= m) return 1;
  else return 0;
}

int solve(int *rock, int n, int L, int m) {
  int minn;
  //int maxn;
  minn = L+1;
  // maxn = 0;
  for(int i = 1; i <= n; i ++){
    if(rock[i]-rock[i-1] < minn)
      minn = rock[i]-rock[i-1];
    //if(rock[i]-rock[i-1] > maxn)
    //  maxn = rock[i]-rock[i-1];
  }
  // cout << minn << endl;
  int l = minn, r = L;
  int mid;
  while(l <= r) {
    mid = (l+r)/2;
    if(check(rock, n, mid, m)) l = mid+1;
    // 移除的石头过多,即跳跃距离过大
    else r = mid-1;
  }
  //printf("%d %d %d \n", l, mid, r);
  return l;
}

int main()
{
  int l, n, m;
  int rock[50005];
  while(scanf("%d%d%d", &l, &n, &m) != EOF){
    rock[0] = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &rock[i]);
    }
    rock[++n] = l;
    sort(rock, rock+n);
    int ans = solve(rock, n, l, m);
    printf("%d\n", ans);
  }
  return 0;
}
