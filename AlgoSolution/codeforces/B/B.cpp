/*
    ID : problem6
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

const int maxn = 200000+10;
long long b[maxn];

int main(){
  int n;
  scanf("%d", &n);
  long long maxn, minn;
  maxn = 0;
  minn = (long long)(1e11);
  for(int i = 0; i < n; i ++){
    scanf("%d", &b[i]);
    if(b[i] > maxn) maxn = b[i];
    if(b[i] < minn) minn = b[i];
  }
  long long cnt1, cnt2;
  cnt1 = cnt2 = 0;
  for(int i = 0; i < n; i ++){
    if(b[i] == maxn) cnt1 ++;
    if(b[i] == minn) cnt2 ++;
  }
  if(maxn != minn)
    cout << maxn-minn << " " << (long long)cnt1*cnt2 << endl;
  else if(cnt1 == 2) cout << 0 << " " << 1 << endl;
  else cout << 0 << " " << cnt1*(cnt2-1)/2 << endl;
  // c(n, 2)
  return 0;
}
