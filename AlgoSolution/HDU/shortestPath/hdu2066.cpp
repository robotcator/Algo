#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int graph[1005][1005];
const int inf = 0x3f3f3f3f;
int beg[1000], end[1000];
int vis[1005];
int dist[10005];
int ans;

void dijkstra(int src, int m, int n, int d) // dΪ�յ�����
{
	int i, j;
	for(i = m; i <= n; i ++)
		vis[i] = 0;
	vis[src] = 1;
	for(i = m; i <= n; i ++)
		dist[i] = (i == src) ? 0 : graph[src][i]; 
	int pre = src;
	//all above intial
	for(i = m+1; i <= n; i ++){
		for(j = m; j <= n; j ++){
			if(vis[j] == 0 && dist[j] > dist[pre] + graph[pre][j])
				dist[j] = dist[pre] + graph[pre][j];
		}
		int min = inf;
		for(j = m; j <= n; j ++)
			if(vis[j] == 0 && dist[j] < min){
				min = dist[j];
				pre = j;
			}
		vis[pre] = 1;
	}
	for(i = 0; i < d; i ++){
		if(dist[end[i]] < ans){
			ans = dist[end[i]];
		}	
	}
	// ÿ���յ������·
}

int main()
{
	int t, s, d;
	int i;
	while(scanf("%d%d%d", &t, &s, &d) != EOF){
		memset(graph, inf, sizeof(graph));
		int x, y, c;
		int m, n;
		m = -1, n = inf;
		// n ��ʼ�������С�� m ��ʼ��С�����
		for(i = 0; i < t; i ++){
			scanf("%d%d%d", &x, &y, &c);
			if(graph[x][y] > c)			// �����ж���·
			graph[x][y] = graph[y][x] = c;
			if(x > m) m = x;
			if(y > m) m = y;
			if(x < n) n = x;
			if(y < n) n = y;
		}
		//	printf("m=%d n=%d\n", m, n);
		for(i = 0; i < s; i ++)
			scanf("%d", &beg[i]);
		for(i = 0; i < d; i ++)
			scanf("%d", &end[i]);
		ans = inf;
		for(i = 0; i < s; i ++)
			dijkstra(beg[i], n, m, d);
		printf("%d\n", ans);
		
	}
	return 0;
}