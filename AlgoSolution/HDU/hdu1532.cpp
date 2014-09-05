/*
    ID: problem6
    PROG : Drainage Ditches
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200+10;
const int inf = 0x3f3f3f3f;

int cap[maxn][maxn];
int n, m;
int flow[maxn][maxn];
int fa[maxn];
queue<int> q;
int a[maxn];

int bfs(int s, int t){
    memset(a, 0, sizeof(a));
    q.push(s);
    fa[s] = s;
    a[s] = inf;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y = 1; y <= m; y ++){
            if(a[y] == 0 && cap[x][y] > flow[x][y]){
                fa[y] = x;
                q.push(y);
                a[y] = min(a[x], cap[x][y]-flow[x][y]);
            }
        }
    }
    return a[t];
}

int Edmond_Karp(int s, int t){
    while(!q.empty()) q.pop();
    memset(flow, 0, sizeof(flow));
    int x, ans;
    ans = x = 0;
    while((x = bfs(s, t))){
        for(int u = t; u != s; u = fa[u]){
            flow[fa[u]][u] += x;
            flow[u][fa[u]] += x;
        }
        ans += x;
    }
    return ans;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        memset(cap, 0, sizeof(cap));
        int x, y, z;
        for(int i = 0; i < n; i ++){
            scanf("%d%d%d", &x, &y, &z);
            cap[x][y] += z;
        }
        int ans = Edmond_Karp(1, m);
        printf("%d\n", ans);
    }
    return 0;
}
/*
conclusion:
11146871	2014-07-23 10:30:06	Accepted
1532	15MS	632K	1448 B	C++	robotcator
不断找增广路
*/
