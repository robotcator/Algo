 /*
/// 已经优化，时间效率还是慢。
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;

struct Node{
    int to;
    int cost;
};

struct qnode{
    int v;
    int cost;
    bool operator < (const qnode &r) const{
        return cost > r.cost;
    }
};

void init(vector<Node> *G, int n)
{
    for(int i = 0; i <= n; i ++)
        G[i].clear();
}

int dijkstra(vector<Node> *G, int n, int src, int des)
{
    int vis[105];
    int dist[105];
    qnode temp;
    memset(vis, 0, sizeof(vis));
    memset(dist, inf, sizeof(dist));
    dist[src] = 0;
    priority_queue<qnode> q;
    temp.v = src;
    temp.cost = 0;
    //q.push((qnode){src, 0});
    q.push(temp);
    while(!q.empty()){
        qnode x = q.top();  q.pop();
        int v = x.v;
        if(vis[v] == 1) continue;
        vis[v] = 1;
        for(int i = 0; i < G[v].size(); i ++){
            if(dist[G[v][i].to] > (dist[v] + G[v][i].cost)){
                dist[G[v][i].to] = dist[v] + G[v][i].cost;
                temp.v = G[v][i].to;
                temp.cost = dist[G[v][i].to];
                //q.push((qnode){G[v][i].to, dist[G[v][i].to]});
                q.push(temp);
            }
        }
    }
    if(dist[des] == inf) return -1;
    else return dist[des];
}


int main()
{
    int n, a, b;
    vector<Node> G[105];
    while(scanf("%d%d%d", &n, &a, &b) != EOF){
        init(G, n);
        for(int i = 1; i <= n; i ++){
            int m, x;
            Node node;
            scanf("%d", &m);
            for(int j = 0; j < m; j ++){
                scanf("%d", &x);
                node.to = x;
                if(j == 0)
                    node.cost = j;
                else node.cost = 1;
                G[i].push_back(node);
            }
        }

        //for(int i = 1; i <= n; i ++){
        //   for(int j = 0; j < G[i].size(); j ++){
        //        printf("%d %d\n", G[i][j].to, G[i][j].cost);
        //    }
        //    printf("\n");
        // }

        int ans = dijkstra(G, n, a, b);
        printf("%d\n", ans);
    }
    return 0;
}
*/

/// 传统方法
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;
int dist[105];
int vis[105];
int path[105];
int graph[105][105];

int dijkstra(int n, int src, int des)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, inf, sizeof(dist));
    dist[src] = 0;
    int pre = -1;
 //   for(int i = 1; i <= n; i ++)
 //       printf("%d ", dist[i]);
 //   printf("\n");
    for(int i = 1; i <= n; i ++){
        int Min = inf;
        for(int j = 1; j <= n; j ++){
            if(vis[j] == 0 && dist[j] < Min){
                Min = dist[j];
                pre = j;
            }
        }
   //     printf("~%d\n", pre);
        vis[pre] = 1;
        for(int j = 1; j <= n; j ++){
            if(vis[j] == 0
               && dist[j] > dist[pre] + graph[pre][j]){
                dist[j] = dist[pre] + graph[pre][j];
            }
        }
    }
    if(dist[des] == inf) return -1;
    else return dist[des];

}

int main()
{
    int n, a, b;
    while(scanf("%d%d%d", &n, &a, &b) != EOF){
        memset(graph, inf, sizeof(graph));
        for(int i = 0; i <= n; i ++) graph[i][i] = 0;
        for(int i = 1; i <= n; i ++){
            int m, x;
            scanf("%d", &m);
            for(int j = 0; j < m; j ++){
                scanf("%d", &x);
                if(j == 0) graph[i][x] = 0;
                else graph[i][x] = 1;
            }
        }
        int ans = dijkstra(n, a, b);
        printf("%d\n", ans);
    }
    return 0;
}

