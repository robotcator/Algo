#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000+10;
vector<int> G[maxn];
int st[maxn];
int ed[maxn];

int vis[maxn];
int depth[maxn];

void init(){
  for(int i = 0; i < maxn; i ++)
    G[i].clear();
  memset(vis, 0, sizeof(vis));
  memset(depth, 0, sizeof(depth));
}

void dfs(int s, int dep){
  //printf("%d %d\n", s, depth);
  vis[s] = 1;
  depth[s] = dep;
  if(st[s] != ed[s])
  for(int i = 0; i < G[s].size(); i ++){
    if(vis[G[s][i]] != 1) dfs(G[s][i], dep+1);
  }
}

int main(){
  int n, a, b;
  while(scanf("%d", &n) != EOF){
    init();
    for(int i = 0; i < n-1; i ++){
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
      scanf("%d", &st[i]);
    for(int i = 0; i < n; i ++)
      scanf("%d", &ed[i]);
    dfs(1, 0);
    for(int i = 1; i <= n; i ++)
      printf("%d\n", depth[i]);

  }
  return 0;
}
