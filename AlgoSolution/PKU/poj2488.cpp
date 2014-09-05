#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int chess[30][30];
char path[900];
int p, q;

//int dx[10] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[10] = { 1,  2, 2, 1,-1, -2, -2, -1};
int dx[10] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[10] = {-1, 1, -2, 2, -2, 2, -1, 1};
// �ƶ����ֵ��� �޶�Ϊ�����޻���������

void print_path(int p, int q)
{
  for(int i = 0; i < 2*p*q; i ++)
    printf("%c", path[i]);
  printf("\n");
}

void dfs(int x, int y, int num, int& flag)
{
  if(num == q*p){
    flag = 1;
    return ;
  }
  for(int i = 0; i < 8; i ++){
   int xx = x + dx[i];
   int yy = y + dy[i];
   if(1 <= xx && xx <= p && 1 <= yy && yy <= q && chess[xx][yy] == 0){
      chess[xx][yy] = 1;
      path[2*num] = 'A' + yy - 1;
      path[2*num+1] = '1' + xx - 1;
      // ·����¼
      dfs(xx, yy, num+1, flag);
      chess[xx][yy] = 0;
      // ����
   }
  }
}

int main()
{
  int T;
  int num = 1;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &p, &q);
    // p ��digit q ��alpha��
    memset(chess, 0, sizeof(chess));
    chess[0][0] = 1;
    int flag = 0;
    path[0] = 'A';
    path[1] = '1';
    dfs(1, 1, 1, flag);
    printf("Scenario #%d:\n", num ++);
    if(flag == 0) printf("impossible\n");
    else print_path(p, q);
  }
  return 0;
}
