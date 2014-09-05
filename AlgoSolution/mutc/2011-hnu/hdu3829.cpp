/*
    ID: problem6
    PROG : Cat VS Dog
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 500+10;
vector<int> G[maxn];
char like[maxn][10], dislike[maxn][10];

int Left[maxn];
bool T[maxn];

bool match(int u){
    for(int v = 0; v < G[u].size(); v ++){
        if(!T[G[u][v]]){
            T[G[u][v]] = true;
            if(Left[G[u][v]] == -1 || match(Left[G[u][v]])){
                Left[G[u][v]] = u;
                return true;
            }
        }
    }
    return false;
}

int solve(int p){
    memset(Left, -1, sizeof(Left));
    int ans = 0;
    for(int i = 0; i < p; i ++){
        memset(T, 0, sizeof(T));
        if(match(i)) ans ++;
    }
    for(int i = 0; i < p; i ++)
        printf("%d %d\n", i, Left[i]);
    printf("\n");
    return ans;
}

int main(){
    int m, n, p;
    while(scanf("%d%d%d", &n, &m, &p) != EOF){
        for(int i = 0; i < p; i ++){
            scanf("%s %s", like[i], dislike[i]);
            // printf("%s %s\n", like[i], dislike[i]);
        }
        for(int i = 0; i < maxn; i ++) G[i].clear();
        for(int i = 0; i < p; i ++){
            for(int j = i+1; j < p; j ++){
                if(strcmp(dislike[i], like[j]) == 0
                   || strcmp(like[i], dislike[j]) == 0){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int ans = solve(p);
        for(int i = 0; i < p; i ++){
            for(int j = 0; j < G[i].size(); j ++)
                printf("%d %d\n", i, G[i][j]);
        }
        printf("%d\n", p-ans/2);
    }
    return 0;
}
/*
conclusion :
11131498	2014-07-22 11:02:09	Accepted
3829	78MS	944K	1537 B	C++	robotcator
1: 如何求最大匹配
*/
