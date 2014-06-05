// 5028K 172MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1000000+10;
char data[maxn];
int fail[maxn];

void get_fail(char *s){
  int len = strlen(s);
  fail[0] = -1;
  int j = -1;
  for(int i = 1; i < len; i ++){
    while(j > -1 && s[j+1] != s[i]) j = fail[j];
    if(s[j+1] == s[i]) j ++;
    fail[i] = j;
  }
  //for(int i = 0; i < len; i ++)
  //  cout << fail[i] << " ";
  //cout << endl;
}

bool kmp(char *s, char *T){
  int n = strlen(T);
  int m = strlen(s);
  int j = -1;
  int cnt = 0;
  for(int i = 0; i < n; i ++){
    while(j > -1 && s[j+1] != T[i]) j = fail[j];
    if(s[j+1] == T[i]) j ++;
    if(j == m-1){
      j = fail[j];
      cnt ++;
    }
  }
  if(cnt == n/m) return true;
  else return false;
}

int main(){
  while(scanf("%s", data) != EOF){
    if(strcmp(data, ".") == 0) break;
    memset(fail, 0, sizeof(fail));
    int len = strlen(data);
    get_fail(data);
    if(len % (len-1-fail[len-1]) == 0)
      printf("%d\n", len/(len-1-fail[len-1]));
    else printf("1\n");
    // len - 1 - fail[len-1] 的长度即为string a的长度
    /*
    char temp[maxn];
    int ans = 0;
    for(int i = 1; i <= len; i ++){
      memset(temp, 0, sizeof(temp));
      if(len % i != 0) continue;
      strncpy(temp, data, i);
      if(kmp(temp, data)){
        ans = i; break;
      }
    }
    printf("%d\n", ans/len);
    */
  }
  return 0;
}
