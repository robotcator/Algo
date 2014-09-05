#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10000+10;
int a[maxn];
int b[maxn];

int main(){
    int n, q;
    int test = 1;
    while(scanf("%d%d", &n, &q) != EOF){
        if(n == 0 && q == 0) break;
        memset(a, 0, sizeof(a));
        int x;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &x);
            a[x] ++;
        }
        for(int i = 1; i < maxn; i ++)
            b[i] = b[i-1] + a[i];
        printf("CASE# %d:\n", test++);
        for(int i = 0; i < q; i ++){
            scanf("%d", &x);
            if(a[x] != 0) printf("%d found at %d\n", x, b[x-1]+1);
            else printf("%d not found\n", x);
        }
    }
    return 0;
}

/*
conclusion:
13790851 	10474 	Where is the Marble?
Accepted 	C++11 	0.102 	2014-06-25 07:11:07
1: 基数排序，要读懂题意，不要妄自乱猜
2: 用基数排序去看看后缀数组
*/
