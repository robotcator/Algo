#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int from;
    int to;
    int cost;
    int status;
};
int p[105];
int Find(int x)
{
    return p[x] == x ? x : p[x] = Find(p[x]);
}

int cmp(struct edge e1, struct edge e2)
{
    return e1.cost < e2.cost;
}

int kruskal(struct edge *e, int n)
{
    int m = (n-1)*n/2;  // the number of edge
    int res = 0;
    for(int i = 1; i <= n; i ++) p[i] = i;
    // 注意是从1开始
    sort(e, e+m, cmp);
    for(int i = 0; i < m; i ++){
        int x = Find(e[i].from);
        int y = Find(e[i].to);
        /*
        if(e[i].status == 1){
            if(x != y)  {
                    p[x] = y;
                    res += 0;
            }
        }
        else {
            if(x != y){
                p[x] = y;
                res += e[i].cost;
            }
        }
        */
        if(x != y) {
            res += e[i].cost;
            p[x] = y;
        }
    }
    /*
    int num = 0;
    for(int i = 0; i < n; i ++){
        if(p[i] == i) num ++;
    }
    if(num == 1) return res;
    else return -1;
        */
    return res;
}

int main()
{
    int n;
    edge e[5005];
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        int x, y, z, w;
        for(int i = 0; i < n*(n-1)/2; i ++){
            scanf("%d%d%d%d", &x, &y, &z, &w);
            e[i].from = x;
            e[i].to = y;
            e[i].status = w;
            if(w == 1) e[i].cost = 0;
            else e[i].cost = z;
        }
      int ans = kruskal(e, n);
      printf("%d\n", ans);
    }

    return 0;
}
