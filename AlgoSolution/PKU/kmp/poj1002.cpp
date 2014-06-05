#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int trie[1000005][10];
int val[1000005];
int sz;

int cnt[100005];
char ans[100005][10];
int res;

void Init() {
  memset(trie[0], 0, sizeof(trie[0][10]));
  sz = 1;
}

int Index(char c){
  if(c == 'A' || c == 'B' || c == 'C') return 2;
  else if(c == 'D' || c == 'E' || c == 'F') return 3;
  else if(c == 'G' || c == 'H' || c == 'I') return 4;
  else if(c == 'J' || c == 'K' || c == 'L') return 5;
  else if(c == 'M' || c == 'N' || c == 'O') return 6;
  else if(c == 'P' || c == 'R' || c == 'S') return 7;
  else if(c == 'T' || c == 'U' || c == 'V') return 8;
  else if(c == 'W' || c == 'X' || c == 'Y') return 9;
  else if(c >= '0' && c <= '9') return c-'0';
  else if(c == 'Q' || c == 'Z') return 0;
}

void Insert(int root, char *data) {
  int len = strlen(data);
  int u = root;
  for(int i = 0; i < len; i ++){
    if(data[i] == '-') continue;
    int ch = Index(data[i]);
    if(trie[u][ch] == 0){
      memset(trie[sz], 0, sizeof(trie[sz]));
      trie[u][ch] = sz;
      val[sz] = 0;
      sz ++;
    }
    u = trie[u][ch];
  }
  val[u] ++;
}

void print_word(char *temp, int num, int root){
  for(int i = 0; i < num; i ++)
      ans[res][i] = temp[i];
  cnt[res] = val[root];
  res ++;
}

void dfs(int root, char *temp, int num){
  if(val[root] > 0) print_word(temp, num, root);
    for(int i = 0; i < 10; i ++){
      if(trie[root][i] != 0){
        temp[num] = i + '0';
        dfs(trie[root][i], temp, num+1);
      }
    }
}

void Traverse(int root){
  char temp[10005];
  dfs(0, temp, 0);
}

int main()
{
  int t;
  char data[1000];
  scanf("%d", &t);
  Init();
  for(int i = 0; i < t; i ++){
    scanf("%s", data);
    Insert(0, data);
  }
  res = 0;
  Traverse(0);
  // cout << res << endl;
  int flag = 0;
  for(int i = 0; i < res; i ++)
    if(cnt[i] > 1) {
        for(int j = 0; j < strlen(ans[i]); j ++){
          if(j == 3) printf("-%c", ans[i][j]);
          else printf("%c", ans[i][j]);
        }
        printf(" %d\n", cnt[i]);
        flag = 1;
    }
  if(flag == 0) printf("No duplicates.\n");
  // 没有两个是相同的
  return 0;
}
