/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
  char data[15];
  while(scanf("%s", data) != EOF){
    int len = strlen(data);
    int flag = 0;
    long long res = 0;
    long long pow = 1;
    for(int i = 0; i < len; i ++){
        if(i < len-1 && data[i] < data[i-1]) { flag = 1; break; }
        // cout << res << " " << pow <<endl;
        res = res*pow + (data[i]-'a'+1);
        // cout << res << " " << pow <<endl;
        pow *= 26;
    }
    // cout << res << endl;
    int num = 0;
    for(int i = len-2; i >= 0; i --){
      num = num + (data[i]-'a'+1+1)*(data[i]-'a'+1)/2;
      // cout << num << endl;
    }
    if(flag == 0)
    cout << res-num << endl;
    else cout << "0" << endl;
  }
  return 0;
}
*/
// 172K 0MS
// Accepted 176K 32MS 要注意浮点数误差
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
long long c[30][30];
// double c[30][30];
double calcu(int n, int m){
  if(m > n/2) m = n-m;
  if(n < m) return 0;
  else {
    double s1, s2;
    s1 = s2 = 0;
    for(int i = m+1; i <= n; i ++)
      s1 += log(double(i));
    for(int i = 2; i <= n-m; i ++)
      s2 += log(double(i));
    return  exp(s1-s2);
  }
}

void table()
{
  memset(c, 0, sizeof(c));
  c[1][0] = c[1][1] = 1;
  //cout << calcu(3,1) << endl;
  for(int i = 2; i <= 26; i ++){
    for(int j = 0; j <= i; j ++){
     if(j == 0 || i == j)  c[i][j] = 1;
     else c[i][j] = (long long)(calcu(i, j)+0.5);
     // 要避免浮点数误差
    // printf("%d %d %lf\n", i, j, c[i][j]);
    }
  }
  // return ;
  // for(int i = 1; i <= 26; i ++){
  //  for(int j = 0; j <= i; j ++)
  //    printf("%d ", c[i][j]);
  //  printf("\n");
  // }

}
/*
void table()
{
  memset(c, 0, sizeof(c));
  c[1][0] = c[1][1] = 1;
  for(int i = 2; i <= 26; i ++){
    for(int j = 0; j <= i; j ++){
      if(j == 0 || i == j) c[i][j] = 1;
      else c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
  }

   for(int i = 1; i <= 26; i ++){
    for(int j = 0; j <= i; j ++)
      printf("%d ", c[i][j]);
    printf("\n");
   }
}
*/
int main()
{
  char data[15];
  table();
  while(scanf("%s", data) != EOF){
    int len = strlen(data);
    int flag = 0;
    for(int i = 1; i < len; i ++){
      if(data[i] < data[i-1]) {flag = 1; break;}
    }
    if(flag == 0){
      int res = 0;
      for(int i = 1; i < len; i ++) res += c[26][i];
      for(int i = 0; i < len; i ++){
          char ch = i == 0 ? 'a' : data[i-1]+1;
          while(ch < data[i]){
            res += c['z'-ch][len-i-1];
            // ÕâÀï
            ch ++;
          }

      }
      printf("%d\n", res+1);
    }
    else printf("%d\n", 0);
  }
  return 0;
}
