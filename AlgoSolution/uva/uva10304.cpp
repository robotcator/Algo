/*
    ID: problem6
    PROG : Optimal Binary Search Tree
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 250+10;
const int inf = 0x3f3f3f3f;
int fre[maxn];
int dp[maxn][maxn];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i ++)
            scanf("%d", &fre[i]);
        memset(dp, 0, sizeof(dp));
        for(int l = 1; l < n; l ++){
           for(int i = 1; i <= n-l; i ++){
             int j = i+l;
             int minn = inf;
             int sum = 0;
             for(int k = i; k <= j; k ++){
                sum += fre[k];
                if(minn > dp[i][k-1]+dp[k+1][j]-fre[k])
                    minn = dp[i][k-1]+dp[k+1][j]-fre[k];
             }
             dp[i][j] = minn + sum;
           }
        }
        /*
        for(int i = 0; i <= n; i ++){
            for(int j = 0; j <= n; j ++){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n", dp[1][n]);

    }
    return 0;
}
