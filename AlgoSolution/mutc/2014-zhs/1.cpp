/*
    ID: problem6
    PROG : ride
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int e, k;
    double per;
};
const int maxn = 100000+10;
node p[maxn];
bool cmp(node a, node b){
    if(a.e == b.e) return a.k > b.k;
    else return a.e < b.e;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i ++){
            scanf("%d", &p[i].e);
        }
        for(int i = 0; i < n; i ++){
            scanf("%d", &p[i].k);
        }
        for(int i = 0; i < n; i ++){
            p[i].per = 1.0*
        }
        for(int i )
        sort(p, p+n, cmp);
        int temp = 0;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            printf("%d %d\n", p[i].e, p[i].k);
            temp += p[i].e;
            cout << temp << endl;
            sum += temp * p[i].k;
        }
        cout << sum << endl;
    }
    return 0;
}
