// Accepted	308K	391MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int maxn = 100+10;
const int inf = 0x3f3f3f3f;

struct edge{
  int u, v, cost;
};
vector<edge> E;

int cmp(edge a, edge b){
  return a.cost < b.cost;
}

int Set[maxn];
int Find(int x){ return x == Set[x] ? x : Set[x] = Find(Set[x]); }
void Union(int x, int px, int y, int py) { Set[px] = py; }

int kurskal(int n, int index){
  // index 枚举最小边
  for(int i = 1; i <= n; i ++)
    Set[i] = i;
  int maxm = 0;
  int cnt = 0; // 统计生成树的边
  int cost = 0;
  for(int i = index; i < E.size(); i ++){
    int px = Find(E[i].u);
    int py = Find(E[i].v);
    if(px != py){
      Union(E[i].u, px, E[i].v, py);
      cnt ++;
      cost += E[i].cost;
      if(E[i].cost > maxm) maxm = E[i].cost;
    }
  }
  if(cnt == n-1) return maxm;
  // 返回最大边
  else return -1;
}

int main(){
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    E.clear();
    // 要初始化
    for(int i = 0; i < m; i ++){
      edge temp;
      scanf("%d%d%d", &temp.u, &temp.v, &temp.cost);
      E.push_back(temp);
    }
    sort(E.begin(), E.end(), cmp);
    int ans = inf;
    for(int i = 0; i < m; i ++){
      int temp = kurskal(n, i);
      // cout << temp << endl;
      if(temp != -1 && temp - E[i].cost < ans) {
          ans = temp - E[i].cost;
      }
    }
    if(ans != inf) printf("%d\n", ans);
    else printf("-1\n");
  }
  return 0;
}
