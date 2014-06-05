/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void solve(int w[][175], double a[][175], double b[][175], int n){
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      a[i][j] = (w[i][j]+w[j][i])/2.0;
      b[i][j] = (w[i][j]-w[j][i])/2.0;
    }
  }
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      printf("%.8lf ", a[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      printf("%.8lf ", b[i][j]);
    }
    printf("\n");
  }

}

int main()
{
  int n;
  int w[175][175];
  double a[175][175];
  double b[175][175];
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++){
        scanf("%d", &w[i][j]);
      }
    }
    solve(w, a, b, n);
  }
  return 0;
}
*/
/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int minn(int a, int b) { return a < b ? a : b; }

int check(int ans, int n, int i, int e, int t) {
  if(ans*3 <= e && ans <= i && ans <= t && n >= 2*ans+1) return 1;
  else return 0;
}

int main()
{
  char data[105];
  int t, n, i, e;
  while(scanf("%s", data) != EOF){
    t = n = i = e = 0;
    for(int j = 0; j < (int)strlen(data); j ++){
      if(data[j] == 'n') n ++;
      else if(data[j] == 'i') i ++;
      else if(data[j] == 'e') e ++;
      else if(data[j] == 't') t ++;
    }
    //printf("%d %d %d %d\n", n, i, e, t);
    int ans = minn(i, t);
    while(!check(ans, n, i, e, t)) ans --;
    if(ans < 0 ) printf("%d\n", 0);
    else printf("%d\n", ans);
  }
  return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100005;
int prime[maxn];

void table(){
  memset(prime, 0, sizeof(prime));
  for(int i = 2; i < maxn; i ++) {
    if(prime[i] == 0)
    for(int j = 2; j*i < maxn; j ++){
      prime[j*i] = 1;
    }
  }
   //for(int i = 2; i < 100; i ++)
  //   if(prime[i] == 0) cout << i << endl;
}

int is_palind(char* data, int st, int ed){
  int len = (st+ed);
  for(int i = st; i <= len/2; i ++){
    if(data[i] != data[len-i]) return 0;
  }
  return 1;
}

int main()
{
  int T;
  table();
  scanf("%d", &T);
  char data[100005];
  while(T--){
    scanf("%s", data);
    int len = strlen(data);
    int num = 0;
    for(int i = 2; i < len; i ++){
      if(prime[i] == 0){
        for(int j = 0; j < len-i; j ++){
          if(is_palind(data, j, j+i-1) == 1){
            num ++;
          }
        }
      }
    }
    cout << num << endl;
  }
  return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int check(int *cnt, int mid, int k, int maxn, int n) {
  int sum = 0;
  for(int i = 0; i < n; i ++){
    if(cnt[i] < k) sum += cnt[i];
  }

}

int main()
{
  int t, k, l;
  int cnt[30];
  char data[1000005];
  scanf("%d", &t);
  while(t--){
    scanf("%s", data);
    scanf("%d%d", &k, &l);
    int n = strlen(data);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i ++){
      cnt[data[i]-'a'] ++;

    }
    int maxn = 0;
    for(int i = 0; i < 26; i ++)
      if(cnt[i] > maxn) maxn = cnt[i];
    if(n-maxn+1 >= k) cout << k << endl;
    else {
      int low = l, high = n;
      int mid;
      while(low <= high){
        int mid = (low+high)/2;
        if(check(cnt, mid, k, maxn, n) > 0) high = mid-1;
        else low = mid+1;
      }
    }

  }
  return 0;
}
