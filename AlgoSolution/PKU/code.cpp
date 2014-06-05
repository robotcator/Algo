/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int lis(unsigned long long *data, int n){
  unsigned long long dp[10005];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  int rec[10005];
  for(int i = 1; i < n; i ++){
      int maxn = 0;
    for(int j = 0; j < i; j ++){
      if(data[i] >= data[j] && (dp[j] > maxn)){
        maxn = dp[j];
      }
    }
    dp[i] = maxn + 1;
  }
  int maxn = 0, flag = -1;
  for(int i = 0; i < n; i ++)
    if(dp[i] > maxn) {
        maxn = dp[i];
        flag = i;
    }
  cout << maxn << " ";
  int res = maxn;
  rec[--maxn] = flag;
  int last = flag;
  for(int i = flag-1; i >= 0; i --){
      if(dp[i] == maxn && data[i] <= data[last]){
        rec[--maxn] = i;
        last = i;
      }
  }
  for(int i = 0; i < res-1; i ++)
    cout << data[rec[i]] << " ";
  cout << data[rec[res-1]] << endl;

}

int main()
{
    int n;
    unsigned long long data[10005];
    while(scanf("%d", &n) != EOF){
      for(int i = 0; i < n; i ++){
        cin >> data[i];
      }
    lis(data, n);
  }
  return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const long long inf = (1<<60);
long long gaze[1005][1005];

void solve(int v, int e, int src){
  long long dist[1005];
  int vis[1005];
  memset(vis, 0, sizeof(vis));

  for(int i = 0; i < v; i ++) dist[i] = gaze[src][i];
  vis[src] = 1;
  dist[src] = 0;
  int minn;
  int pre = src;

  for(int i = 1; i < v; i ++){
   for(int j = 0; j < v; j ++){
      if(vis[j] == 0  && dist[j] > dist[pre]+gaze[pre][j]) {
            dist[j] = dist[pre] + gaze[pre][j];
      }
   }
   minn = inf;
    for(int j = 0; j < v; j ++){
      if(vis[j] == 0 && dist[j] < minn)
        minn = dist[j];
        pre = j;
    }
    vis[pre] = 1;
  }
  int ans = 0, flag;
  for(int i = 0; i < v; i ++)
    if(vis[i] == 0) flag = 1;
  if(flag == 1){
    for(int i = 0; i < v; i ++)
      if(ans > dist[i])
       ans = dist[i];
    cout << ans << endl;
  }
}

int main()
{
  int v, e, s;
  while(scanf("%d%d%d", &v, &e, &s) != EOF){
    int x, y, w;
    for(int i = 0; i < v; i ++){
      for(int j = 0; j < v; j ++){
        gaze[i][j] = inf;
      }
    }
    for(int i = 0; i < e; i ++){
      scanf("%d%d%d", &x, &y, &w);
      if(w < gaze[x][y]) gaze[x][y] = gaze[y][x] = w;
      if(x == y) gaze[x][y] = inf;
    }
    solve(v, e, s);
  }
  return 0;
}
*/

/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const long long inf = 100000000000;
long long gaze[1005][1005];

void solve(int v, int e, int src){
  long long dist[1005];
  int vis[1005];
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < v; i ++)
    dist[i] = (i == src) ? 0 : gaze[src][i];

  vis[src] = 1;
  int minn;
  int pre = src;

  for(int i = 1; i < v; i ++){
      //枚举节点的个数
      minn = inf;
    for(int j = 0; j < v; j ++){
      if(vis[j] == 0 && dist[j] > dist[pre] + gaze[pre][j])
        dist[j] = dist[pre] + gaze[pre][j];
     }

     for(int j = 0; j < v; j ++){
      if(vis[j] == 0 && (dist[j] < minn)){
        minn = dist[j];
        pre = j;
      }
     }
    vis[pre] = 1;
  }
  int flag = 0, maxn = 0;
  for(int i = 0; i < v; i ++)
    if(vis[i] == 0) flag = 1;
  if(flag == 1){
    printf("INFINITY\n");
  }
  else{
    for(int i = 0; i < v; i ++)
      if(maxn < dist[i]) maxn = dist[i];
    cout << maxn << endl;
  }
}

int main()
{
  int v, e, s;
  while(scanf("%d%d%d", &v, &e, &s) != EOF){
    int x, y, w;
    for(int i = 0; i < v; i++){
      for(int j = 0; j < v; j ++)
        gaze[i][j] = inf;
    }
    for(int i = 0; i < e; i ++){
      scanf("%d%d%d", &x, &y, &w);
      if(gaze[x][y] > w)
        gaze[x][y] = gaze[y][x] = w;
    }
    solve(v, e, s);
  }
  return 0;
}
*/


