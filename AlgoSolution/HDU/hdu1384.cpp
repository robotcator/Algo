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
//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{
    char Test[30];
    scanf("%s", Test);
    printf("%d",who(Test));
}
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
