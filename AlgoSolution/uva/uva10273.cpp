/*
    ID: problem6
    PROG : Eat or not to Eat?
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

const int maxn = 1000+50;

int T[maxn];
int M[maxn][25];
int kill[maxn];

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
  return a*b/gcd(a, b);
}

int get_lcm(int *a, int n){
  int ans = 1;
  for(int i = 0; i < n; i ++){
    if(kill[i] == 0) ans = lcm(ans, a[i]);
  }
  return ans;
}

int check(int k, int n){
  int cnt[255];
  //cout << "k" << k << endl;
  memset(cnt, 0, sizeof(cnt));
  int j = 0;
  int ans, minn, num;
  minn = 260;
  for(int i = 0; i < n; i ++){
    if(kill[i] == 0){
      cnt[j] = M[i][(k-1)%T[i]];
     // cout<< cnt[j] << endl;
      if(cnt[j] < minn) {
        minn = cnt[j];
        ans = i;
      }
      j ++;
    }
  }
  num = 0;
  for(int i = 0; i < j; i ++){
    if(cnt[i] == minn) num ++;
  }
  if(num <= 1) return ans;
  else return -1;
}

int main(){
  int t, n;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
      scanf("%d", &T[i]);
      for(int j = 0; j < T[i]; j ++)
        scanf("%d", &M[i][j]);
    }
    memset(kill, 0, sizeof(kill));
    int num = 0;
    int last = 0;
    int st, ed;
    st = 1;
    while(true){
      int L = get_lcm(T, n);
     // cout << L << endl;
      ed = st + L-1;
      int ok = 0;
      for(int i = st; i <= ed; i ++){
        int k = check(i, n);
       // cout << k << endl;
       // cout << endl;
        if(k > -1){
          kill[k] = ++num ;
          last = i;
          ok = 1;
        }
      }
      st = ed+1;
      if(ok == 0 || num >= n) break;
    }
    printf("%d %d\n", n-num, last);
  }
  return 0;
}
