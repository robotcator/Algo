//Accepted 168K 16MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int dp[1005];

int LIS(int *data, int n)
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < n; i ++){
        int temp = 0;
        for(int j = 0; j < i; j ++){
            if(data[i] > data[j] && dp[j] > temp)
                temp = dp[j];
        }
        dp[i] = temp + 1;
    }
    int maxn = 0;
    for(int i = 0; i < n; i ++){
       // printf("~%d\n", dp[i]);
        if(maxn < dp[i]) maxn = dp[i];
    }
    return maxn;
}

int main()
{
    int n;
    int data[1005];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i ++)
            scanf("%d", &data[i]);
        int ans = LIS(data, n);
        printf("%d\n", ans);
    }
    return 0;
}
