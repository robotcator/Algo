#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int graph[maxn][maxn];
int mark[maxn];
// 搜索过程中染色方案，1为黑色，2为白色
int ans;
int rec[maxn];
// 最后的最大染色数和染色方案

void dfs(int cur, int n, int *mark, int size){
    if(cur > n){
        if(size > ans){ ans = size;
            int j = 0;
            for(int i = 1; i <= n; i ++) {
                if(mark[i] == 1) rec[j++] = i;
            }
        }
        return ;
    }else{
        for(int i = 1; i <= n; i ++){
            if(graph[cur][i] == 1 && mark[i] == 2){
                mark[cur] = 1;
                dfs(cur+1, n, mark, size+1);
                mark[cur] = 0;
            }
        }
        mark[cur] = 2;
        dfs(cur+1, n, mark, size);
        mark[cur] = 0;
    }
}

int main(){
    int n, k, m;
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &n, &k);
        int x, y;
        for(int i = 0; i < k; i ++){
            scanf("%d%d", &x, &y);
            graph[x][y] = graph[y][x] = 1;
        }
        memset(mark, 0, sizeof(mark));
        memset(rec, 0, sizeof(rec));
        ans = 0;
        dfs(0, n, mark, 0);
        printf("%d\n", ans);
        for(int i = 0; i < ans; i ++){
            printf("%d", rec[i]);
            if(i != ans-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*
conclusion:
13807477 	193 	Graph Coloring 	Time limit exceeded
C++11 	3.000 	2014-06-29 04:55:42

*/
