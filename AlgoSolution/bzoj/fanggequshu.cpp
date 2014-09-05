/*
    ID: problem6
    PROG : 方格取数
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 30+5;
int graph[maxn][maxn];

struct Edge{
  int from, to, cap, flow;
};
vector<int> G[maxn*maxn];
vector<Edge> edge;
int d[maxn*maxn];
bool vis[maxn*maxn];
int cur[maxn*maxn];
const int inf = 0x3f3f3f3f;

bool bfs(int s, int t){
  memset(vis, 0, sizeof(vis));
  d[s] = 0;
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while(!q.empty()){
    int x = q.front(); q.pop();
    for(int i = 0; i < G[x].size(); i ++){
      Edge& e = edge[G[x][i]];
      if(!vis[e.to] && e.cap > e.flow){
       vis[e.to] = true;
       d[e.to] = d[x] + 1;
       q.push(e.to);
      }
    }
  }
  return vis[t];
}

int dfs(int x, int t, int a){
  if(x == t || a == 0) return a;
   int flow, f;
   flow = f = 0;
   for(int& i = cur[x]; i < G[x].size(); i ++){
     Edge& e = edge[G[x][i]];
     if(d[x]+1 == d[e.to] && (f = dfs(e.to, t, min(a, e.cap-e.flow))) > 0){
        e.flow += f;
        edge[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
     }
   }
   return flow;
}

int MaxFlow(int s, int t){
  int Flow = 0;
  while(bfs(s, t)){
    memset(cur, 0, sizeof(cur));
    Flow += dfs(s, t, inf);
  }
  return Flow;
}

void init(){
  edge.clear();
  for(int i = 0; i < maxn*maxn; i ++){
    G[i].clear();
  }
}

void add_edge(int from, int to, int cap){
  edge.push_back((Edge){from, to, cap, 0});
  edge.push_back((Edge){to, from, 0, 0});
  int m = edge.size();
  G[from].push_back(m-2);
  G[to].push_back(m-1);
}

bool is_inside(int x, int y, int n){
  if(x >= 0 && x < n && y>= 0 && y < n) return true;
  else return false;
}

int s, t;
void build(int n){
  init();
  s = n*n; t = n*n+1;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      if((i+j)%2 == 0){
        add_edge(s, i*n+j, graph[i][j]);
        if(is_inside(i-1, j, n)) add_edge(i*n+j, (i-1)*n+j, inf);
        if(is_inside(i, j-1, n)) add_edge(i*n+j, i*n+j-1, inf);
        if(is_inside(i+1, j, n)) add_edge(i*n+j, (i+1)*n+j, inf);
        if(is_inside(i, j+1, n)) add_edge(i*n+j, i*n+j+1, inf);
      }else{
        add_edge(i*n+j, t, graph[i][j]);
      }
    }
  }
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int sum = 0;
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++){
        scanf("%d", &graph[i][j]);
        sum += graph[i][j];
      }
    }
    build(n);
    int ans = MaxFlow(s, t);
    //cout << ans << endl;
    printf("%d\n", sum-ans);
  }
  return 0;
}
