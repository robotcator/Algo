/*
// hdu 3790
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Node{
	int to;
	int len;
	int cost;
};

int dist[1000];
int cost[1000];
int vis[1000];
const int inf =  0x3f3f3f3f;
vector<Node> G[1005];

void dijkstra(int src, int n)
{
	int i, j;
	memset(vis, 0, sizeof(vis));
	memset(dist, inf, sizeof(dist));
	memset(cost, inf, sizeof(cost));
	vis[src] = 1;
	for(vector<Node>::iterator it = G[src].begin(); it != G[src].end(); it ++){
       // printf("n%d\n", it->to);
		dist[it->to] = it->len;
		cost[it->to] = it->cost;
	}
	dist[src] = 0;
    cost[src] = 0;

	int Min = inf;
	int pre = src;      //Ç°Çý½áµã

	for(i = 2;  i <= n; i ++){
        Min = inf;
        for(vector<Node>::iterator it = G[pre].begin(); it != G[pre].end(); it ++){
            if(vis[it->to] == 0 ){
                if(dist[pre]+it->len < dist[it->to]){
                    dist[it->to] = dist[pre] + it->len;
                    cost[it->to] = cost[pre] + it->cost;
                }
                else if(dist[pre]+it->len == dist[it->to]){
                    if(cost[it->to] >cost[pre] + it->cost)
                    cost[it->to] = cost[pre] + it->cost;
                }
            }
        }
       // for(int k = 1; k <= n; k ++)
       // cout << "k1 " << dist[k] << endl;
        for(j = 1; j <= n; j ++){
            if(vis[j] == 0 && dist[j] < Min){
                Min = dist[j];
                pre = j;
            }
        }
        vis[pre] = 1;
        //for(int k = 1; k <= n; k ++)
        //cout << "k2 " << dist[k] << endl;
	}
}

int main()
{
	int n, m;	// the vertic ans edge
	int i, j;
	int s, t;
	int a, b, d, p;
    // d is length p is cost
	Node node;
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0) break;
		for(i = 0; i < m; i ++){
			scanf("%d%d%d%d", &a, &b, &d, &p);
			int flag = 0;
			for(vector<Node>::iterator it = G[a].begin(); it != G[a].end(); it ++){
                if(it->to == b){
                    if(it->len > d){
                        it->len = d;
                        it->cost = p;
                        flag = 1;
                    }
                    else if(it ->to == b && it->len == d){
                        if(it->cost > p){
                            it->cost = p;
                            flag = 1;
                        }
                    }
                }
			}
			for(vector<Node>::iterator it = G[b].begin(); it != G[b].end(); it ++){
                if(it->to == b){
                    if(it->len > d){
                        it->len = d;
                        it->cost = p;
                        flag = 1;
                    }
                    else if(it ->to == b && it->len == d){
                        if(it->cost > p){
                            it->cost = p;
                            flag = 1;
                        }
                    }
                }
			}
			if(flag == 0){
                node.to = b;
                node.len = d;
                node.cost = p;
                G[a].push_back(node);
                node.to = a;
                node.len = d;
                node.cost = p;
                G[b].push_back(node);
			}
		}

		scanf("%d%d", &s, &t);
		dijkstra(s, n);
		printf("%d %d\n", dist[t], cost[t]);

	}
	return 0;
}
*/

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int graph[1005][1005];
int cost[1005][1005];

const int inf = 0x3f3f3f3f;

int dist[1005];
int lowcost[1005];
int vis[1005];

void dijkstra(int src, int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
        dist[i] = graph[src][i];
        lowcost[i] = cost[src][i];
    }
    dist[src] = lowcost[src] = 0;
    vis[src] = 1;

    int pre = src;
    int Min ;
    for(int i = 2; i <= n; i ++){
        Min = inf;
        for(int j = 1; j <= n; j ++){
            if(vis[j] == 0 && graph[pre][j] + dist[pre] < dist[j]){
                dist[j] = graph[pre][j] + dist[pre];
                lowcost[j] = cost[pre][j] + lowcost[pre];
            }
            else if(vis[j] == 0 && graph[pre][j] + dist[pre] == dist[j]){
                if(lowcost[j] > lowcost[pre] + cost[pre][j]){
                    dist[j] = graph[pre][j] + dist[pre];
                    lowcost[j] = cost[pre][j] + lowcost[pre];
                }
            }
        }
        for(int j = 1; j <= n; j ++){
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
    int n, m;
    int a, b, d, p;
    int s, t;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0) break;
        memset(graph, inf, sizeof(graph));
        memset(cost, inf, sizeof(cost));
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d%d", &a, &b, &d, &p);
            if(graph[a][b] > d){
                graph[a][b] = graph[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }
            else if(graph[a][b] == d){
                if(cost[a][b] > p){
                    graph[a][b] = graph[b][a] = d;
                    graph[a][b] = graph[b][a] = p;
                }
            }
        }
        scanf("%d%d", &s, &t);
        dijkstra(s, n);
        printf("%d %d\n", dist[t], lowcost[t]);
    }
    return 0;
}

