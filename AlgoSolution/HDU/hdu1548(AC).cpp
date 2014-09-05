#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node{
  int pos;
  int step;
};
int k[210];

void bfs(int from, int to, int n){
  node que[5000];
  int vis[210];
  memset(vis, 0, sizeof(vis));
  int front, rear;
  front = rear = 0;
  que[rear].pos = from;
  que[rear].step = 0;
  rear ++;
  vis[from]  = 1;
  int flag = 0;  // 判断是否到达，如果最后队列已空则不能到达
  node cur;
  while(front < rear){
     // 相等时表示没有元素，还犯这种低级错误
     cur = que[front++];
     if(cur.pos == to){
        flag = 1;
        break;
     }
     if(cur.pos+k[cur.pos] <= n && cur.pos+k[cur.pos] >= 1
        && vis[cur.pos+k[cur.pos]] == 0) {
        que[rear].pos = cur.pos+k[cur.pos];
        que[rear].step = cur.step+1;
        vis[que[rear].pos] = 1;
        rear ++;
     }
    if(cur.pos-k[cur.pos] <= n && cur.pos-k[cur.pos] >= 1
        && vis[cur.pos-k[cur.pos]] == 0) {
        que[rear].pos = cur.pos-k[cur.pos];
        que[rear].step = cur.step+1;
        vis[que[rear].pos] = 1;
        rear ++;
     }
  }
  if(flag == 1) printf("%d\n", cur.step);
  else printf("-1\n");
}

int main()
{
  int n, a, b;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= n; i ++)
      scanf("%d", &k[i]);
    bfs(a, b, n);
  }
  return 0;
}
