/*
    ID: problem6
    PROG : R(N)
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

const int inf = 1e9;

int bina_search(int left, int right, int key){
    int l = left, r = right;
    while(l <= r){
        long long mid = (l+r)/2;
        if((long long)(mid*mid) == (long long)key) return mid;
        else if((long long)(mid*mid) > (long long)key) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(){
    int n;
    long long ans;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        int temp = sqrt(n);
        for(int i = 0; i <= temp; i ++){
            int y = bina_search(0, inf, n-i*i);
            if(y != -1){
               // printf("%d %d\n", i, y);
                if(i == 0 && y == 0) ans += 1;
                else if(i == 0 || y == 0) ans += 2;
                else if(i == y) ans =+ 4;
                else ans += 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
11116665	2014-07-21 11:27:11	Accepted
3835	546MS	364K	1108 B	G++	robotcator
*/
