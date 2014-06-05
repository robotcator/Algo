//hdu 1301
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node { 
		int from;	// 起点
	    int to;		// 终点
	    int cost;	// 权重
};   

int set[100];
node edge[105];

int cmp(node a, node b)
{
	return a.cost < b.cost;   // sort by weight
}

int find(int x)
{
	return set[x] == x ? x : set[x] = find(set[x]);
}

int kruskal(int n, int k)
{
	int i, j;
	int res = 0;
	for(i = 0; i < n; i ++) set[i] = i;
	for(j = 0; j < k; j ++){
		int x = find(edge[j].from);
		int y = find(edge[j].to);
		if(x != y) {
			res += edge[j].cost;
			set[x] = y;
		}
	}

	return res;
}

int main()
{
	int n, k;
	int i, j;
	char d, d1;
	int num, c;
	//vector< vector <int> > a;
	//vector<int> G[28];	 // 无权重，如何修改
	//vector<node> a[maxn];  
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		k = 0;
		getchar();
		for(i = 0; i < n-1; i ++){
			scanf("%c %d", &d, &num);
			for(j = 0; j < num; j ++){
				scanf(" %c %d", &d1, &c);
				edge[k].from = d -'A';
				edge[k].to = d1 - 'A';
				edge[k].cost = c;
				k ++;
			}
		getchar();			//去除回车换行，还有去除空格
		}
		sort(edge, edge+k, cmp);
		int ans = kruskal(n, k);
		printf("%d\n", ans);

	}
	return 0;
}