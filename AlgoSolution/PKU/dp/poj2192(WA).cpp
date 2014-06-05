//Wrong Answer
//Wrong Answer 加了特判
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int dp[205][205];

int sovle(char *x, char *y, char *z)
{
    int len1 = strlen(x);
    int len2 = strlen(y);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    if(y[0] == z[0]){
      dp[0][1] = 1;
      for(int i = 1; i <= len1; i ++){
        // 要特判哪个做首字母
          for(int j = 0; j <= len2; j ++){
              if((dp[i-1][j] && z[i+j-1] == x[i-1]) ||
                 (dp[i][j-1] && z[i+j-1] == y[j-1]) )
                  dp[i][j] = 1;
              else dp[i][j] = 0;
          }
      }
    }
    else{
        dp[1][0] = 1;
        for(int i = 0; i <= len1; i ++){
          for(int j = 1; j <= len2; j ++){
              if((dp[i-1][j] && z[i+j-1] == x[i-1]) ||
                 (dp[i][j-1] && z[i+j-1] == y[j-1]) )
                  dp[i][j] = 1;
              else dp[i][j] = 0;
          }
      }

    }
//  多想想如何确定状态，阶段，决策
/*
    for(int i = 0; i<= len1; i ++){
        for(int j = 0; j <= len2; j ++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
*/
    return dp[len1][len2];
}

int main()
{
    int t, flag = 1;
    char word1[205], word2[205];
    char word[500];
    scanf("%d", &t);
    while(t --){
        scanf("%s %s %s", word1, word2, word);
        int ans = sovle(word1, word2, word);
        printf("Data set %d: ", flag ++);
        if(ans == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
