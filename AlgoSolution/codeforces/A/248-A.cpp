#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int w[maxn];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int sum = 0;
    int num1 , num2;
    num1 = num2 = 0;
   for(int i = 0; i < n; i ++){
    scanf("%d", &w[i]);
    sum += w[i];
    if(w[i] == 100) num1 ++;
    else num2 ++;
   }
   if(num1 % 2 != 0) cout << "NO" << endl;
   else if(num1 == 0 && num2 % 2 == 1) cout << "NO" << endl;
   else cout << "YES" << endl;
  }
  return 0;
}
