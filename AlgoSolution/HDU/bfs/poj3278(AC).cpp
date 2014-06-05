// 1764K 16MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 200000+1;
int vis[maxn];

struct node{
  int x;
  int step;
};

void bfs(int n, int k){
  memset(vis, 0, sizeof(vis));
  queue<node> q;
  node temp;
  temp.x = n, temp.step = 0;
  q.push(temp);
  vis[n] = 1;
  node cur, next;
  while(!q.empty()){
    cur = q.front();
    q.pop();
    if(cur.x == k){
      printf("%d\n", cur.step);
      return ;
    }
    // 剪枝要注意，可以到2*k,也允许到k+1
    // 不然模拟1-5试试
    // 所以第一要模拟一组方案试试，怎么剪枝才是正确的也要试试
    // 数据越完善越好
    for(int i = 0; i < 3; i ++){
      if(i == 0){
        if(cur.x <= k && vis[cur.x+1] == 0){
          next.x = cur.x + 1;
          next.step = cur.step + 1;
          q.push(next);
          vis[next.x] = 1;
        }
      }
      else if(i == 1){
        if(cur.x-1 >= 0 &&  vis[cur.x-1] == 0){
          next.x = cur.x - 1;
          next.step = cur.step + 1;
          q.push(next);
          vis[next.x] = 1;
        }
      }
      else if(i == 2){
        if(cur.x >= 0 && cur.x <= k && vis[cur.x*2] == 0){
          next.x = cur.x * 2;
          next.step = cur.step + 1;
          q.push(next);
          vis[next.x] = 1;
        }
      }
    }
  }
}

int main()
{
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    bfs(n, k);
  }
  return 0;
}
