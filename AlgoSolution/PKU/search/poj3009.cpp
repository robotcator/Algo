#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int w, h;
int ans;
int gaze[25][25];
//int dx[5] = {0, -1, 0, 1};
//int dy[5] = {1, 0, -1, 0};

int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

int check(int x, int y)
{
  if(x >= w || x < 0 || y >= h || y < 0) return -1;
  // 不能向这个方向扩展
  else if(gaze[x][y] == 1) return 1;
  // 遇到石头
  else if(gaze[x][y] == 3)  return 3;
  // 遇到终点
  else return 2;
  // 空道
}

void dfs(int sx, int sy, int ex, int ey, int num)
{
  if(num > 10) return;
  if(sx == ex && sy == ey) {
    ans = ans > num ? num : ans;
    return ;
  }
  for(int i = 0; i < 4; i ++){
    int tx = sx ;
    int ty = sy ;
    int temp;
    if(check(tx+dx[i], ty+dy[i]) == 1) continue;
      while(1){
        if((temp = check(tx+dx[i], ty+dy[i]))== 2) {
          tx = tx + dx[i];
          tx = tx + dy[i];
        }
        else {
          if(temp == 3) {
            tx += dx[i];
            ty += dy[i];
            dfs(tx, ty, ex, ey, num+1);
          }
          else if(temp == 1) {
            // ?
            int xx = tx;
            int yy = ty;
            tx += dx[i];
            ty += dy[i];
            gaze[tx][ty] = 0;
            dfs(xx, yy, ex, ey, num+1);
            gaze[tx][ty] = 1;
          }
          break;
        }
      }
    }

}

int main()
{
  int sx, sy, ex, ey;
  while(scanf("%d%d", &w, &h) != EOF){
    memset(gaze, 0, sizeof(gaze));
    for(int i = 0; i < w; i ++){
      for(int j = 0; j < h; j ++){
        scanf("%d", &gaze[i][j]);
        if(gaze[i][j] == 2){
          sx = i; sy = j;
        }
        if(gaze[i][j] == 3){
          ex = i; ey = j;
        }
      }
    }
    ans = 11;
    dfs(sx, sy, ex, ey, 0);
    if(ans == 11) printf("-1\n");
    else printf("~ %d\n", ans);
  }
  return 0;
}
