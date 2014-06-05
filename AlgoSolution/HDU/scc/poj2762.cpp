  // 单连通图，而不是弱连通图
  // 因为需要找到一条路径，可以贯穿所有的节点(压缩以后的节点
  #include <cstdio>
  #include <cstring>
  #include <iostream>
  #include <vector>
  #include <stack>
  #include <queue>
  using namespace std;

  const int maxn = 1000+10;
  vector<int> G[maxn];
  int n, m;
  int pre[maxn];
  int link[maxn];
  int sccno[maxn];
  int dfs_clock, sccnum;
  stack<int> s;

  vector<int> newG[maxn];
  int din[maxn], dout[maxn];
  int vis[maxn];

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

    if(pre[u] == link[u]){
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
    for(int i = 1; i <= n; i ++)
      if(pre[i] == 0) dfs(i);
  }


  bool topo_sort(int sccnum){
    int cnt = 0;
    queue<int> q;
    while(!q.empty()) q.pop();

    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= sccnum; i ++){
      if(din[i] == 0){
        q.push(i);
      }
    }
    if(q.size() >= 2) return false;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      cnt ++;
      //cout << G[v].size() << endl;
      for(int i = 0; i < newG[v].size(); i ++){
        int x = newG[v][i];
        // 不要新图，旧图不分
        din[x] --;
        //cout << x << " " << din[x] << endl;
        if(din[x] == 0){
          q.push(x);
        }
      }
      if(q.size() >= 2) return false;
    }
    if(cnt < sccnum) return false;
    else return true;
  }

  int main()
  {
    int t;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--){
      // 要对数据初始化，特别是全局变量，vector， stack等
      for(int i = 0; i < maxn; i ++){
        G[i].clear();
        newG[i].clear();
      }
      scanf("%d%d", &n, &m);
      int x, y;
      for(int i = 0; i < m; i ++){
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
      }
      /*
      for(int i = 1; i <= n; i ++){
        for(int j = 0; j < G[i].size(); j ++){
          cout << G[i][j] << " ";
        }
        cout << endl;
      }
      */
      find_scc();
      /*
      for(int i = 1; i <= n; i ++)
        cout << sccno[i] << " ";
      cout << endl;
      */
      memset(din, 0, sizeof(din));
      memset(dout, 0, sizeof(dout));
      for(int i = 1; i <= n; i ++){
        for(int j = 0; j < G[i].size(); j ++){
          int v = G[i][j];
          if(sccno[i] != sccno[v]){
            //cout << i << G[i][j] << "x";
            newG[sccno[i]].push_back(sccno[v]);
          }
        }
      }
      for(int i = 1; i <= sccnum; i ++){
        for(int j = 0; j < newG[i].size(); j ++){
          //printf("%d ", newG[i][j]);
          //cout << i << newG[i][j] << " ";
          int v = newG[i][j];
          dout[i] ++;
          din[v] ++;
        }
        //printf("\n");
      }
      //cout << endl;

      /*
      for(int i = 1; i <= sccnum; i ++)
        cout << din[i] << " ";
      cout << endl;
      */
      bool ans = topo_sort(sccnum);
      if(!ans) printf("No\n");
      else printf("Yes\n");
    }
    return 0;
  }
