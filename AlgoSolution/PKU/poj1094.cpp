#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

const int maxn = 30;
int graph[maxn][maxn];
int m, n;
int din[maxn];
int vis[maxn];
stack<int> s;

int topo_sort(){
  while(!s.empty()) s.pop();
  memset(din, 0, sizeof(din));
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      if(graph[i][j] > 0)
      din[j] ++;
    }
  }
  for(int i = 1; i <= n; i ++)
    if(din[i] == 0) {
        s.push(i);
        vis[i] = 1;
    }
  int cnt = 0;
  if(s.size() >= 2) return 1;
  // 出现度数为零的点多于一个
  while(!s.empty()){
    int v = s.top();
    s.pop();
    cout << v << endl;
    cnt ++;
    for(int i = 1; i <= n; i ++){
      if(graph[v][i] > 0) din[i] --;
      if(din[i] == 0 && vis[i] == 0){
          s.push(i);
          vis[i] = 1;
      }
    }
    //cout << s.size() << endl;
    if(s.size() >= 2) return 1;
  }
  cout << cnt << endl;
  if(cnt < n) return 2;
  // 有环
  else return 3;
  // 可以排序
}

int main()
{
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    memset(graph, 0, sizeof(graph));
    char x, y, z;
    getchar();
    for(int i = 1; i <= m; i ++){
      scanf("%c%c%c", &x, &z, &y);
      getchar();
      graph[x-'A'+1][y-'A'+1] = 1;
    }
    /*
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        cout << graph[i][j] << " ";
      }
      cout << endl;
    }
    */
    int ans = topo_sort();
    if(ans == 1) printf("Sorted sequence cannot be determined.\n");
    else if(ans == 2) printf("Inconsistency found after 2 relations.\n");
    else if(ans == 3) printf("Sorted sequence determined after 4 relations: ABCD.\n");

  }
  return 0;
}
