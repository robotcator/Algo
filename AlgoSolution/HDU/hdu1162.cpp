//hdu 1162
#include <stdio.h>
#include <string.h>

#include <math.h>

typedef struct point{
	double x, y;
}Point;

Point p[105];
int visit[105];
double lowc[105];
double graph[105][105];
const double inf = 0x7fffffff;

double prim(int n)
{
	int i, j, p;
	double res = 0;
	double Min;
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	for(i = 1; i < n; i ++) lowc[i] = graph[0][i];
	for(i = 1; i < n; i ++){
		Min = inf;
		p = -1;
		for(j = 0; j < n; j ++){
			if(visit[j] == 0 && lowc[j] < Min){
				Min = lowc[j];
				p = j;
			}
		}
		res += Min;
		visit[p] = j;
	//	printf("%lf\n", Min);
		for(j = 0; j < n; j ++)
			if(visit[j] == 0 && lowc[j] > graph[p][j])
				lowc[j] = graph[p][j];	
	}
	return res;
}

double distance(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n;
	int i, j;
	double ans;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i ++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		for(i = 0; i < n; i ++)
			for(j = 0; j < n; j ++){
				graph[i][j] = distance(p[i], p[j]);
			}
		// calculate the adjacent matrix
		ans = prim(n);
		printf("%.2lf\n", ans);
	}
	return 0;
}
