/*
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100+10;

int main(){
    int x, y, n;
    int gaze[maxn][maxn];
    memset(gaze, 0, sizeof(gaze));
    scanf("%d", &n);
    int num = gaze[0][n-1] = 1;
    x = 0, y = n-1;
    while(num < n*n){
        while(x+1 < n && gaze[x+1][y] == 0) gaze[++x][y] = ++ num;
        while(y-1 >= 0 && gaze[x][y-1] == 0) gaze[x][--y] = ++ num;
        while(x-1 >= 0 && gaze[x-1][y] == 0) gaze[--x][y] = ++ num;
        while(y+1 < n && gaze[x][y+1] == 0) gaze[x][++y] = ++ num;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            printf("%4d", gaze[i][j]);
        }
        printf("\n");
    }
    return 0;
}

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n ,cnt;

bool check(int *x, int k){
    for(int i = 0; i < k; i ++)
    if(x[k] == x[i] || i+x[i] == k+x[k] || i-x[i] == k-x[k]) return false;
    //if(x[k] == x[i] || abs(i-x[i]) == abs(k-x[k])) return false;
    return true;
}

int x[10];

void queue_rec(int cur){
    if(cur >= n){
        cnt ++;
        for(int i = 0; i < n; i ++)
            cout << x[i] << " ";
        cout << endl;
    }
    else {
        for(int i = 0; i < n; i ++){
            x[cur] = i;
            if(check(x, cur)) queue_rec(cur + 1);
        }
    }

}

void Queue_rec(int cur){
    if(cur >= n) {
        cnt ++;
        for(int i = 0; i < n; i ++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i = 0; i < n; i ++){
            int flag = 1;
            x[cur] = i;
            for(int j = 0; j < cur; j ++){
                //if(x[j] == x[cur] || j-x[j] == cur-x[cur] || cur+x[cur] == j+x[j])
                if(x[i] == x[cur] || abs(j-x[j]) == abs(cur-x[cur]))
                    { flag = 0; break; }
            }
            if(flag == 1) Queue_rec(cur+1);
        }
    }
}


void Queue(int n){
    memset(x, 0, sizeof(x));
    int k = 1;
    cnt = 0;
    while(k >= 1){
        x[k] = x[k]+1;
        while(x[k] <= n && check(x, k) == 0) x[k] = x[k]+1;
        if(x[k] <= n && k == n) {
            for(int i = 1; i <= k; i ++){
                cout << x[i]+1 << " ";
            }
            cout << endl;
            cnt ++;
        }
        else if(x[k] <= n && k < n) {
            k  = k + 1;
        }
        else {
                x[k] = 0;
                k = k - 1;
        }
    }
}

int main(){
    n = 8;
    memset(x, -1, sizeof(x));
    queue_rec(0);
    //Queue_rec(0);
    //Queue(n);
    cout << cnt << endl;
    return 0;
}

