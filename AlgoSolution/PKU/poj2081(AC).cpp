//Memory Limit Exceeded   C++ 593B
//Accepted 7016K 0MS C++
//a���ܹ���visҪѧ����ƻ��߼����滻
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[500005];
bool vis[5000000];

void table()
{
  memset(vis, 0, sizeof(vis));
  memset(a, 0, sizeof(a));
  // �����Ƿ��������֪�������У����������¼
  for(int i = 1; i <= 500000; i ++){
    if(a[i-1]-i > 0 && vis[a[i-1]-i] == 0){
      a[i] = a[i-1] - i;
      vis[a[i]] = 1;
    }
    else{
      a[i] = a[i-1] + i;
      vis[a[i]] = 1;
    }
  }
}

int main()
{
  int k;
  table();
  while(scanf("%d", &k) != EOF){
      if(k == -1) break;
      printf("%d\n", a[k]);
  }
  return 0;
}
