// 680K 563MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct point{
  int x, y, step;
  int f, g, h;
  bool operator < (const point& a)const{
    return f > a.f;
  }
};

int d[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int vis[9][9];

bool is_inside(int x, int y, int n){
  if(x >= 0 && x < n && y >= 0 && y < n )
    return true;
  else return false;
}

int manhattan(const point temp, int ex, int ey){
  return (abs(temp.x-ex)+abs(temp.y-ey))*10;
}

void Astar(int sx, int sy, int ex, int ey){
  memset(vis, 0, sizeof(vis));
  point temp;
  temp.x = sx, temp.y = sy;
  temp.step = 0; temp.g = 0;
  temp.h = manhattan(temp, ex, ey);
  temp.f = temp.g + temp.h;
  priority_queue<point> q;
  q.push(temp);
  vis[temp.x][temp.y] = 1;
  point cur, next;
  while(!q.empty()){
    cur = q.top();
    q.pop();
    vis[cur.x][cur.y] = 1;
    if(cur.x == ex && cur.y == ey){
      printf("To get from %c%c to %c%c takes %d knight moves.\n",
             sx+'a', sy+'1', ex+'a', ey+'1', cur.step);
      break;
    }
    for(int i = 0; i < 8; i ++){
        next.x = cur.x + d[i][0];
        next.y = cur.y + d[i][1];
        if(is_inside(next.x, next.y, 8) && vis[next.x][next.y] == 0){
          next.g = cur.g + 23;
          next.h = manhattan(next, ex, ey);
          next.f = next.g + next.f;
          next.step = cur.step+1;
          q.push(next);
        }
    }
  }
}

int main()
{
  char data[5];
  while(gets(data)){
    int sx = data[0]-'a';
    int sy = data[1]-'1';
    int ex = data[3]-'a';
    int ey = data[4]-'1';
    Astar(sx, sy, ex, ey);
  }
  return 0;
}
