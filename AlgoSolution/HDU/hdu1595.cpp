/*
    ID: problem6
    PROG : find the longest of the shortest
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000+10;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];
int vis[maxn];
int d[maxn];
int p[maxn];

struct node{
  int dist, x;
  bool operator < (const node& p)const{
    return dist > p.dist;
  }
};

int bfs(int s, int t, int n){
  memset(vis, 0, sizeof(vis));
  memset(d, inf, sizeof(d));
  priority_queue<node> q;
  node temp;
  temp.dist = 0; temp.x = s;
  q.push(temp);
  int ans = 0;
  d[s] = 0;
  p[s] = -1;
  while(!q.empty()){
   node cur = q.top(); q.pop();
   if(vis[cur.x]) continue;
   vis[cur.x] = 1;
   for(int i = 1; i <= n; i ++){
      if(!vis[i] && graph[cur.x][i] < inf &&
         d[cur.x]+graph[cur.x][i] < d[i]){
        d[i] = d[cur.x]+graph[cur.x][i];
        temp.dist = d[i];
        temp.x = i;
        q.push(temp);
        p[i] = cur.x;
      }
   }
  }
  return d[t];
}

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    int x, y, z;
    memset(graph, inf, sizeof(graph));
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &x, &y, &z);
      graph[x][y] = graph[y][x] = z;
    }
    int ans = bfs(1, n, n);
    int num = 1;
    path[num++] = n;
    int temp = p[n];
    while(temp != -1){
      path[num++] = temp;
      temp = p[temp];
    }
    // Ã¶¾ÙÃ¿Ìõ±ß
    for(int i = num-1; i > 1; i --){
      //cout << path[i] << " " << path[i-1] << endl;
      int tempx = graph[path[i]][path[i-1]];
      graph[path[i]][path[i-1]] = graph[path[i-1]][path[i]] = inf;
      temp = bfs(1, n, n);
      //cout << temp << endl;
      if(temp != inf && temp > ans) ans = temp;
      graph[path[i]][path[i-1]] = graph[path[i-1]][path[i]] = tempx;
    }
    cout << ans << endl;
  }
  return 0;
}
