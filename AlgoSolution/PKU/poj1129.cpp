#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int node[27];
int gaze[30][30];
int res = 30;

void dfs(int cur, int n)
{


}
/*
int isLegal(int cur, int i)
{
  for(int j = 0; j < cur; j ++)
    // �����Ǿ��󼴿�
    if(gaze[j][cur] && node[j] == i)
       return 0;
  return 1;
}

int dfs(int cur, int n, int maxncolor)
{
  printf("cur = %d\n", cur);
  if(cur >= n){
      printf("~%d\n", maxncolor);
      if(res > maxncolor) res = maxncolor;
      return res;
  }
  for(int i = 1; i <= maxncolor; i ++){
    // �����е���ɫ��ѡ
    if(isLegal(cur, i)){
      node[cur] = i;
      dfs(cur+1, n, maxncolor);
    }
  }
  // �����µ���ɫ
  node[cur] = maxncolor+1;
  dfs(cur+1, n, maxncolor+1);
}
*/
int main()
{
  int n;
  char data[30];
  while(scanf("%d", &n) != EOF){
    memset(gaze, 0, sizeof(gaze));
    for(int i = 0; i < n; i ++){
      scanf("%s", data);
      for(int j = 2; j < (int)strlen(data); j ++){
        gaze[data[0]-'A'][data[j]-'A'] = 1;
        gaze[data[j]-'A'][data[0]-'A'] = 1;
      }
    }
    res = 30;
    memset(node, 0, sizeof(node));
    int ans = dfs(0, n, 0);
    printf("=%d\n", ans);
/*
    int visit[27];
    int color[27];
    memset(color, 0, sizeof(color));
    int maxlen = 0;
    for(int i = 0;i < n; i ++){
      memset(visit, 0, sizeof(visit));
      for(int j = 0; j < n; j ++){
        if(gaze[i][j] != 0){
          if(color[j] != 0){
              // �Ѿ�Ⱦɫ
            visit[color[j]] = 1;
          }
        }
      }
      int j;
      for(j = 0; j < 26; j ++){
          // ö�ٵ�����ɫ
        if(visit[j] == 0){
          //
          color[i] == j;
          //
          if(j > maxlen) maxlen = j;
          break;
        }
      }
      if(j == 4) break;
    }
*/
  }
  return 0;
}
