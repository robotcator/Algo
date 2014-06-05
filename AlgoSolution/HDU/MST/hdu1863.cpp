#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Edge{
	int from;
	int to;
	int cost;
};
int set[100];
Edge edge[10000];

int cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int find(int x)
{
	if(set[x] == x) return x;
	else return set[x] = find(set[x]);
}

int kruskal(int n, int m)
{
	int i,j;
	int res = 0;
	for(i = 0; i < n; i ++) set[i] = i;
	for(j = 0; j < m; j ++){
		int x = find(edge[j].from);
		int y = find(edge[j].to);
		if(x != y) {
			set[x] = y;
			res += edge[j].cost;
		}
	}
	int num = 0;
	for(i = 0; i < n; i ++)
		if(set[i] == i) num ++;
	if(num > 1) return -1;
	else return res;
	
}

int main()
{
	int n, m;
	int i;
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0) break;
		for(i = 0; i < n; i ++){
			scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].cost);
		}
		sort(edge, edge+n, cmp);
		int ans = kruskal(m, n);
		if(ans < 0) printf("?\n");
		else printf("%d\n", ans);
	}
	return 0;
}