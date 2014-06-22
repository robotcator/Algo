#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char data[55][55];
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[9] = {1, 0, -1, -1, -1, 0, 1, 1};
int m, n, t;
char temp[55];

bool is_inside(int x, int y){
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    else return false;
}

bool check(int a, int b, char *x){
    int len = strlen(x);
    for(int i = 0; i < 8; i ++){
        int nx = a + (len-1)*dx[i];
        int ny = b + (len-1)*dy[i];
        if(is_inside(nx, ny)){
            temp[0] = data[a][b];
            for(int j = 1; j < len; j ++){
                temp[j] = data[a+j*dx[i]][b+j*dy[i]];
            }
            temp[len] = '\0';
            if(strncmp(x, temp, len) == 0) return true;
        }
    }
    return false;
}

int main(){
    scanf("%d", &t);
    char x[55];
    while(t --){
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i ++){
            scanf("%s", &x);
            for(int j = 0; j < n; j ++){
                if(x[j] >= 'A' && x[j] <= 'Z')
                    data[i][j] = x[j]-'A'+'a';
                else data[i][j] = x[j];
            }
        }
        int p;
        scanf("%d", &p);
        for(int test = 1; test <= p; test ++){
            scanf("%s", &x);
            for(int i = 0; i < strlen(x); i ++)
                if(x[i] >= 'A' && x[i] <= 'Z') x[i] = x[i]-'A'+'a';
            int flag = 0;
            for(int i = 0; i < m; i ++){
                for(int j = 0; j < n; j ++){
                    if(check(i, j, x)){
                        printf("%d %d\n", i+1, j+1);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
        }
       if(t != 0)  printf("\n");
    }
    return 0;
}

/*
conclusion:
13774751 	10010 	Where's Waldorf?
Accepted 	C++11 	0.025 	2014-06-21 08:20:00
wa: 6 times
1: 搜索的范围，要注意是从0还是1开始
2：每两个case中有一个blank意味着最后没有blank
*/
