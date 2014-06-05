/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x7f7f7f7f;
const int maxn = 100000+10;
struct edge{
  int to, cost;
};

struct node{
  int v,dist;
  bool operator < (const node a) const{
    return a.dist < dist;
  }
};

vector<edge> G[maxn];
int vis[maxn];
int d[maxn];

void dijkstra(int s, int t){
    node temp;
    temp.v = s, temp.dist = 0;
    priority_queue<node> q;
    q.push(temp);
    memset(d, inf, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    while(!q.empty()){
      node cur = q.top();
      q.pop();
      if(vis[cur.v] == 1) continue;
      vis[cur.v] = 1;
      for(int i = 0; i < G[cur.v].size(); i ++){
        int u = G[cur.v][i].to;
        if(G[cur.v][i].cost + d[cur.v] < d[u]){
          d[u] = G[cur.v][i].cost + d[cur.v];
          node next;
          next.v = u, next.dist = d[u];
          q.push(next);
        }
      }
    }
}

int main()
{
  int n, m, q;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    scanf("%d", &m);
    int a, b, c;
    edge temp;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &a, &b, &c);
      temp.to = b, temp.cost = c;
      G[a].push_back(temp);
      temp.to = a, temp.cost = c;
      G[b].push_back(temp);
    }
    scanf("%d", &q);
    int s, t;
    for(int i = 0; i < q; i ++){
        scanf("%d%d", &s, &t);
        dijkstra(s, t);
        if(d[t] == inf) cout << "-1" << endl;
        else cout << d[t] << endl;
    }
  }
  return 0;
}
*/
