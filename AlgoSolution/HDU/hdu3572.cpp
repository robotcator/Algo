/*
    ID: problem6
    PROG : Task Schedule
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 500+10;
struct Edge{
    int from, to, cap, flow;
    // flow 为流量， cap为容量
};
vector<Edge> edge;
vector<int> G[2*maxn];

void init(){
    edge.clear();
    for(int i = 0; i < 2*maxn; i ++)
        G[i].clear();
}

void add_edge(int from, int to, int cap){
    //Edge e = {from, to, cap, 0};
    edge.push_back((Edge){from, to, cap, 0});
    //e.from = to, e.to = from, e.cap = e.flow = 0;
    edge.push_back((Edge){to, from, 0, 0});
    int m = edge.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

int d[2*maxn];
int vis[2*maxn];
int cur[2*maxn];

int bfs(int s, int t){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0; i < G[x].size(); i ++){
            Edge& e = edge[G[x][i]];
            if(vis[e.to] == 0 && e.cap > e.flow){
                q.push(e.to);
                vis[e.to] = 1;
                d[e.to] = d[x] + 1;
            }
        }
    }
    return vis[t];
}

int dfs(int x, int a, int t){
    if(x == t || a == 0) return a;
    int flow, f;
    flow = f = 0;
    for(int& i = cur[x]; i < G[x].size(); i ++){
        Edge& e = edge[G[x][i]];
        if(d[x]+1 == d[e.to] && (f = dfs(e.to, min(a, e.cap-e.flow), t)) > 0){
            e.flow += f;
            edge[G[x][i]^1].flow -= f;
            flow += f;
            a -= f;
            if(a == 0) break;
        }
    }
    return flow;
}
/*
int st[2*maxn];
int top = 0;
// 模拟栈
int Dfs(int s, int t){
    int cur = s;
    memset(st, 0, sizeof(st));
    st[top++] = s;
    while(top >= 0){
        if(st[top-1] == t){
            int minx = inf;
            for(int i = top-1; i >= 1; i ++){
                Edge e =
                minx = min(minx, )
                // 这种数据结构不好用
            }
            // 寻找路径中流量最小的值

        }else{
            for(int i = 0; i < G[cur].size(); i ++){
              Edge e = edge[G[cur][i]];
              if(d[cur] + 1 = d[e.to] && )
            }
        }
    }
}
*/
int Dinic(int s, int t){
    int MaxFlow = 0;
    while(bfs(s, t)){
        memset(cur, 0, sizeof(cur));
        MaxFlow += dfs(s, inf, t);
    }
    return MaxFlow;
}

int main(){
    int t, m, n;
    scanf("%d", &t);
    for(int test = 1; test <= t; test ++){
        init();
        scanf("%d%d", &n, &m);
        int p, s, e;
        // 1-n为机器节点
        int ed = 0;
        // 最后结束时间
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%d%d%d", &p, &s, &e);
            sum += p;
            ed = ed < e ? e : ed;
            add_edge(0, i, p);
            for(int j = s; j <= e; j ++){
                add_edge(i, n+j, 1);
            }
        }
        int des = n+ed+1;
        for(int i = 1; i <= ed; i ++)
            add_edge(i+n, des, m);
        int ans = Dinic(0, des);
        /*
        for(int i = 0; i <= des; i ++){
            for(int j = 0; j < G[i].size(); j ++){
                Edge e = edge[G[i][j]];
                printf("%d %d %d %d\n", i, e.from, e.to, e.cap);
            }
        }
        */

        printf("Case %d: ", test);
        if(ans == sum) printf("Yes\n");
        else printf("No\n");
        printf("\n");
    }
    return 0;
}

/*
conclusion:
11156569	2014-07-23 17:40:32	Accepted
3572	203MS	5524K	3051 B	G++	robotcator
*/
