#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 2000+10;
int n, k, x;
vector<int> G[maxn];
int pre[maxn];
int link[maxn];
int sccno[maxn];
int dfs_clock, sccnum;
stack<int> s;

int minn(int a, int b){ return a > b ? b : a; }

void dfs(int u){
  pre[u] = link[u] = ++ dfs_clock;
  s.push(u);

  for(int i = 0; i < G[u].size(); i ++){
    int v = G[u][i];
    if(pre[v] == 0){
      dfs(v);
      link[u] = minn(link[u], link[v]);
    }
    else if(sccno[v] == 0){
      link[u] = minn(link[u], pre[v]);
    }
  }

  if(link[u] == pre[u]){
   sccnum ++;
   while(!s.empty() && pre[s.top()] >= pre[u]){
      sccno[s.top()] = sccnum;
      s.pop();
   }
  }
}

void find_scc(){
  memset(pre, 0, sizeof(pre));
  memset(link, 0, sizeof(link));
  memset(sccno, 0, sizeof(sccno));
  dfs_clock = sccnum = 0;
  for(int i = 1; i <= n; i ++){
    if(pre[i] == 0) dfs(i);
  }
}

int main()
{
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < maxn; i ++){
      G[i].clear();
    }
    for(int i = 1; i <= n; i ++){
      scanf("%d", &k);
      for(int j = 0; j < k; j ++){
        scanf("%d", &x);
        G[i].push_back(x);
      }
    }

   find_scc();
   for(int i = 1; i <= n; i ++){
      printf("%d %d\n", pre[i], sccno[i]);
   }

  }
  return 0;
}



