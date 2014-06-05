#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int inf = 0x3f3f3f3f;
int Max[205];
int Min[205];


int main()
{
    int n, m;
    int graph[205][205];
    while(scanf("%d%d", &n, &m) != EOF){
        int x, y, z;
        memset(graph, inf, sizeof(graph));
        for(int i = 0; i < n; i ++) graph[i][i] = 0;
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d", &x, &y, &z);
            graph[x-1][y-1] = graph[y-1][x-1] = z;
        }

    }

    return 0;
}
