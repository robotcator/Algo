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

int maxn = 100000+10;

int main(){
  long long n, x, y;
  cin >> n >> x >> y ;
  int a[maxn];
  for(int i = 0; i < n; i ++){
    a[i] = 1;
  }
  if(y >= n){
    a[0] += y-n;
    for(int i = 0; i < n; i ++){
      x -= (long long)a[0]*a[0];
    }
    if(x <= 0){
      for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
      }
      cout << endl;
    }else{
      cout << -1 << endl;
    }
  }else{
    cout << -1 << endl;
  }
  return 0;
}
