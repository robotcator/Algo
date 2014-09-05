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

const int maxn = 100000+10;
long long c[maxn];
int n, q;

int lowbit(int x) { return x&(-x); }

long long sum(int x){
  long long ans = 0;
  for(int i = x; i > 0; i -= lowbit(i)){
    ans += c[i];
  }
  return ans;
}

void add(int x, int val){
  for(int i = x; i <= n; i += lowbit(i)){
    c[i] += val;
  }
}

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a%b);
}

template <class T>
inline void Input(T &x){
  char c; x = 0;
  while((c = getchar()) < '0' || c > '9');
  while(c >= '0' && c <= '9') x = x*10 + (c-'0'), c = getchar();
}

int main(){
  int flag = 1;
  while(scanf("%d%d", &n, &q) != EOF){
    if(n == 0 && q == 0) break;
    memset(c, 0, sizeof(c));
    printf("Case #%d: \n", flag ++);
    int cc, x, d, v;
    for(int i = 0; i < q; i ++){
     // scanf("%d", &cc);
      Input(cc);
      if(cc == 1){
        Input(x); Input(d); Input(v);
        //scanf("%d%d%d", &x, &d, &v);
        x = x/d;
        for(int i = d; i <= n; i += d){
          if(gcd(i/d, x) == 1){
            add(i, v);
          }
        }

      }else{
        //scanf("%d", &x);
        Input(x);
        long long ans = sum(x);
        printf("%I64d\n", ans);
      }
    }
  }
  return 0;
}

/*
int main(){
  int h, a, b, k;
  int flag = 0;
  while(scanf("%d%d%d%d", &h, &a, &b, &k) != EOF){
    if(h == 0 && a == 0 && b == 0 && k == 0) break;
    printf("Case #%d: \n", flag++);
    if((long long)a*(long long)k - (long long)h < 1){
      printf("YES\n");
    }else {
      h = h - a*k + b;

    }
  }
  return 0;
}
*/
