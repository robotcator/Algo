//Presentation Error
//Accepted 576K 63MS
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int data[100000];
int dp[100000];

int LDS(int *data, int num)
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    /*
    for(int i = 1; i < num; i ++){
        for(int j = 0; j < i; j ++){
            if(data[i] < data[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    */


    for(int i = 1; i < num; i ++){
        int temp = 0;
        for(int j = 0; j < i; j ++){
            if(data[i] < data[j] && dp[j] > temp)
                temp = dp[j];
        }
        dp[i] = temp + 1;
    }
   // for(int i = 0; i < num; i ++)
   //     printf("~%d\n", dp[i]);

    int maxn = 0;
    for(int i = 0; i < num; i ++)
        if(dp[i] > maxn) maxn = dp[i];
    return maxn;
}


int main()
{
    int num, temp;
    int flag = 1;
    while(scanf("%d", &data[0]) != EOF){
        if(data[0] == -1) break;
        num = 1;
        while(1){
            scanf("%d", &temp);
            if(temp == -1) break;
            data[num++] = temp;
        }
        //printf("%d\n", num);
        printf("Test #%d:\n", flag ++);
        int ans = LDS(data, num);
        printf("  maximum possible interceptions: %d\n\n", ans);
    }

    return 0;
}
