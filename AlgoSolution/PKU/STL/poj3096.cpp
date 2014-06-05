// Accepted 164K 0MS
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

// 26进制进行哈希,因为只有两位所以数据不大

bool hash_table[1000];

int check(char *data){
  int len = strlen(data);
  int flag = 0;
  for(int i = 0; i < len-2; i ++){
      memset(hash_table, 0, sizeof(hash_table));
      int key = 0;
    for(int j = 0; j+i+1 < len; j ++){
      key = data[j]-'A' + 26*(data[j+i+1]-'A');
      if(hash_table[key]) { flag = 1; break; }
      else hash_table[key] = true;
    }
    if(flag == 1) break;
  }
  if(flag == 1) return 1;
  else return 0;
}

int main()
{
  char data[100];
  while(scanf("%s", data) != EOF){
    if(data[0] == '*') break;
    int res = check(data);
    if(res == 1) printf("%s is NOT surprising.\n", data);
    else printf("%s is surprising.\n", data);
  }
  return 0;
}
