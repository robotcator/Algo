#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int flag;
void dfs(int cur, int n, int ans, int *a){
    if(cur >= n){
        if(ans == 23) { flag = 1; return; }
    }else{
        for(int i = 0; i < 3; i ++){
            if(i == 0){
                dfs(cur+1, n, ans+a[cur], a);
            }
            else if(i == 1){
                dfs(cur+1, n, ans-a[cur], a);
            }
            else {
                dfs(cur+1, n, ans*a[cur], a);
            }
        }
      //  cur ++;
    }
}

int main(){
    int a[10];
    while(scanf("%d", &a[0]) != EOF){
        for(int i = 1; i < 5; i ++)
            scanf("%d", &a[i]);
        if(a[0] == 0 && a[1] == 0 && a[2] == 0
           && a[3] == 0 && a[4] == 0) break;
        sort(a, a+5);
        flag = 0;
        dfs(1, 5, a[0], a);
        if(flag == 1) printf("Possible\n");
        else {
            while(next_permutation(a, a+5)){
                dfs(1, 5, a[0], a);
                if(flag == 1){
                    printf("Possible\n");
                    break;
                }
            }
        }
        if(flag == 0) printf("Impossible\n");
    }
    return 0;
}
/*
13801924 	10344 	23 out of 5
Accepted 	C++11 	0.719 	2014-06-27 15:36:36
// È¥µôK++µÄ´úÂë
13801911 	10344 	23 out of 5
Accepted 	C++11 	0.695 	2014-06-27 15:34:11
*/
