// Accepted	176K	16MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100+10;
const int inf = 0x3f3f3f3f;
struct edge{
  int from, to, cost;
};
vector<int> G[maxn];
vector<edge> edges;

void Init(){
  edges.clear();
  for(int i = 0; i < maxn; i ++)
    G[i].clear();
}

void add_edge(int u, int v, int cost){
  edge temp;
  temp.from = u, temp.to = v, temp.cost = cost;
  edges.push_back(temp);
  G[u].push_back(edges.size()-1);
}

bool inq[maxn];
int d[maxn];
int cnt[maxn];

bool spfa(int src, int n){
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i <= n; i ++){
    inq[i] = false;
    d[i] = inf;
  }
  queue<int> q;
  q.push(src);
  d[src] = 0;
  inq[src] = true;
  cnt[src] ++;
  while(!q.empty()){
      int cur = q.front();
      q.pop();
      inq[cur] = false;
      for(int j = 0; j < G[cur].size(); j ++){
        edge temp = edges[G[cur][j]];
        if(d[temp.to] > temp.cost + d[cur]){
          d[temp.to] = temp.cost + d[cur];
          if(!inq[temp.to]){
            q.push(temp.to);
            inq[temp.to] = true;
            cnt[temp.to] ++;
            if(cnt[temp.to] >= n+1) return false;
          }
        }
      }
  }
  return true;
}

int main()
{
  int m, n;
  //freopen("in.txt", "r", stdin);
  while(scanf("%d", &n), n){
    scanf("%d", &m);
    int si, ni, ki;
    char op[5];
    Init();
    for(int i = 0; i < m; i ++){
      scanf("%d %d %s %d", &si, &ni, op, &ki);
      if(strcmp(op, "gt") == 0){
        add_edge(si+ni, si-1, -(ki+1));
      }
      else if(strcmp(op, "lt") == 0){
        add_edge(si-1, si+ni, ki-1);
      }
    }
    /*
    for(int i = 0; i <= n; i ++){
      for(int j = 0; j < G[i].size(); j ++){
        edge temp = edges[G[i][j]];
        printf("%d %d %d %d\n", i, temp.from, temp.to, temp.cost);
      }
    }
    */
    bool ans = spfa(0, n);
    for(int i = 0; i <= n; i ++)
      cout << d[i] << endl;
    if(!ans) printf("successful conspiracy\n");
    else {
      printf("lamentable kingdom\n");
    }
  }
  return 0;
}
