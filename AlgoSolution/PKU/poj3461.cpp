// Accepted 1220K 94MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void getFail(char *p, int *f){
  int len = strlen(p);
  int j = -1; f[0] = -1;
  for(int i = 1; i < len; i ++){
    while(j > -1 && p[i] != p[j+1]) j = f[j];
    if(p[j+1] == p[i]) j ++;
    f[i] = j;
  }
  /*
  for(int i = 0; i < len; i ++)
    printf("%d\n", f[i]);
  */
}

void match(char *T, char *p, int *f){
  int len = strlen(T);
  int m = strlen(p);
  int j = -1, cnt = 0;
  for(int i = 0; i < len; i ++){
    while(j > -1 && T[i] != p[j+1]) j = f[j];
    if(p[j+1] == T[i]) j ++;
    if(j == m-1) {
        cnt ++;
        j = f[j];
        // return i-m+1;
        // ∑µªÿ∆•≈‰Œª÷√
    }
  }
  cout << cnt << endl;
}

int main()
{
  int t;
  char data[10005], T[1000005];
  int f[10005];
  scanf("%d", &t);
  while(t--){
    scanf("%s", data);
    scanf("%s", T);
    getFail(data, f);
    match(T, data, f);
  }
  return 0;
}
