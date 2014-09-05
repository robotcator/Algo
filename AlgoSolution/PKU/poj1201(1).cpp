// Accepted 6736K 1625MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 50000+10;
int Max, Min, n;
int a[maxn], b[maxn], c[maxn];
int d[maxn];
int inq[maxn];
// 判断是否在队列中
int cnt[maxn];
// 判断入队的次数
// bellman_ford用邻接表存储
struct edge{
  int from, to, cost;
};
vector<edge> E;
vector<int> G[maxn];
/*
  0 <= s(i)-s(i-1) <= 1
  s(bi) - s(ai)-1 <= c(i)
*/

void init(){
  E.clear();
  for(int i = 0; i < maxn; i ++){
    G[i].clear();
  }
}

void add_edge(int u, int v, int cost){
  edge temp;
  temp.from = u, temp.to = v, temp.cost = cost;
  E.push_back(temp);
  G[u].push_back(E.size()-1);
}

bool spfa(int src, int des){
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    queue<int> q;
    for(int i = 0; i <= des; i ++){
      d[i] = inf;
    }
    d[0] = 0;
    inq[0] = 1;
    q.push(0);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i ++){
        edge temp = E[G[u][i]];
        if(d[temp.to] > d[u] + temp.cost){
          d[temp.to] = d[u] + temp.cost;
          if(!inq[temp.to]){
            q.push(temp.to);
            cnt[temp.to] ++;
            inq[temp.to] = 1;
            if(cnt[temp.to] > des-src+1) return false;
          }
        }
      }
    }
    return true;
}


int main()
{
  while(scanf("%d", &n) != EOF){
    Max = -1;
    Min = maxn;
    init();
    for(int i = 1; i <= n; i ++){
      scanf("%d%d%d", &a[i], &b[i], &c[i]);
      add_edge(b[i]+1, a[i], -c[i]);
      if(b[i]+1 > Max) Max = b[i]+1;
    }
    // 仅仅只是编号
    for(int i = 1; i < Max; i ++){
      //add_edge(0, i, 0);
      add_edge(i, i+1, 1);
      add_edge(i+1, i, 0);
    }
    add_edge(0, Max, 0);
    /*
    cout << Max << endl;
    for(int i = 0; i < E.size(); i ++)
      cout << E[i].from << " " << E[i].to << " " << E[i].cost << endl;

    for(int i = Min; i <= Max; i ++){
      for(int j = 0; j < G[i].size(); j ++){
        cout << i << " " << E[G[i][j]].from << " " << E[G[i][j]].to << " " <<
        E[G[i][j]].cost  << endl;
      }
    }
    */

    spfa(0, Max);
    //for(int i = 0; i <= Max; i ++)
    //  cout << d[i] << endl;

    cout << d[Max]-d[1] << endl;
  }
  return 0;
}
