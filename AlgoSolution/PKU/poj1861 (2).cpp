#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
struct Edge{
  int x, y, w;
};

Edge edge[15005];
int Uset[1005];
int vis[15005];

int cmp(Edge a, Edge b){
  return a.w < b.w;
}

int find(int x){
  return Uset[x] == x ? x : Uset[x] = find(Uset[x]);
}

void kruskal(int  n, int m){
  for(int i = 1; i <= n; i ++) Uset[i] = i;
  int maxn = 0; // 记录使用的最大边
  int cnt = 0; // 统计边的数目
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < m; i ++){
      int px = find(edge[i].x);
      int py = find(edge[i].y);
      if(px != py){
        Uset[px] = py;
        if(edge[i].w > maxn) maxn = edge[i].w;
        cnt ++;
        vis[i] = 1;
      }
      // if(cnt == n-1) break;
      // 如果有n-1那么最小生成树则完成
  }
  printf("%d\n%d\n", maxn, cnt);
  for(int i = 0; i < m; i ++)
    if(vis[i] == 1) printf("%d %d\n", edge[i].x, edge[i].y);

}

int main()
{
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
    }
    sort(edge, edge+m, cmp);
    kruskal(n, m);
  }
  return 0;
}
