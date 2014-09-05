/*
    ID: problem6
    PROG : Exclusive or
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  for(int i = 2; i <= 30; i ++){
    int ans = 0;
    for(int j = 1; j < i; j ++){
    //if(j == 2) cout << j << " " << i-j << " " << (j^(i-j)) << endl;
      ans += j ^ (i-j);
    }
   // cout <<  "n" << i << " " << ans << endl;
    cout << ans << " ";
  }
  cout << endl;
    return 0;
}
