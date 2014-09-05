// Accepted	220K	0MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 500+10;
const int inf = 0x3f3f3f3f;
const double eps = 1E-32;

struct Hnode{
  int v, dist;
  bool operator < (const Hnode& a) const{
    return dist > a.dist;
  }
};

struct node{
  int to, cost;
};
// 用来存储图
vector<node> G[maxn];
int vis[maxn];
int d[maxn];
int fa[maxn];

void dijkstra(int src, int n){
  //memset(vis, 0, sizeof(node));
  // 初始化要注意啊啊啊啊啊啊啊 啊啊啊啊啊啊啊
  memset(vis, 0, sizeof(vis));
  memset(d, inf, sizeof(d));
  memset(fa, -1, sizeof(fa));
  priority_queue<Hnode> q;
  Hnode temp;
  temp.v = src, temp.dist = 0;
  q.push(temp);
  d[src] = 0;
  while(!q.empty()){
    Hnode cur = q.top();
    q.pop();
    if(vis[cur.v] != 0) continue;
    vis[cur.v] = 1;
    for(int j = 0; j < G[cur.v].size(); j ++){
      node next = G[cur.v][j];
      if(d[next.to] > d[cur.v] + next.cost){
          d[next.to] = d[cur.v] + next.cost;
          fa[next.to] = cur.v;
          Hnode newnode ;
          newnode.v = next.to , newnode.dist = d[next.to];
          q.push(newnode);
      }
    }
  }
  //for(int i = 1; i <= n; i ++){
  //  cout << i << " " << fa[i] << " " << d[i] << endl;
  //}
}

/*
计算每一行完全倒下的时间。设每一行的两端的关键牌为i 和j，
则这一行完全倒下的时间为
(dist[i] + dist[j] + edge[i][j])/2.0，
(确实可行)如果在同一直线上和不同直线上都行，所以还是的提高数学能力
其中edge[i][j]为连接第i、j 两张关键牌的行倒下
所花的时间。取所有行完全倒下时间的最大值，设为max2
*/

void solve(int n){
  double lastfall = -inf;
  int k = 0;
  for(int i = 1; i <= n; i++){
      if( lastfall < (double)d[i]){
        //有些不通
        lastfall = d[i];
        k = i;
      }
  }
  // 枚举每一条边,求所有边倒下的最大值
  int a, b;
  double bettwen = -inf;
  for(int i = 1; i <= n; i ++){
    for(int j = 0; j < G[i].size(); j ++)
      if((d[i] + d[G[i][j].to] + G[i][j].cost)/2.0 > bettwen){
        bettwen = (d[i]+d[G[i][j].to]+G[i][j].cost)/2.0;
        a = i;
        b = G[i][j].to;
      }
  }
  if(lastfall >= bettwen ){
    printf("The last domino falls after %.1f seconds, at key domino %d.\n", lastfall, k);
    // G++ 用%.1f过   c++ 用.1lf过
    // 一般习惯上都用%lf读入，%f输出
    // MinGW版的gcc和g++尚不支持用"%lf"作为输出
    //C89标准，double类型用"%lf"输入，用"%f"输出。
    //C99标准， double类型用"%lf"输入，用"%lf"输出。
    //然而，某些libc的动态库尚未更新到C99标准，依然沿用C89标准的语法。
  }
  else {
    printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", bettwen, a>b?b:a, a>b?a:b);
  }
  printf("\n");
  //输入输出一定不能错
}

int main()
{
  int n, m;
  int Case = 1;
  //freopen("in.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    for(int i = 0; i <= maxn; i ++){
      G[i].clear();
    }
    int a, b, l;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &a, &b, &l);
      node temp;
      temp.to = b, temp.cost = l;
      G[a].push_back(temp);
      temp.to = a, temp.cost = l;
      G[b].push_back(temp);
    }
    /*
   for(int i = 1; i <= n; i ++){
    for(int j = 0; j < G[i].size(); j ++){
      cout << i << " " << G[i][j].to << " " << G[i][j].cost << endl;
    }
   }
  */
   printf("System #%d\n", Case++);
   dijkstra(1, n);
   solve(n);
  }
  return 0;
}
