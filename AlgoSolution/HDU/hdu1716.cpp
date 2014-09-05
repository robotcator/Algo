// Accepted	1716	0MS	300K	1175 B	G++	robotcator
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char p[30][10];
int k;

void get_permutation(int *a, int n){
  sort(a, a+n);
  memset(p, 0, sizeof(p));
  for(int i = 0; i < n; i ++)
    p[k][i] = a[i]+'0';
  k ++;
  while(next_permutation(a, a+n)){
    for(int i = 0; i < n; i ++){
      p[k][i] = a[i] + '0';
     // cout << a[i] << " ";
    }
    p[k][n] = '\0';
    k ++;
    // cout << endl;
  }
  //cout << k << endl;
}

int main(){
  int a[5];
  int flag = 0;
  while(scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != EOF){
    if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;
    if(flag == 1) printf("\n");
    flag = 1;
    //  每组数据要输入换行，但是最后一组数据不换行
    k = 0;
    get_permutation(a, 4);
    int j = 0;
    for(int i = 0; i < k; i ++){
      if(p[i][0] != '0'){ j = i; break; }
    }
    for(int i = j; i < k; i ++){
      if(i != j && p[i][0] != p[i-1][0]) printf("\n");
      printf("%s", p[i]);
      if(i != k && p[i][0] == p[i+1][0]) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
