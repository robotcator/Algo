/*
// Time Limit Exceeded
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

char data[20000000];

int main()
{
  int n, nc;
  set<string> a;
  while(scanf("%d%d", &n, &nc) != EOF){
    scanf("%s", data);
    a.clear();
    if(strlen(data)-n < 0) printf("0\n");
    else {
      string temp;
      for(int i = 0; i <= strlen(data)-n; i ++){
        for(int j = i; j < i+n; j ++)
          temp += data[j];
      a.insert(temp);
      }
      printf("%d\n", a.size());
    }
  }
  return 0;
}
*/

// 如何构造哈希函数，尽量不冲突
// Time Limit Exceeded
// Accepted 30388K 79MS
// 单输入，为了节约时间一般用len = strlen(data);
// 避免判断是重复计算
// 尽量减少代码中的重复计算和空间分配等代码
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
using namespace std;

char data[1000000];
int Hash[17000000];
// 哈希函数为将长度为n的字符转换为nc进制的数
int main()
{
  int n, nc;
  int asc[257];
  //while(scanf("%d%d", &n, &nc) != EOF){
    scanf("%d%d", &n, &nc);
    scanf("%s", data);
    memset(asc, 0, sizeof(asc));
    memset(Hash, 0, sizeof(asc));
    int key  = 0;
    int len = strlen(data);
    for(int i = 0; i < len; i ++){
        if(asc[data[i]] == 0) asc[data[i]] = ++key;
        if(key == nc) break;
    }
    // 如何查出这四种字符,出现的字符分别表位1,2,3 ... n
    // 可以构造nc进制的数
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < len-n+1; i ++){
      sum = 0;
      for(int j = i; j < i+n; j ++){
        sum = sum*nc + asc[data[j]]-1;
        // 任意n进制数的计算，按权相加
      }
      if(Hash[sum] == 0){
        Hash[sum] = 1;
        cnt ++;
      }
    }
    printf("%d\n", cnt);

  //}
  return 0;
}
