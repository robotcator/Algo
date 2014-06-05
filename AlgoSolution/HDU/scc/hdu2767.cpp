// Accepted 2767 250MS 2136K
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 20000+10;
int n, m, x, y;
vector<int> G[maxn];
stack<int> s;
int pre[maxn];
int sccno[maxn];
int link[maxn];
int dfs_clock;
int sccnum;

int minn(int a, int b) { return a > b ? b : a ;}

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
      while(!s.empty() && pre[s.top()] >= pre[u]){
        sccno[s.top()] = sccnum;
        s.pop();
      }
    }
}

void find_cc(){
  memset(pre, 0, sizeof(pre));
  memset(sccno, 0, sizeof(sccno));
  memset(link, 0, sizeof(link));
  dfs_clock = sccnum = 0;
  for(int i = 1; i <= n; i ++){
    if(pre[i] == 0) dfs(i);
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < maxn; i ++) G[i].clear();

    for(int i = 0; i < m; i ++){
      scanf("%d%d", &x, &y);
      G[x].push_back(y);
    }
    find_cc();
    //for(int i = 1; i <= n; i ++){
    //  cout << sccno[i] << " ";
    //}
    //cout << endl;

    int din[maxn], dout[maxn];
    for(int i = 1; i <= sccnum; i ++)
      din[i] = dout[i] = 1;
    // 所有的出入度均为零
    for(int i = 1; i <= n; i ++){
      for(int j = 0; j < G[i].size(); j ++){
        int v = G[i][j];
        //  对于每条边，如果连接着不同的联通分量，则修改出入度
        if(sccno[i] != sccno[v]) din[sccno[v]] = dout[sccno[i]] = 0;
        // 不需要统计出入度为多少
      }
    }

    int a, b;
    a = b = 0;
    for(int i = 1; i <= sccnum; i ++){
      if(din[i]) a ++;
      if(dout[i]) b ++;
    }
    if(sccnum == 1){
      printf("%d\n", 0);
      // 如果只有一个连通分量，出度为零的个数有一个，同理入读也一样
    }
    else{
      printf("%d\n", a > b ? a : b);
    }

  }
  return 0;
}
