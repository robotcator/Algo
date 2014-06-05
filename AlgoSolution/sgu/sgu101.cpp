// 1561231	10.05.14 18:42	robotcator	101 	.CPP	Accepted 	15 ms	190 kb
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

const int maxn = 100+10;
struct node{
  int u, tag;
};
vector<node> G[8];
stack<int> rec;

int vis[maxn];
int deg[maxn];
int num ;// 欧拉回路的边数

void Init(){
  memset(vis, 0, sizeof(vis));
  memset(deg, 0, sizeof(deg));
  for(int i = 0; i < 8; i ++){
    G[i].clear();
  }
  while(!rec.empty()) rec.pop();
}

bool dfs(int u){
  for(int v = 0; v < G[u].size(); v ++){
      node temp = G[u][v];
      //cout << temp.tag << endl;
      if(vis[abs(temp.tag)] == 0){
        vis[abs(temp.tag)] = 1;
        dfs(temp.u);
        //printf("%d %d %d\n", u, temp.u, temp.tag);
        rec.push(temp.tag);
        num ++;
      }
  }
}

int main(){
  int n, a, b;
  while(scanf("%d", &n) != EOF){
    Init();
    for(int i = 1; i <= n; i ++){
      scanf("%d%d", &a, &b);
      node temp;
      temp.u = b, temp.tag = i;
      G[a].push_back(temp);
      temp.u = a, temp.tag = -i;
      G[b].push_back(temp);
      deg[a] ++;  deg[b] ++;
    }
    //for(int i = 0; i <= 6; i ++)
    //  cout << deg[i] << endl;
    int st = 0; // 欧拉路径起始位置
    int cnt = 0; //  统计度数为奇数的数目
    for(int i = 0; i <= 6; i ++){
      if(deg[i] != 0) st = i;
    }
    // 数据(有环)
    // 2
    //  1 2
    //  2 1
    for(int i = 0; i <= 6; i ++){
      if(deg[i] % 2 == 1) { cnt ++; st = i; }
    }
    // printf("%d\n\n", st);
    if(cnt > 2) printf("No solution\n");
    else {
      num = 0;
      dfs(st);
      if(num < n) printf("No solution\n");
      else {
        while(!rec.empty()){
          int x = rec.top(); rec.pop();
          if(x > 0) printf("%d +\n", x);
          else printf("%d -\n", -x);
        }
      }
    }
  }
  return 0;
}
