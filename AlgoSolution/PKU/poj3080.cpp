//  Accepted 136K 32MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char data[15][65];
int fail[65];
char temp[65];
char ans[65];

void get_fail(char *data, int n){
  int j = -1;
  fail[0] = -1;
  for(int i = 1; i < n; i ++){
    while(j != -1 && data[i] != data[j+1])
      j = fail[j];
    if(data[j+1] == data[i]) j ++;
    fail[i] = j;
  }
}

bool kmp(char *s, char *T){
  int n = strlen(T);
  int m = strlen(s);
  int j = -1;
  for(int i = 0; i < n; i ++){
    while(j > -1 && s[j+1] != T[i])
      j = fail[j];
      if(s[j+1] == T[i]) j ++;
      if(j == m-1) return true;
  }
  return false;
}

bool check(char *s, int num){
  for(int i = 1; i < num; i ++){
      if(kmp(s, data[i]) == 0)
        return false;
  }
  return true;
}

int main(){
  int m, T;
  scanf("%d", &T);
  while(T --){
    memset(data, 0, sizeof(data));
    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
     scanf("%s", &data[i]);
    }
    int len = strlen(data[0]);
    // 枚举子串
    int L = 0;
    for(int i = 1; i <= len; i ++){
      for(int j = 0; j < len-i+1; j ++){
          memset(temp, 0, sizeof(temp));
          // 对于字符复制的还是要清零为妙，好习惯
          strncpy(temp, data[0]+j, i); // 复制i个字符过去
          // printf("%s\n", temp);
          memset(fail, 0, sizeof(fail));
          get_fail(temp, i);
          if(check(temp, m)){
            if(i >= L){
              if(i > L) { strcpy(ans, temp); L = i; }
              else if(i == L && strcmp(ans , temp) > 0) strcpy(ans, temp);
            }
          }
      }
    }
    if(L < 3) printf("no significant commonalities\n");
    else printf("%s\n", ans);
 }
  return 0;
}
