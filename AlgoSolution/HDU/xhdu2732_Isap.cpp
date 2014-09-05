  /*
      ID: problem6
      PROG : Leapin' Lizards
      LANG : C++
  */
  #include <cstdio>
  #include <iostream>
  #include <queue>
  #include <cstring>
  #include <vector>
  #include <algorithm>

  using namespace std;

  const int maxn = 21;
  const int inf = 0x3f3f3f3f;
  char Pilar[maxn][maxn];
  char Lizard[maxn][maxn];
  int flag[maxn][maxn];
  int k; // 柱子的数量
  int num;
  int n, m;
  struct Edge{
      int from, to, cap, flow;
  };
  vector<Edge> edge;
  vector<int> G[2*maxn*maxn];

  void init(){
      edge.clear();
      for(int i = 0; i < 2*maxn*maxn; i ++){
          G[i].clear();
      }
      memset(flag, 0, sizeof(flag));
  }

  void add_edge(int from, int to, int cap, int flow){
      edge.push_back((Edge){from, to, cap, flow});
      edge.push_back((Edge){to, from, 0, 0});
      int m = edge.size();
      G[from].push_back(m-2);
      G[to].push_back(m-1);
  }

  // Dinic 函数
  int vis[2*maxn*maxn];
  int d[2*maxn*maxn];
  int cur[2*maxn*maxn];

  bool bfs(int s, int t){
      memset(vis, 0, sizeof(vis));
      queue<int> q;
      q.push(s);
      d[s] = 0;
      vis[s] = 1;
      while(!q.empty()){
          int x = q.front(); q.pop();
          for(int i = 0; i < G[x].size(); i ++){
              Edge& e = edge[G[x][i]];
              if(!vis[e.to] && e.cap > e.flow){
                  q.push(e.to);
                  vis[e.to] = 1;
                  d[e.to] = d[x] + 1;
              }
          }
      }
      return vis[t];
  }

  int dfs(int x, int a, int t){
      if(x == t || a == 0) return a;
      int f, flow;
      f = flow = 0;
      for(int& i = cur[x]; i < G[x].size(); i ++){
          Edge& e = edge[G[x][i]];
          if(d[e.to] == d[x]+1 && (f = dfs(e.to, min(a, e.cap-e.flow), t)) > 0){
              //edge[G[x][i]].flow += f;
              e.flow += f;
              edge[G[x][i]^1].flow -= f;
              flow += f;
              a -= f;
              if(a == 0) break;
          }
      }
      return flow;
  }

  int Dinic(int s, int t){
      int MaxFlow = 0;
      while(bfs(s, t)){
          memset(cur, 0, sizeof(cur));
          MaxFlow += dfs(s, inf, t);
      }
      return MaxFlow;
  }

  bool is_safe(int x, int y, int d){
      //cout << n << m << endl;
      //注意从0开始的图的上下界
      if(x-d < 0 || x+d >= n || y-d < 0 || y+d >= m) return true;
      else return false;
  }

  int dist(int i, int j, int x, int y){
    return abs(i-x) + abs(j-y);
  }

  void build_graph(int d, int src, int des){
      num = 0;
      for(int i = 0; i < n; i ++){
          for(int j = 0; j < m; j ++){
              // 能出去的柱子
              if(Pilar[i][j] != '0'){
                  add_edge(flag[i][j], flag[i][j]+k, Pilar[i][j]-'0', 0);
                  if(is_safe(i, j, d)) {
                      //cout << i << j << endl;
                      add_edge(flag[i][j]+k, des, inf, 0);
                  }
                  // 对柱子能leap次数进行约束
              }
              if(Lizard[i][j] == 'L'){
                num ++;
                add_edge(src, flag[i][j], 1, 0);
              }
          }
      }
      for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
          if(Pilar[i][j] > '0'){
            for(int k1 = 0; k1 < n; k1 ++){
              for(int k2 = 0; k2 < m; k2 ++){
               if(k1 == i && k2 == j) continue;
               if(dist(i, j, k1, k2) <= d && Pilar[k1][k2] > '0'){
                  //cout << i << j << " ";
                  //cout << k1 << k2 << endl;
                  add_edge(flag[i][j]+k, flag[k1][k2], inf, 0);
               }
              }
            }
          }
        }
      }
      /*
      // 如何调试建图的正确性
      for(int i = 0; i < G[src].size(); i ++){
        Edge e = edge[G[src][i]];
        printf("%d %d %d\n", src, e.to, e.cap);
      }
      // 调源点和汇点
      printf("\n");
      for(int i = 0; i < G[des].size(); i ++){
        Edge e = edge[G[des][i]];
        printf("%d %d %d\n", e.from, e.to, e.cap);
      }
      printf("\n");
      for(int i = 0; i < src; i ++){
        for(int j = 0; j < G[i].size(); j ++){
          Edge e = edge[G[i][j]];
          if(e.cap != 0) printf("%d %d %d\n", e.from, e.to, e.cap);
        }
      }
      */
  }

  int main(){
      int t, d;
      scanf("%d", &t);
      for(int test = 1; test <= t; test ++){
          init();
          scanf("%d%d", &n, &d);
          k = 0;
          for(int i = 0; i < n; i ++){
              scanf("%s", Pilar[i]);
              m = strlen(Pilar[0]);
              for(int j = 0; j < m; j ++){
                if(Pilar[i][j] != '0') flag[i][j] = k ++;
              }
          }
          for(int i = 0; i < n; i ++)
              scanf("%s", Lizard[i]);
          int src, des;
          src = 2*k;
          des = src+1;
          // 超级源点，超级汇点
          build_graph(d, src, des);
          int ans = Dinic(src, des);
          //cout << num << " " << ans << endl;
          printf("Case #%d: ", test);
          ans = num-ans;
          if(ans == 1) printf("%d lizard was left behind.\n", ans);
          else if(ans == 0) printf("no lizard was left behind.\n");
          else printf("%d lizards were left behind.\n", ans);
      }
      return 0;
  }
