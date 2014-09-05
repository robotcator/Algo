/*
    ID: problem6
    PROG : find the safest road
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
const double eps = 1e-10;
double graph[maxn][maxn];

int vis[maxn];
double d[maxn];
int p[maxn];

struct node{
  double dist;
  int x;
  bool operator < (const node& p)const{
    return dist - p.dist > 0;
  }
};

double dijkstra(int s, int t, int n){
  memset(vis, 0, sizeof(vis));
  memset(d, 0, sizeof(d));
  priority_queue<node> q;
  node temp;
  temp.dist = 1; temp.x = s;
  q.push(temp);
  d[s] = 1;
  p[s] = -1;
  while(!q.empty()){
   node cur = q.top(); q.pop();
   if(vis[cur.x]) continue;
   vis[cur.x] = 1;
   for(int i = 1; i <= n; i ++){
      if(!vis[i] && graph[cur.x][i] > eps &&
         d[cur.x]*graph[cur.x][i] > d[i]){
        d[i] = d[cur.x]*graph[cur.x][i];
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
  int n;
  while(scanf("%d", &n) != EOF){
    memset(graph, 0, sizeof(graph));
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        scanf("%lf", &graph[i][j]);
      }
    }
    int q, x, y;
    scanf("%d", &q);
    for(int i = 0; i < q; i ++){
      scanf("%d%d", &x, &y);
      double ans = dijkstra(x, y, n);
      if(!ans) printf("What a pity!\n");
      else printf("%.3f\n", ans);
    }
  }
  return 0;
}
