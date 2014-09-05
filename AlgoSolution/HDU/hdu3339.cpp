//hdu 3339
/*
ע�⣺
����������ͼΪ����ģ����Ƕ�����n�ͱ���m֮��Ĺ�ϵ�������㣺m<=n*(n-1)/2
��˵��ͼ�е�������֮����ж���·��������Ҫѡ����̵Ĵ洢���ڽӾ�����ȥ
*/
/*
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct edge{
    int from;
    int to;
    int len;
};

edge e[10000];
int pow[100];
int dist[100], pre[100];
const int inf = 0x3f3f3f3f;

int relax(int u, int v, int cost)
{
    if(dist[u] + cost < dist[v]){
      dist[v] = dist[u] + cost;
      pre[v] = u;
      return 1;
    }
    return 0;
}

int bellman(int src, int m, int n)
{
    for(int i = 0; i < n; i ++){
        dist[i] = inf ;
        pre[i] = -1;
    }
    dist[src] = 0;
    int flag = 0;
    for(int i = 1; i < n; i ++){
        flag = 0;
        for(j = 0; j < m; j ++){
            if(relax(e[j].from, e[j].to, e[j].len) == 1)
                flag = 1;
        }
        if(flag == 0) break;
    }
    for(j = 0; j < m; j ++)
            if(relax(e[j].from, e[j].to, e[j].len) == 1)
                return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, z;
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d", &x, &y, &z);
            e[i].from = x;
            e[i].to = y;
            e[i].len = z;

        }
        for(int i = 1; i <= n; i ++)
            scanf("%d", &pow[i]);

    }
    return 0;
}
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int pow[105];
int dist[105], vis[105];
const int inf = 0x3f3f3f3f;
int graph[105][105];

void dijkstra(int src, int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i ++){
        dist[i] = graph[src][i];
    }
    vis[src] = 1;
    dist[src] = 0;
    int pre = src;
    int Min = inf;
    for(int i = 1; i <= n; i ++){
        Min = inf;
        for(int j = 0; j <= n; j ++){
            if(vis[j] == 0 && dist[pre] + graph[pre][j] < dist[j])
                dist[j] = dist[pre] + graph[pre][j];
        }
        for(int j = 0; j <= n; j ++){
            if(vis[j] == 0 && dist[j] < Min){
                Min = dist[j];
                pre = j;
            }
        }
        vis[pre] = 1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, z;
        memset(graph, inf, sizeof(graph));
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d", &x, &y, &z);
            if(graph[x][y] > z){
                graph[x][y] = graph[y][x] = z;
            }
        }
        pow[0] = 0;
        int total = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &pow[i]);
            total += pow[i];
        }
        dijkstra(0, n);
        int flag = 0;
        for(int i = 1; i <= n; i ++){
            if(dist[i] >= inf) {
                flag = 1;
                break;
            }
        }
        int dp[100005];
        if(flag == 1)   printf("impossible\n");// ��·��ͨ
        else{
            int vol = 0;
            for(int i = 0; i <= n; i ++)
            vol += dist[i];
            memset(dp, 0, sizeof(dp));
            for(int i = 1; i <= n; i ++){
                for(int j = vol; j >= dist[i]; j --){
                    if(dp[j] < dp[j-dist[i]]+pow[i])
                    dp[j] = dp[j-dist[i]]+ pow[i];

                }
            }
            total = total/2+1;
            for(int i = 1; i <= vol; i ++){
                if(dp[i] >= total){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
