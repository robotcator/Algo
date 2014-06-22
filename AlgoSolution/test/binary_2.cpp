#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int binary(int a[][10], int m, int n, int x){
    int i = 0, j = n-1;
    for(int i = 0; i < m; i ++){
        if(a[i][j] >= x){
            while(j >= 0) {
                if(a[i][j] == x){
                    cout << i << " " << j << endl;
                    return 1;
                }
                j --;
            }
            return 0;
        }
    }
    return 0;
}

int binary_rec(int a[][10], int m, int n, int x){

}

int main(){
    int a[][10] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {12, 13, 14, 15, 16}
    };
    int x;
    while(scanf("%d", &x) != EOF){
        int ans = binary(a, 3, 5, x);
        cout << ans << endl;
    }
    return 0;
}
