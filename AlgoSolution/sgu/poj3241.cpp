// robotcator	3241	Memory Limit Exceeded			C++	1586B
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 10000+10;
const int inf = 0x3f3f3f3f;
struct point{
  int x, y;
};
point P[maxn];

int graph[maxn][maxn];
int n, k;

int dist[maxn];
int vis[maxn];
vector<int> rec;

void Init(){
  memset(P, 0, sizeof(P));
  memset(graph, 0, sizeof(graph));
  memset(dist, inf, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  rec.clear();
}

int prim(){
 for(int i = 0; i < n; i ++) dist[i] = graph[0][i];
 vis[0] = 1;
 rec.push_back(0);
 int cost = 0;
 // 记录生成树的最小值
 for(int i = 1; i < n; i ++){
   int minn = inf;
   int minv = -1;
   for(int j = 0; j < n; j ++)
      if(vis[j] == 0 && dist[j] < minn) { minn = dist[j]; minv = j; }
   // 找出距离前一个节点最近的点
   if(minv == -1) return -1;
   rec.push_back(minv);
   vis[minv] = 1;
   cost += minn;
   for(int j = 0; j < n; j ++){
      if(vis[j] == 0 && graph[minv][j] > 0 && graph[minv][j] < dist[j]) {
        dist[j] = graph[minv][j];
        // 记录路径,自己到自己要算不可达，不能有自环
        //  要么这里判断，要么建图时判断
      }
   }
 }
 return cost;
}

int main(){
  while(scanf("%d%d", &n, &k) != EOF){
    Init();
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &P[i].x, &P[i].y);
    }
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++){
        graph[i][j] = abs(P[i].x - P[j].x) + abs(P[i].y - P[j].y);
      }
    }
    //cout << prim() << endl;
    cout << graph[rec[k]][rec[k+1]] << endl;
  }
  return 0;
}
