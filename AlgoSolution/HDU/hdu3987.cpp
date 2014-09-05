/*
    ID: problem6
    PROG : Harry Potter and the Forbidden Forest
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 1000+10;
const int MaxE = 1000000+1;
//const LL inf = 0x3f3f3f3f3f3f3f3f;
const LL inf = (LL)MaxE*(LL)MaxE;
struct Edge{
  int from, to;
  LL cap, flow;
};
vector<int> G[maxn];
vector<Edge> edge;

void Init(){
  edge.clear();
  for(int i = 0; i < maxn; i ++)
    G[i].clear();
}

void add_edge(int from, int to, LL cap){
  Edge e;
  e.from = from, e.to = to, e.cap = cap, e.flow = 0;
  edge.push_back(e);
  e.from = to, e.to = from, e.cap = 0, e.flow = 0;
  edge.push_back(e);
  //edge.push_back((Edge){from, to, cap, 0, 0);
  //edge.push_back((Edge){to, from, 0, 0});
  int m = edge.size();
  G[from].push_back(m-2);
  G[to].push_back(m-1);
}

int cur[maxn];
int vis[maxn];
int d[maxn];

int bfs(int s, int t){
  memset(vis, 0, sizeof(vis));
  d[s] = 0;
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int x = q.front(); q.pop();
    for(int i = 0; i < G[x].size(); i ++){
      Edge& e = edge[G[x][i]];
      if(!vis[e.to] && e.cap > e.flow){
        d[e.to] = d[x] + 1;
        vis[e.to] = 1;
        q.push(e.to);
      }
    }
  }
  /*
  for(int i = s; i <= t; i ++)
    printf("%d", vis[i]);
  printf("\n");
  */
  return vis[t];
}

LL Min(LL a, LL b){
  return a > b ? b : a;
}

LL dfs(int x, LL a, int t){
  if(x == t || a == 0) return a;
  LL f, flow;
  f = flow = 0;
  for(int& i = cur[x]; i < G[x].size(); i ++){
    Edge& e = edge[G[x][i]];
    if(d[e.to] == d[x] + 1 &&
      (f = dfs(e.to, Min(a, e.cap-e.flow), t)) > 0){
      // 赋值运算时最低的运算符，一定要注意
      // 如果一直存在增广路，很有可能反向流没有增加
      e.flow += f;
      edge[G[x][i]^1].flow -= f;
      flow += f;
      a -= f;
      if(a == 0) break;
    }
  }
  return flow;
}

LL Dinic(int s, int t){
    LL MaxFlow = 0;
    while(bfs(s, t)){
      memset(cur, 0, sizeof(cur));
      MaxFlow += dfs(s, inf , t);
    }
    return MaxFlow;
}

int main(){
    int t, n, m;
    scanf("%d", &t);
    for(int test = 1; test <= t; test ++){
      Init();
      scanf("%d%d", &n, &m);
      int a, b, c, d;
      for(int i = 0; i < m; i ++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_edge(a, b, (LL)c*(LL)MaxE+1);
        if(d == 1) add_edge(b, a, (LL)c*(LL)MaxE+1);
      }
      /*
      for(int i = 0; i < n; i ++){
        for(int j = 0; j < G[i].size(); j ++){
          Edge e = edge[G[i][j]];
          printf("%d %d %d %lld %lld\n", i, e.from, e.to, e.cap, e.flow);
        }
      }
      */
      LL ans = Dinic(0, n-1);
      printf("Case %d: ", test);
      cout << ans%MaxE << endl;
    }
    return 0;
}

/*
conclusion:
11211225	2014-07-27 15:46:09	Accepted
3987	1015MS	16536K	2948 B	C++	robotcator
1: 对于移位操作，注意1默认为是32位的所以，如果是左(右)移操作32
必须要显示说明为long long型
2：对于其他计算可能越界的同样处理。
3：不该把时间都花在调试上，所以不要一开始都引入bug
*/
