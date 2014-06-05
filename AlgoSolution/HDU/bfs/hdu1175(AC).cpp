// Time Limit Exceeded 1175 10000MS 10412K 2628 B
// 找到后没有break
// 修改后3265MS 10396K 2843 B
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
// 逆时针

struct node{
  int x, y;
  int round;
};
int gaze[1005][1005];
int vis[1005][1005];
int flag;

bool is_inside(int x, int y, int n, int m){
  if(x >= 0 && x < n && y >= 0 && y < m)
    return true;
  else return false;
}

void bfs(int sx, int sy, int ex, int ey, int n, int m){
  queue<node> q;
  node temp;
  memset(vis, 0, sizeof(vis));
  temp.x = sx, temp.y = sy, temp.round = -1;
  q.push(temp);
  vis[temp.x][temp.y] = 1;
  node cur, next;
  while(!q.empty()){
    cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i ++){
        next.x = cur.x + dx[i];
        next.y = cur.y + dy[i];
        next.round = cur.round + 1;
        if(next.round > 2) continue;
        //cout << next.x << " " << next.y << endl;
        while(1){
            if(!is_inside(next.x, next.y, n, m)) break;
              // 是否在界内
            if(gaze[next.x][next.y] != 0){
              // 是障碍物
              if(next.x == ex && next.y == ey && next.round <= 2){
                flag = 1;
                return ;
              }
              break;
            }
            if(vis[next.x][next.y] == 0){
              q.push(next);
              vis[next.x][next.y] = 1;
            }
            next.x += dx[i];
            next.y += dy[i];
            next.round = cur.round + 1;
        }
        /*
        while(is_inside(next.x, next.y, n, m) && vis[next.x][next.y] == 0){
            if(vis[next.x][next.y] == 0){
              if(next.x == ex && next.y == ey && next.round <= 2){
                printf("YES\n");
                return ;
              }
              cout << next.x << " " << next.y << endl;
              vis[next.x][next.y] = 1;
              q.push(next);
            }
            next.x += dx[i];
            next.y += dy[i];
            next.round = cur.round + 1;
        }
      */
    }
  }
}

int main()
{
  int n, m, q;
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    memset(gaze, 0, sizeof(gaze));
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j ++){
        scanf("%d", &gaze[i][j]);
      }
    }
    int sx, sy, ex, ey;
    scanf("%d", &q);
    for(int i = 0; i < q; i ++){
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        if(gaze[sx-1][sy-1] != gaze[ex-1][ey-1]
           || gaze[sx-1][sy-1] == 0 || gaze[ex-1][ey-1] == 0)
          printf("NO\n");
        else{
          flag = 0;
          bfs(sx-1, sy-1, ex-1, ey-1, n, m);
          if(flag == 0) printf("NO\n");
          else printf("YES\n");
        }
    }
  }
  return 0;
}
