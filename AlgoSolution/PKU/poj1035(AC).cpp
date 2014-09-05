// Accepted 19104K 172MS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 300000;

int ch[maxn][26];
int val[maxn];
int sz;

struct node{
  char record[20];
  int id;
};

void Init() {
  sz = 1;
  memset(ch[0], 0, sizeof(ch[0]));
  memset(val, 0, sizeof(val));
}

int Index(char c) {
  return c-'a';
}

void Insert(char *s, int v) {
  int u = 0;
  int len = strlen(s);
  for(int i = 0; i < len; i ++) {
    int c = Index(s[i]);
    if(ch[u][c] == 0) {
      memset(ch[sz], 0, sizeof(ch[sz]));
      // 下一个节点啊
      val[sz] = 0;
      ch[u][c] = sz ++;
    }
    u = ch[u][c];
  }
  val[u] = v;
}

int Search(char *s) {
  int len = strlen(s);
  int u = 0, i;
  for(i = 0; i < len; i ++){
    int c = Index(s[i]);
      u = ch[u][c];
    if(u == 0) break;
  }
  if(i == len && val[u] > 0) return val[u];
  else return 0;
}

void Delete_Letter(char *data, char *temp, int i) {
  int k = 0;
  for(int j = 0; j < (int)strlen(data); j ++){
    if(j != i) temp[k++] = data[j];
  }
  temp[k] = '\0';
}

void Insert_Front(char *data, char *temp, int i, char x) {
  int k = 0;
  for(int j = 0; j < (int)strlen(data); j ++){
    if(i == j) temp[k++] = x;
    temp[k++] = data[j];
  }
  temp[k] = '\0';
}

void Insert_Back(char *data, char *temp, int i, char x) {
  int k = 0;
  for(int j = 0; j < (int)strlen(data); j ++){
    temp[k++] = data[j];
    if(i == j) temp[k++] = x;
  }
  temp[k] = '\0';
}

void Modify_Letter(char *data, char *temp, int i, char x) {
  int k = 0;
  for(int j = 0; j < (int)strlen(data); j ++){
    if(i == j) temp[k++] = x;
    else temp[k++] = data[j];
  }
  temp[k] = '\0';
}

int cmp(node a, node b) {
  return a.id < b.id;
}

int main()
{
  char data[16];
  node s[200000];
  // 要的修改
  int v = 1;
  Init();
  while(1){
    scanf("%s", data);
    if(strcmp(data, "#") == 0) break;
    Insert(data, v);
    v ++;
  }
  while(1){
    scanf("%s", data);
    if(strcmp(data, "#") == 0) break;
    if(Search(data)) printf("%s is correct\n", data);
    else {
        int num = 0;
        int val = 0;
        for(int i = 0; i < (int)strlen(data); i ++){
          char temp[20];
          Delete_Letter(data, temp, i);
          if((val = Search(temp))) {
              strcpy(s[num].record, temp);
              s[num++].id = val;
          }
          // printf("%s\n", temp);
          // 删除一个字符
          for(int j = 0; j < 26; j ++){
              Insert_Front(data, temp, i, j+'a');
             // printf("%s\n", temp);
              if((val = Search(temp))) {
                  strcpy(s[num].record, temp);
                  s[num++].id = val;
              }
              Insert_Back(data, temp, i, j+'a');
             // printf("%s\n", temp);
              if((val = Search(temp))) {
                  strcpy(s[num].record, temp);
                  s[num++].id = val;
              }
              Modify_Letter(data, temp, i, j+'a');
             // printf("%s\n", temp);
              if((val = Search(temp))) {
                  strcpy(s[num].record, temp);
                  s[num++].id = val;
              }
              // printf("%s\n", record[num-1]);
           }
        }
       // printf("%d\n", num);
        sort(s, s+num, cmp);
        printf("%s:", data);
        if(num != 0){
          printf(" %s", s[0].record);
          for(int i = 1; i < num; i ++) {
            if(strcmp(s[i].record, s[i-1].record) != 0)
              printf(" %s", s[i].record);
          }
        }
        printf("\n");
    }
  }
  return 0;
}
