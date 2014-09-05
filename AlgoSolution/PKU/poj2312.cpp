/*
2 2
T B
E Y
*/
// Accepted 1164K 16MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 300+10;
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, -1, 0, 1};
int n, m;
int sx, sy, ex, ey;
char gaze[maxn][maxn];
int vis[maxn][maxn];

struct node{
  int x, y, step;
  bool operator <(const node a)const{
    return step > a.step;
  }
};

bool is_inside(int x, int y){
  if(x >= 0 && x < n && y >= 0 && y < m)
    return true;
  else return false;
}

void bfs(){
  memset(vis, 0, sizeof(vis));
  priority_queue<node> q;
  node temp;
  temp.x = sx, temp.y = sy, temp.step = 0;
  q.push(temp);
  vis[sx][sy] = 1;
  node cur, next;
  while(!q.empty()){
    cur = q.top();
    q.pop();
    //cout << cur.x << cur.y << cur.step << endl;
    if(cur.x == ex && cur.y == ey){
      printf("%d\n", cur.step);
      return ;
    }
    for(int i = 0; i < 4; i ++){
      next.x = cur.x + dx[i];
      next.y = cur.y + dy[i];
      if(is_inside(next.x, next.y) && vis[next.x][next.y] == 0
         && (gaze[next.x][next.y] == 'E' || gaze[next.x][next.y] == 'B'
             || gaze[next.x][next.y] == 'T')){
            if(gaze[next.x][next.y] == 'E' || gaze[next.x][next.y] == 'T')
                next.step = cur.step + 1;
            else if(gaze[next.x][next.y] == 'B')
                next.step = cur.step + 2;
            q.push(next);
            vis[next.x][next.y] = 1;
      }
    }
  }
  printf("%d\n", -1);
  // 木有找到
}

int main()
{
  char data[maxn];
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    memset(gaze, 0, sizeof(gaze));
    for(int i = 0; i < n; i ++){
      scanf("%s", data);
      for(int j = 0; j < m; j ++){
        if(data[j] == 'Y'){
          sx = i, sy = j;
        }
        else if(data[j] == 'T'){
          ex = i, ey = j;
        }
        gaze[i][j] = data[j];
      }
    }
    // input
    //cout << sx << sy << ex << ey << endl;
    bfs();
  }
  return 0;
}
