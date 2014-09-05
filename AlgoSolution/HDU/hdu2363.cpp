#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

const int maxn = 100+10;
const int inf = 0x3f3f3f3f;
int n,  m;
int altitude[maxn];

vector<int> G[maxn];
struct edge{
  int u, v, cost;
};
vector<edge> edges;

void init(){
  edges.clear();
  for(int i = 0; i <= n; i ++) G[i].clear();

}

void add_edge(int a, int b, int c){
  edge temp;
  temp.u = a, temp.v = b, temp.cost = c;
  edges.push_back(temp);
  temp.u = b, temp.v = a, temp.cost = c;
  edges.push_back(temp);
  int size = edges.size();
  G[a].push_back(size-2);
  G[b].push_back(size-1);
}

struct HeapNode{
  int dist, u;
  bool operator < (const HeapNode & c) const{
    return dist > c.dist;
  }
};
int d[maxn];
int vis[maxn];
int p[maxn];

bool dijksta(int src, int limit){
  priority_queue<HeapNode> q;
  memset(d, inf, sizeof(d));
  d[src] = 0;
  memset(vis, 0, sizeof(vis));
  q.push((HeapNode){0, src});
  while(!q.empty()){
    HeapNode x = q.top();
    q.pop();
    int u = x.u;
    if(vis[u]) continue;
    vis[u] = 1;
    for(int i = 0; i < G[u].size(); i ++){
      edge e = edges[G[u][i]];
      if(abs(altitude[u]-altitude[e.v]) <= limit && d[e.v] > d[e.u] + e.cost){
        d[e.v] = d[e.u] + e.cost;
        p[e.v] = G[u][i];
        q.push((HeapNode){d[e.v], e.v});
      }
    }
  }
  for(int i = 1; i <= n; i ++)
    //if(d[i] == inf) return 0;
    printf("%d ", d[i]);
  printf("\n");
  return 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t --){
    init();
    scanf("%d%d", &n, &m);
    int L, R;
    L = inf, R = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &altitude[i]);
      if(altitude[i] > R) R = altitude[i];
      if(altitude[i] < L) L = altitude[i];
    }
    int a, b, c;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &a, &b, &c);
      add_edge(a, b, c);
    }
    printf("\n");
    for(int i = 1; i <= n; i ++){
      printf("%d ", i);
      for(int j = 0; j < G[i].size(); j ++){
        printf("%d ", G[i][j]);
      }
      printf("\n");
    }
    printf("%d%d\n", L, R);
    int mid;
    while(L <= R){
      mid = (L+R)/2;
      if(dijksta(1, mid) == 0) L = mid+1;
      else R = mid-1;
    }
    printf("%d\n", mid);
    for(int i = 1; i <= n; i ++)
      printf("%d ", p[i]);
    printf("\n");
  }
  return 0;
}
