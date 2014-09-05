/*
    ID: problem6
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

int get_number(char ch){
  if(ch >= '0' && ch <= '9') return ch-'0';
  else return ch-'A'+10;
}

int main(){
  char data[20], a[10], b[10];
  while(scanf("%s", data) != EOF){
    int i , j;
    int pos = 0;
    for(i = 0; i < strlen(data); i ++)
    if(data[i] == ':') { pos = i; break; }

    for(i = 0; i < pos; i ++){
      if(data[i] != '0') break;
    }
    for(j = i, i = 0; j < pos; j ++){
      a[i++] = data[j];
    }
    a[i++] = '\0';
    //printf("%s\n", a);
    for(i = pos+1; i < strlen(data); i ++){
      if(data[i] != '0') break;
    }
    for(j = i, i = 0; j < strlen(data); j ++){
      b[i++] = data[j];
    }
    b[i++] ='\0';
    // 去除前导零
    int h, m, flag = 0;
    //printf("%s %s\n", a, b);
    int ok = 0;
    int num = 0;
    int ans[100];
    for(int i = 1; i <= 59; i ++){
      h = m = 0;
      flag = 1;
      for(int j = 0; j < strlen(a); j ++){
        if(get_number(a[j]) < i) {
            h = h*i + get_number(a[j]);
        }
        else { flag = 0; break;}
      }
      if(flag == 0) continue;
      for(int j = 0; j < strlen(b); j ++){
        if(get_number(b[j]) < i) m = m*i + get_number(b[j]);
        else { flag = 0; break;}
      }
      if(flag == 0) continue;
      if(h >= 0 && h <= 23 && m >= 0 && m <= 59) {
          ok = 1;
          ans[num++] = i;
      }
    }
    if(ok == 0) printf("0\n");
    else if(strlen(a) <= 1 && strlen(b) <= 1){
      printf("%d\n", -1);
    }
    else {
      for(int i = 0; i < num; i ++){
        printf("%d ", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
// 如果为单独数字，那么有无穷基地可以表示x
