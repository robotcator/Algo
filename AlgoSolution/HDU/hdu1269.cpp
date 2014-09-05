// 31MS 1344K 1755 B
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
1 2
2 3
2 8
3 4
3 7
4 5
5 6
5 3
7 4
7 6
8 1
8 7
*/

const int maxn = 10000+10;
int n, m;
vector<int> G[maxn];
stack<int> s;
int link[maxn];
// 从u及其后代能回到最早祖先的pre值（其实就pre最小的值）
int sccno[maxn];
// 所属连通分量
int pre[maxn];
// 开始的时间戳，也用来做标记
int dfs_clock;
// 时间
int sccnum;
// 连通分量的个数

int minn(int a, int b) { return a > b ? b : a; }

void dfs(int u){
  pre[u] = link[u] = ++dfs_clock;
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
      if(sccnum >= 2) {
          printf("No\n");
          return ;
      // 剪枝简直没有任何影响
      }
      while(!s.empty() && pre[s.top()] >= pre[u]){
        //cout << s.top() << " ";
        sccno[s.top()] = sccnum;
        s.pop();
      }
      //cout << endl;
  }

}

void find_scc(){
  dfs_clock = sccnum = 0;
  memset(pre, 0, sizeof(pre));
  memset(sccno, 0, sizeof(sccno));
  for(int i = 1; i <= n; i ++){
    if(pre[i] == 0) dfs(i);
  }
}

int main()
{
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    int a, b;
    for(int i = 0; i < maxn; i ++){
      G[i].clear();
    }
    for(int i = 0; i < m; i ++){
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
    }
    find_scc();
    if(sccnum == 1)
      printf("Yes\n");
    /*
    cout << sccnum << endl;
    for(int i = 1; i <= n; i ++){
      cout << pre[i] << " " << sccno[i] << endl;
    }
    */
  }
  return 0;
}
