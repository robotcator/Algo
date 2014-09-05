#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int n, m;
struct edge{
  int u, v, w;
};
vector<edge> E;

int cmp(edge a, edge b){
  return a.w < b.w;
}

int Set[maxn];
int rec[maxn];
// 记录的边的编号
int cnt;
// 记录最小生成树的边的数目
int find(int x){
  return x == Set[x] ? x : Set[x] = find(Set[x]);
}

void Union(int x, int px, int y, int py){
  Set[px] = py;
  // 并查集都写错
}

int kruskal(int index){
  int cost = 0;
  // 最小生成树的代价
  for(int i = 0; i <= n; i ++)
    Set[i] = i;
  int num = 0;
  for(int i = 0; i < E.size(); i ++){
      if(i != index){
        // 去掉删除的边
        int x = E[i].u; int y = E[i].v;
        int px = find(x);
        int py = find(y);
        if(px != py){
          Union(x, px, y, py);
          num ++;
          cost += E[i].w;
          if(index == -1) {
            rec[cnt++] = i;
          // 小技巧只记录第一次的最小生成树，不要影响以后的
          }
        }
      }
  }
  if(num == n-1) return cost;
  else return -1;
}

void Init(){
  memset(rec, 0, sizeof(rec));
  cnt = 0;
  E.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t --){
    scanf("%d%d", &n, &m);
    edge temp;
    Init();
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &temp.u, &temp.v, &temp.w);
      E.push_back(temp);
    }
    sort(E.begin(), E.end(), cmp);
    int cost = kruskal(-1);
    //for(int i = 0; i < cnt; i ++)
    //  cout << rec[i] << endl;
    int ans = -1;
    int flag = 1;
    for(int i = 0; i < cnt; i ++){
      ans = kruskal(rec[i]);
      if(ans == cost) {
          printf("Not Unique!\n");
          flag = 0; break;
      }
    }
    if(flag == 1) printf("%d\n", cost);
  }
  return 0;
}
