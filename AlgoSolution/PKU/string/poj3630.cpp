#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 10;

int cmp(char *a, char *b)
{
  return strcmp(a, b) < 0;
}

int main()
{
  int T, n;
  char **data;
  data = new char*[maxn];
  for(int i = 0; i < maxn; i ++)
    data[i] = new char[12];
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%s", data[i]);
    sort(data, data+n, cmp);
    int flag = 0;
    for(int i = 1; i < n; i ++){
      // printf("%s\n", data[i]);
      int len = strlen(data[i-1]);
      int ans = strncmp(data[i-1], data[i], len);
      if(ans == 0) {
          flag = 1;
          break;
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
/*
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxnode = 100000;

int ch[maxnode][15];
int val[maxnode];
int sz;

void init()
{
  sz = 1;
  memset(ch[0], 0, sizeof(ch[0]));
}

int index(char c)
{
  return c-'0';
}

void Insert(char *s, int v)
{
  int u = 0;
  int len = strlen(s);
  for(int i = 0; i < len; i ++){
    int c = index(s[i]);
   // printf("%d\n", c);
    if(ch[u][c] == 0){
      memset(ch[sz], 0, sizeof(ch[sz]));
      val[sz] = 0;
      ch[u][c] = sz ++;
      //printf("%d\n", ch[u][c]);
    }
   // printf("~%d\n", sz);
    u = ch[u][c];
   // printf("u = %d\n", u);
  }
  val[u] = v;
  ch[u][10] = 1;
}

int Search(char *s)
{
  int len = strlen(s);
  int u = 0;
  for(int i = 0; i < len; i ++){
    int c = index(s[i]);
    u = ch[u][c];
  }
  return val[u] > 0 ? val[u] : 0;
}

bool Del(char *s)
{
  int len = strlen(s);
  int u = 0;
  for(int i = 0; i < len; i ++){
    int c = index(s[i]);
    u = ch[u][c];
  }
  if(val[u] == 0) return false;
  else {
    val[u] =0;
    return true;
  }
}

int longPrefix(char *s)
{
  int len = strlen(s);
  int num = 0;
  int u = 0;
  for(int i = 0; i < len; i ++){
    int c = index(s[i]);
    if(ch[u][c] == 0)  break;
    num ++;
    u = ch[u][c];
  }
  return num;
}

void print_word(char *temp, int num)
{
  for(int i = 0; i < num; i ++)
    printf("%c", temp[i]);
  printf("\n");
}

void traverse(int root, char *temp, int num)
{
  // printf("root %d %d\n", root, ch[root][10]);
  //if(ch[root][10] == 1)
  if(val[root] != 0)
    print_word(temp, num);
  // 该层不会再进入循环内
  for(int i = 0; i < 10; i ++){
    if(ch[root][i]){
      temp[num] = i + '0';
      //printf("%c", i+'0');
      traverse(ch[root][i], temp, num+1);
    }
  }
}

int main()
{
  int T, n;
  char data[15];
  scanf("%d", &T);
  while(T--){
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
      scanf("%s", data);
      Insert(data, i+1);
    }
    while(scanf("%s", data)){
      int ans = Search(data);
      printf("%d\n", ans);
    }
    char temp[10000];
    traverse(0, temp, 0);
    while(scanf("%s", temp)){
      int ans = longPrefix(temp);
      printf("%d\n", ans);
    }
  }
  return 0;
}
*/

