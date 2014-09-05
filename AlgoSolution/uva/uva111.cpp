/*
    ID: problem6
    PROG : History Grading
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[25], b[25];
int dp[25][25];
int Max(int x, int y) { return x > y ? x : y; }

int lcs(int *a, int *b, int n){
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = Max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main(){
    int n, temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &temp);
        a[temp] = i;
    }
    while(scanf("%d", &temp) != EOF){
        b[temp] = 1;
        for(int j = 2; j <= n; j ++){
            scanf("%d", &temp);
            b[temp] = j;
        }
        int ans = lcs(a, b, n);
        printf("%d\n", ans);
    }
    return 0;
}
/*
conclusion :
13811942 	111 	History Grading
Accepted 	C++11 	0.012 	2014-06-30 08:50:00
1: 要知道是什么序列进行比较，还发现英语水平亟待极高
2: 最长公共子序列.
*/
