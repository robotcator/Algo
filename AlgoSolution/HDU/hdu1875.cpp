
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;
const int inf = 0x3f3f3f3f;

struct Point{
    double x, y;
};
int Set[105];
/*
double distance(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
*/
double distance(double a1, double b1, double a2, double b2)
{
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

double prim(double graph[][105], int n)
{
    int vis[105];
    double dist[105];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i ++) dist[i] = graph[0][i];
    dist[0] = 0;
    vis[0] = 1;
    double res = 0;
    double Min = inf;
    int p = -1;
    for(int i = 1; i < n; i ++){
        Min = inf ;
        p = -1;
        for(int j = 0; j < n; j ++){
            if(vis[j] == 0 &&  dist[j] < Min){
                Min = dist[j];
                p = j;
            }
        }
        if(Min == inf) return -1;
        res += Min;
        vis[p] = 1;
        for(int j = 0; j < n; j ++){
            if(vis[j] == 0 && dist[j] > graph[p][j]){
                dist[j] = graph[p][j];
            }
        }
    }
    return res;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    Point p[105];
    double graph[105][105];
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
               // double ans = distance(p[i], p[j]);
               double ans = distance(p[i].x, p[i].y, p[j].x, p[j].y);
                if(ans >= 10 && ans <= 1000)
                    graph[i][j] = graph[j][i] = ans;
                else   graph[i][j] = graph[j][i] = inf;
            }
        }
        /*
         for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                printf("%lf ", graph[i][j]);
            }
            printf("\n");
        }
        */
        double ans = prim(graph, n)*100;
        if(ans < 0) printf("oh!\n");
        else printf("%.1lf\n", ans);
    }
    return 0;
}
