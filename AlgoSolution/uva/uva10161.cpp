#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        int k = 1;
        int sum = 1;
        while(sum < n) { k ++; sum += 2*(k-1) + 1; }
        //cout << "k " << k  << " sum " << sum << endl;
        sum -= 2*k - 1;
        //cout << sum << endl;
        int left = n-sum;
        //cout << left << endl;
        if(k % 2 == 0){
            if((2*k-1)/2 + 1 > left) printf("%d %d\n", left, k);
            else if((2*k-1)/2 + 1 < left) printf("%d %d\n", k, 2*k-1-left+1);
            else printf("%d %d\n", k, k);
        }
        else{
            if((2*k-1)/2+1 > left) printf("%d %d\n", k, left);
            else if((2*k-1)/2+1 < left) printf("%d %d\n", 2*k-1-left+1, k);
            else printf("%d %d\n", k, k);
        }
    }
    return 0;
}

/*
conclusion:
13779207 	10161 	Ant on a Chessboard
Accepted 	C++11 	0.012 	2014-06-22 14:30:23

1: 数学题，简要写出前几项，然后归纳推理
*/
