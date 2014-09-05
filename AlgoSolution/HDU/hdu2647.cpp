/*
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> G[10005];
int deg[10005];
int Min[10005];
int vis[10005];

int topo(int deg[], int n)
{
    int flag = 0;
    int k = 0;  // 标记名次
    stack<int> s;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
         if(deg[i] == 0){
            vis[i] = 1;
            s.push(i);
            Min[i] = k;
            flag = 1;
         }
    }
    k ++;
    if(flag == 0) return -1;
    while(!s.empty()){
     //   cout << s.top() << endl;
        for(int i = 0; i < G[s.top()].size(); i ++){
            deg[G[s.top()][i]] --;
        }
        s.pop();
        flag = 0;
        for(int i = 1; i <= n; i ++){
            if(vis[i] == 0 && deg[i] == 0){
                vis[i] = 1;
                s.push(i);
                Min[i] = k;
                flag = 1;
            }
        }
    //    if(flag == 0) return -1;
        k ++;
    }
    if(!s.empty()) return -1;
    else return 0;
}

int main()
{
    int n, m;
    int x, y;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < 10005; i ++)
            G[i].clear();           // 注意要清零
        for(int i = 0; i < m; i ++){
            scanf("%d%d", &x, &y);
            G[y].push_back(x);
        }
        memset(deg, 0, sizeof(deg));
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < G[i].size(); j ++){
        //             printf("~%d\n", G[i][j]);
                    deg[G[i][j]] ++;
            }
        }
      //  for(int i = 1; i <= n; i ++)
      //      printf("~%d\n", deg[i]);
        int ans = topo(deg, n);
        if(ans == -1) printf("-1\n");
        else {
            int res = 0;
            for(int i = 1; i <= n; i ++)
                res += Min[i];
            printf("%d\n",res + n*888);
        }
    }
    return 0;
}

*/
// 为什么改用stack不行
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[10005];
int deg[10005];
int Min[10005];

void topo(int n)
{
    queue<int> s;
    int num = 0;
    memset(Min, 0, sizeof(Min));
    for(int i = 1; i <= n; i ++){
         if(deg[i] == 0){
            s.push(i);
         }
    }
    while(!s.empty()){
      //  cout << s.front() << endl;
      // 里面循环了n次
        int x = s.front();
        s.pop();
        num ++;
        for(int i = 0; i < G[x].size(); i ++){
            int u = G[x][i];
            if(--deg[u] == 0){
                s.push(u);
                Min[u] = Min[x] + 1;
            }
        }
    }
    //printf("ans=%d\n", ans);
    if(num != n) printf("-1\n");
    else {
        int res = 0;
        for(int i = 1; i <= n; i ++)
            res += Min[i];
        printf("%d\n",res + n*888);
    }
}

int main()
{
    int n, m;
    int x, y;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i <= n; i ++){
            G[i].clear();           // 清零
            deg[i] = 0;
        }
        for(int i = 0; i < m; i ++){
            scanf("%d%d", &x, &y);
            G[y].push_back(x);
            deg[x] ++;          // 输入即可记录度数
        }
        topo(n);
    }
    return 0;
}
