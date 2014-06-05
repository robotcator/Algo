#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[1005];
struct Node{
 int a, b;
};
Node node[1005];

int cmp(Node x, Node y){
  if(x.b != y.b) return x.b < y.b;
  else return x.a > y.a;
}

int main()
{
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    int suma, sumb;
    suma = sumb = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d%d", &node[i].a, &node[i].b);
      suma += node[i].a;
      sumb += node[i].b;
    }

    for(int i = 1; i <= n; i++){

    }
    int sum = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i ++){
      if(sum+node[i].a-node[i].b > sum){
        sum = sum+node[i].a-node[i].b;
        for(int j = 1; j <= n; j ++){
          node[j].a -= node[i].b;
        }
      }
    }
    cout << sum << endl;

  }
  return 0;
}
