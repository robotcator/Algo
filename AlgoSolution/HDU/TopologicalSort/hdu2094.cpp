#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;
char name[1005][30];
int deg[1005];
int num;

int Find(char *x)
{
    int i;
    for(i = 0; i < num; i ++){
        if(strcmp(name[i], x) == 0)
                break;
    }
    if(i == num){
        strcpy(name[num++], x);
    }
    return i;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        num = 0;  // 如果是全局变量不要重复定义
        char s1[30], s2[30];
        memset(deg, 0, sizeof(deg));
        for(int i = 0; i < 1005; i ++)
            deg[i] = 0;
        getchar();
        for(int i = 0; i < n; i ++){
            scanf("%s %s", s1, s2);
            int pos1 = Find(s1);
            int pos2 = Find(s2);
            deg[pos2] ++;
        }
        int flag = 0;
        for(int i = 0; i < num; i ++){
            if(deg[i] == 0){
                flag ++;
            }
        }
        if(flag == 1) printf("Yes\n");
        else printf("No\n");
    }


    return 0;
}
