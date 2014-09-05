//hdu 1217
/*
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int find(char *x, char s[][30], int n)
{	
	for(int i = 0; i < n; i ++)
		if(strcmp(x, s[i]) == 0) return i;
	return -1;
}
// don't bother to do, be patient

void Floyd(double graph[][30], int n)
{
	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(graph[i][j] < graph[i][k]*graph[k][j])
				   graph[i][j] = graph[i][k]*graph[k][j];

}
int main()
{
	int n, m;
	int i, j;
	int flag = 1;
	char s[35][30];  // store the currencies
	char s1[30], s2[30];
	double graph[30][30];
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		for(i = 0; i < n; i ++)
			scanf("%s", &s[i]);
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++)
				graph[i][j] =  (i == j) ? 1 : 0;
		scanf("%d", &m);
		double x = 0;
		for(i = 0; i < m; i ++){
			scanf("%s%lf%s", s1, &x, s2);
			int p = find(s1, s, n);
			int q = find(s2, s, n);
			graph[p][q] = x;
		}
		
	//	for(i = 0; i < n; i ++){
	//		for(j = 0; j < n; j ++)
	//			printf("%lf ", graph[i][j]);
	//		printf("\n");
	//	}
		
		Floyd(graph, n);
		printf("Case %d: ", flag ++);
		for(i = 0; i < n; i ++)
			if(graph[i][i] > 1.0) break;
		if(i < n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//map 键值到数据的映射
void Floyd(double graph[][35], int n)
{
	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(graph[i][j] < graph[i][k]*graph[k][j])
				   graph[i][j] = graph[i][k]*graph[k][j];

}

int main()
{
	int n, m;
	int i, j;
	int flag = 1;
	double graph[35][35];
	char money[35];
	char money1[35];
	double cost;
	map<string, int> mp;   // 货币到编号的映射
	while(scanf("%d", &n) != EOF){
		if(n == 0) break;
		mp.clear();
		for(i = 0; i < n; i ++){
			scanf("%s", money);
			mp[money] = i;
		}
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++)
				graph[i][j] = (i == j) ? 1 : 0;
		scanf("%d", &m);
		for(i = 0; i < m; i ++){
			scanf("%s%lf%s", money, &cost, money1);
			graph[mp[money]][mp[money1]] = cost;
		}
		Floyd(graph, n);
		printf("Case %d: ", flag ++);
		for(i = 0; i < n; i ++)
			if(graph[i][i] > 1.0) break;
		if(i < n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
// how to avoid warning