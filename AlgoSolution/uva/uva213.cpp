#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
struct point{
    int x, y;
};
point p[20];
int rec[20];
double ans;

double dist(int i, int j){
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)) + 16;
}

void dfs(int cur, int n, int *vis, int *path, double met){
    if(cur == n){
        if(met < ans) {
            ans = met;
            for(int i = 0; i < n; i ++){
                //cout << path[i] << " ";
                rec[i] = path[i];
            }
            //cout << endl;
        }
    }else{
        for(int i = 0; i < n; i ++){
            if(vis[i] == 0){
                path[cur] = i;
                vis[i] = 1;
                double temp = 0;
                if(cur != 0) temp = dist(i, path[cur-1]);
                else temp = 0;
                dfs(cur+1, n, vis, path, met+temp);
                vis[i] = 0;
            }
        }
    }
}


int main(){
    int n, flag;
    flag = 1;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        for(int i = 0; i < n; i ++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        int path[20];
        int vis[20];
        ans = inf;
        memset(vis, 0, sizeof(vis));
        memset(path, -1, sizeof(path));
        dfs(0, n, vis, path, 0);
        printf("**********************************************************\n");
        printf("Network #%d\n", flag ++);
        for(int i = 0; i < n-1; i ++){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
            p[rec[i]].x, p[rec[i]].y, p[rec[i+1]].x, p[rec[i+1]].y, dist(rec[i], rec[i+1]));
        }
        printf("Number of feet of cable required is %.2f.\n", ans);
    }
    return 0;
}


/*
conclusion：
13801240 	216 	Getting in Line
Accepted 	C++11 	0.059 	2014-06-27 13:18:51
1：简单题，数据量可以枚举所有的可能。
2：可以使用最小生成树算法
3：熟悉回溯法框架
*/
