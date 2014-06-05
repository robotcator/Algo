/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int modu = 1000000007;
const int maxn = 100000+10;
long long a[maxn];

int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++){
      cin >> a[i];
    }
    for(int i = 0; i < m; i ++){
      scanf("%d%d", &l, &r);
      int f1 = a[l];
      int f2 = a[l+1];

    }
  }
  return 0;
}
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 20000;
int sum[maxn];
int n;

void table(){
  sum[0] = 0;
  for(int i = 1; i < maxn; i ++){
    sum[i] = sum[i-1] + i;
  }
}

int main(){
  int t;
  table();
  scanf("%d", &t);
  /*
  for(int i = 0; i < maxn; i ++){
    cout << sum[i] << endl;
  }
  */
  /*
  while(t --){
    cin >> n;
    while(n > 0){
      int x = upper_bound(sum, sum+maxn, n)-sum;
      //cout << sum[x-1] << endl;
      cout << x-1 << " ";
      n -= sum[x-1];
    }
    cout << endl;
  }
  */
  while(t--){
    scanf("%d", &n);
    int x = upper_bound(sum, sum+maxn, n)-sum;
    for(int j = 0; j < 3; j ++){
      if(j == 0){
        if(n - sum[x-1] == 0) {
          printf("%d\n", x-1);
        }
      }
      else if(j == 1){
        int a, b;
        for(int i = x; i >= 1; i --){
           int b = n-sum[i-1];
           int y = upper_bound(sum, sum+maxn, b)-sum;
           if(b-sum[y-1] == 0) {
              printf("%d %d\n", i-1 , y-1);
              break;
           }
        }
      }
      else if(j == 2){

      }
    }
  }
  return 0;
}
