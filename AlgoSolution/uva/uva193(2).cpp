/*
    ID: problem6
    PROG : Graph Coloring
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 102;
int graph[maxn][maxn];
int mark[maxn];
// 搜索过程中染色方案，1为黑色，2为白色
int ans;
int rec[maxn];
// 最后的最大染色数和染色方案

void dfs(int cur, int n, int size){
    if(cur > n){
        if(size > ans){
            ans = size;
            int j = 0;
            for(int i = 1; i <= n; i ++) {
                //cout << mark[i] << " ";
                if(mark[i] == 1) rec[j++] = i;
            }
            //cout << endl;
        }
        return ;
    }else{
        if(size+n-cur+1 <= ans) return ;
        int ok = 1;
        for(int i = 1; i <= n; i ++){
            if(graph[cur][i] == 1 && mark[i] == 1){
                ok = 0;
            }
        }
        // 以着色判断
        if(ok == 1){
            mark[cur] = 1;
            dfs(cur+1, n, size+1);
            mark[cur] = 0;
        }
        mark[cur] = 2;
        dfs(cur+1, n, size);
        mark[cur] = 0;
    }
}

int main(){
    int n, k, m;
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &n, &k);
        int x, y;
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < k; i ++){
            scanf("%d %d", &x, &y);
            graph[x][y] = graph[y][x] = 1;
        }
        memset(mark, 0, sizeof(mark));
        memset(rec, 0, sizeof(rec));
        ans = -inf;
        dfs(1, n, 0);
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
13808484 	193 	Graph Coloring 	Accepted
C++11 	0.045 	2014-06-29 11:27:31
wa : 20 times
1: 简单回溯，对所有节点进行染色尝试，所以对节点进行搜索即可
*/
