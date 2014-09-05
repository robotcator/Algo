/*
    ID: problem6
    PROG : ZCC loves cards
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 25;
int a[maxn];

int main(){
    int n, k, l;
    while(scanf("%d%d%d", &n, &k, &l) != EOF){
        for(int i = 0; i < n; i ++){
            scanf("%d", &a[i]);
        }
        int comb = (1<<k)-1;
        while(comb < 1<<n){
            for(int i = 0; i < n; i ++){
                if(comb & (1<<i)) printf("%d ", a[i]);
            }
            printf("\n");
            int x = comb & -comb, y = comb + x;
            comb = ((comb & ~y)/x >> 1) | y;
        }
    }
    return 0;
}
