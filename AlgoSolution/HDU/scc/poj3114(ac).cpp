// Accepted 2232K 235MS
// 学会找数据，如何调试，话说急功近利都忘记改怎么调试了
// 本算法分两部分，主要是看那部分出错
// 还有就是随机数要注意取余不能为零所以要注意技巧
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int maxn = 500+10;
const int inf = 0x3f3f3f3f;
int gaze[maxn][maxn];
int n, m;
int sccno[maxn];
int link[maxn];
int pre[maxn];
int dfs_clock, sccnum;
// 时间戳和连通分量的分数
stack<int> s;

int ngaze[maxn][maxn];
//缩点后的连通图
struct Hnode{
  int v, dist;
  bool operator < (const Hnode a) const{
    return dist > a.dist;
  }
};
int d[maxn];
int vis[maxn];

int minn(int a, int b) { return a > b ? b : a; }

void dfs(int u){
  pre[u] = link[u] = ++dfs_clock;
  s.push(u);

  for(int i = 1; i <= n; i ++){
    if(gaze[u][i] < inf){
      if(pre[i] == 0){
        dfs(i);
        link[u] = minn(link[u], link[i]);
      }
      else if(sccno[i] == 0){
        link[u] = minn(link[u], pre[i]);
      }
    }
  }

  if(link[u] == pre[u]){
    sccnum ++;
    while(!s.empty() && pre[s.top()] >= pre[u]){
      // 还需要判定,每一步都不能有错，所以拼接的时候一定要分块调试
      // 对于tarjan算法还是不熟练
      sccno[s.top()] = sccnum;
      s.pop();
    }
  }
}

void find_scc(){
  dfs_clock = sccnum = 0;
  memset(sccno, 0, sizeof(sccno));
  memset(pre, 0, sizeof(pre));
  memset(link, 0, sizeof(link));
  for(int i = 1; i <= n; i ++)
    if(pre[i] == 0) dfs(i);
}

void dijkstra(int src, int num){
  memset(vis, 0, sizeof(vis));
  memset(d, inf, sizeof(d));
  d[src] = 0;
  priority_queue<Hnode> q;
  Hnode temp;
  temp.v = src, temp.dist = 0;
  q.push(temp);
  while(!q.empty()){
    Hnode cur = q.top();
    q.pop();
    if(vis[cur.v] == 1) continue;
    vis[cur.v] = 1;
    for(int i = 1; i <= num; i ++){
      if(ngaze[cur.v][i] < inf){
        if(d[i] > d[cur.v] + ngaze[cur.v][i]){
          d[i] = d[cur.v] + ngaze[cur.v][i];
          Hnode next;
          next.v = i, next.dist = d[i];
          q.push(next);
        }
      }
    }
  }
}

int main()
{
  //freopen("in.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0) break;
    memset(gaze, inf, sizeof(gaze));
    int x, y, c;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &x, &y, &c);
      if(gaze[x][y] > c)
        // 看到有多条边的尽量去除重边
        gaze[x][y] = c;
    }
    find_scc();
    /*
    for(int i = 1; i <= n; i ++){
      cout << sccno[i] << " ";
    }
    cout << endl;
    */
    memset(ngaze, inf, sizeof(ngaze));
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        if(sccno[i] != sccno[j] && ngaze[sccno[i]][sccno[j]] > gaze[i][j]){
          ngaze[sccno[i]][sccno[j]] = gaze[i][j];
        }
      }
    }
    // 缩点操作,没有错误，强连通图出错
    /*
    for(int i = 1; i <= sccnum; i ++){
      for(int j = 1; j <= sccnum; j ++){
        printf("%d ", ngaze[i][j]);
      }
      printf("\n");
    }
    */
    int q, a, b;
    scanf("%d", &q);
    for(int i = 1; i <= q; i ++){
      scanf("%d%d", &a, &b);
      if(sccno[a] == sccno[b]) printf("0\n");
      else {
          dijkstra(sccno[a], sccnum);
          if(d[sccno[b]] < inf)
            printf("%d\n", d[sccno[b]]);
          else printf("Nao e possivel entregar a carta\n");
      }
    }
    printf("\n");
  }
  return 0;
}
