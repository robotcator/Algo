//hdu 1022
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int graph[105][105];
int lowdist[105];
int visit[105];
const int inf = 0x3f3f3f3f;

int prim(int n)
{
	int i ,j, p;
	int res = 0;
	int Min;
	memset(visit, 0, sizeof(visit));
	
	visit[0] = 1;
	for(i = 1; i < n; i ++)
		lowdist[i] = graph[0][i];

	for(i = 1; i < n; i ++){
		 Min = inf;
		 p = -1;
		for(j = 0; j < n; j ++){
			if(visit[j] == 0 && lowdist[j] < Min){		// if sentence must use curly braces
				Min = lowdist[j];
				p = j;
			}
		}

		if(Min == inf) return -1;
		res += Min;
		visit[p] = 1;
		printf("%d %d\n", p, Min);
		for(j = 0; j < n; j ++){
			if(visit[j] == 0 && lowdist[j] > graph[p][j])
				lowdist[j] = graph[p][j];
		}
	}
	return res;
}


int main()
{
	int n, q;
	int x, y;
	int i, j;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++)
				scanf("%d", &graph[i][j]);
		scanf("%d", &q);
		for(i = 0; i < q; i ++){
			scanf("%d%d", &x, &y);
				graph[x-1][y-1] = graph[y-1][x-1] = 0;
			//the cost is zero
		}
	int ans = prim(n);
	printf("%d\n", ans);
	
	}
	return 0;
}
