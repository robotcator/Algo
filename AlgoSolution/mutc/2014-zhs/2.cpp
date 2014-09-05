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
#include <cmath>

using namespace std;

const int mod = 5047621;

const int maxn = 1000;
string dict[45];
int prime[45];
int temp[maxn];
void table(){
    memset(temp, 0, sizeof(temp));
    int m = sqrt(maxn);
    for(int i = 2; i < m; i ++){
        if(temp[i] == 0){
            for(int j = i*i; j < maxn; j += i){
                temp[j] = 1;
            }
        }
    }
    int k = 0;
    for(int i = 2; i < maxn; i ++)
        if(temp[i] == 0) prime[k++] = i;
}



int main(){
    table();
    long long n, l;
    while(cin >> n >> l){
        for(int i = 1; i <= n; i ++)
            cin >> dict[i];
    }

    return 0;
}
