//4120K 16MS
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[1005][1005];

int minn(int x, int y, int z)
{
    int temp = x < y ? x : y;
    return temp < z ? temp : z;
}

int sovle(char *x, char *y, int num1, int num2)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= num1; i ++)
        dp[i][0] = i;
    for(int i = 1; i <= num2; i ++)
        dp[0][i] = i;
    for(int i = 1; i <= num1; i ++){
        for(int j = 1; j <= num2; j ++){
            if(x[i-1] == y[j-1])
                dp[i][j] = minn(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]);
            // i-1就是插入，j-1就是删除，i-1 && j-1 就是替换
            else
                dp[i][j] = minn(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);
        }
    }

    return dp[num1][num2];
}

int main()
{
    int num1, num2;
    char x[1005], y[1005];
    while(scanf("%d %s", &num1, x) != EOF){
        scanf("%d %s", &num2, y);
        int ans = sovle(x, y, num1, num2);
        printf("%d\n", ans);
    }
    return 0;
}
