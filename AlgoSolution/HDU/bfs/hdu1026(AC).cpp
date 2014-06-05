// 15MS 552K 3103 B
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int gaze[105][105];
int vis[105][105];
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, -1, 0, 1};

struct node{
  int x, y;
  int step;
  bool operator < (const node a) const {
    return step > a.step;
  }
};

struct path{
  int x, y;
}path[105][105];
// record the path

bool is_inside(int x, int y, int n, int m){
  if(x >= 0 && x < n && y >= 0 && y < m)
    return true;
  else return false;
}

void print_path(int x, int y, int step){
  if(step <= 0) return ;
  if(gaze[x][y] > 0){
    if(gaze[x][y] -- ！= 0){
      print_path(x, y, step-1);
      // 向自己递归，不要向父节点递归
      printf("%ds:(%d,%d)->(%d,%d)\n", step--, path[x][y].x, path[x][y].y, x, y);
    }
    while(gaze[x][y] --)
    printf("%ds:FIGHT AT (%d,%d)\n", step--, path[x][y].x, path[x][y].y);
  }
  else{
    print_path(path[x][y].x, path[x][y].y, step-1);
    printf("%ds:(%d,%d)->(%d,%d)\n", step--, path[x][y].x, path[x][y].y, x, y);
  }
}

int num;
// 递归输出实在不行就用全局变量
void print_path(int x, int y){
  if(x == 0 && y == 0) return ;
  print_path(path[x][y].x, path[x][y].y);
  printf("%ds:(%d,%d)->(%d,%d)\n", num++, path[x][y].x, path[x][y].y, x, y);
  for(int i = 0; i < gaze[x][y]; i ++){
    printf("%ds:FIGHT AT (%d,%d)\n", num++, x, y);
  }
}



void bfs(int n, int m){
   node temp;
   temp.x = 0, temp.y = 0;
   temp.step = 0;
   priority_queue<node> q;
   q.push(temp);
   memset(vis, 0, sizeof(vis));
   vis[0][0] = 1;
   path[0][0].x = -1;
   path[0][0].y = -1;
   node cur, next;
   while(!q.empty()){
      cur = q.top();
      q.pop();
      if(cur.x == n-1 && cur.y == m-1){
        printf("It takes %d seconds to reach the target position, ", cur.step);
        printf("let me show you the way.\n");
        print_path(cur.x, cur.y);
        return ;
      }
      for(int i = 0; i < 4; i ++){
        next.x = cur.x + dx[i];
        next.y = cur.y + dy[i];
        if(is_inside(next.x, next.y, n, m) &&
           gaze[next.x][next.y] != -1 && vis[next.x][next.y] == 0){
              next.step = cur.step + 1 + gaze[next.x][next.y];
              path[next.x][next.y].x = cur.x;
              path[next.x][next.y].y = cur.y;
              vis[next.x][next.y] = 1;
              q.push(next);
           }
      }
   }
   printf("God please help our poor hero.\n");
}

int main()
{
  int n, m;
  char data[105];
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 0; i < n; i ++){
      scanf("%s", data);
      for(int j = 0; j < m; j ++){
        if(data[j] >= '0' && data[j] <= '9')
          gaze[i][j] = data[j] -'0';
        else if(data[j] == 'X') gaze[i][j] = -1;
        else if(data[j] == '.') gaze[i][j] = 0;
      }
    }
    /*
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j ++){
        printf("%d ", gaze[i][j]);
      }
      printf("\n");
    }
    */
    num = 1;
    bfs(n, m);
    printf("FINISH\n");
  }
  return 0;
}
