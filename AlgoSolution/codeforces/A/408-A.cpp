// robotcator 	408A - Line to Cashier 	GNU C++0x 	Accepted 	15 ms 	100 KB
// 未调试
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
const int inf = 0x3f3f3f3f;
int peo[maxn];
int pro[maxn][maxn];

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++)
      scanf("%d", &peo[i]);
    for(int i = 0; i < n; i ++)
      for(int j = 0; j < peo[i]; j ++)
      scanf("%d", &pro[i][j]);
    int minn = inf;
    for(int i = 0; i < n; i ++){
        int time = 0;
        for(int j = 0; j < peo[i]; j ++){
          time += pro[i][j]*5;
          time += 15;
        }
        if(time < minn) minn = time;
    }
    cout << minn << endl;
  }
  return 0;
}
