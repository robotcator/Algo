#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n ,cnt;

bool check(int *x, int k){
    for(int i = 1; i < k; i ++)
    if(x[k] == x[i] && abs(i-x[i]) == abs(k-x[k])) return false;
    return true;
}

void Queue(int n){
    int x[9];
    memset(x, 0, sizeof(x));
    int k = 1;
    int cnt = 0;
    while(k >= 1){
        x[k] = x[k]+1;
        while(x[k] <= n && !check(x, k)) x[k] = x[k]+1;
        if(x[k] < n && k == n && check(x, k)) {
            for(int i = 0; i < k; i ++){
                cout << x[i] << " ";
            }
            cout << endl;
            cnt ++;
        }
        else {

        }
    }
}

int main(){
    n = 8;
    Queue(n)
    return 0;
}
