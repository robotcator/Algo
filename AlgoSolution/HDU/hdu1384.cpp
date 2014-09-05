#include <stdio.h>
#include <string.h>

int who (char* word)
{
    int len = strlen(word);
    int dp[30];
    for(int i = 0; i < len; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(word[i] > word[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < len; i ++){
        if(dp[i] > max) max = dp[i];
    }
    if(max%2 == 1) return 0;
    else return 1;
}
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    char Test[30];
    scanf("%s", Test);
    printf("%d",who(Test));
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
