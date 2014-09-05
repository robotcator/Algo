/*
    ID: problem6
    PROG : YY's new problem
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10000+10;
int p[maxn];
int rev[maxn];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(rev, 0, sizeof(rev));
        for(int i = 1; i <= n; i ++){
            scanf("%d", &p[i]);
            rev[p[i]] = i;
        }
        int flag = 0;
        for(int i = 2; i < n/2; i ++){
            for(int j = 1; j < i; j ++){
                int temp = 2*p[i]-p[j];
                if(temp <= 0 || temp > n) continue;
                if(rev[temp] >= i+1) { flag = 1; break; }
            }
            if(flag == 1) break;
        }
        for(int i = n/2; i < n; i ++){
            for(int j = i+1; j <= n; j ++){
                int temp = 2*p[i]-p[j];
                if(temp <= 0 || temp > n) continue;
                if( rev[temp] > 0 && rev[temp] <= i-1) { flag = 1; break; }
            }
            if(flag == 1) break;
        }
        if(flag == 1) puts("Y");
        else puts("N");
    }
    return 0;
}
/*
11118347	2014-07-21 14:05:41	Accepted
3833	3203MS	328K	1181 B	C++	robotcator
1: 论优化的重要性
2: 当时判定性问题是：用二分或哈希速度回比较快
*/

/*
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10000+10;
int p[maxn];
int rev[maxn];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(rev, 0, sizeof(rev));
        for(int i = 1; i <= n; i ++){
            scanf("%d", &p[i]);
            rev[p[i]] = i;
            // the latter is a permutation of 1 to N.
        }
        int flag = 0;
        for(int i = 2; i <= n-1; i ++){
            for(int j = 1; j < i; j ++){
                if(2*p[i] >= p[j] && rev[2*p[i] - p[j]] >= i+1) { flag = 1; break; }
            }
        }
        if(flag == 1) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

// 11117915	2014-07-21 13:28:03	Time Limit Exceeded	3833
// 4000MS	408K	883 B	G++	robotcator
*/
