//Accepted 172K 0MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int dp[1005];
int temp[1003];
// 用来记录最大序列中的值

int binasearch(int *temp, int left, int right, int key)
{
    int l = left;
    int r = right-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(temp[mid-1] < key && key <= temp[mid]) return mid;
        else if(key < temp[mid]) r = mid-1;
        else l = mid+1;
    }
}

int LIS(int *data, int n)
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int tsize = 0;
    temp[tsize ++] = data[0];
    int pos = 0;
    for(int i = 1; i < n; i ++){
        int x = data[i];

        if(x < temp[0]) pos = 0;
        else if(x > temp[tsize-1]) pos = tsize ++;
        else pos = binasearch(temp, 0, tsize, x);

        temp[pos] = x;
        dp[i] = pos+1;
    }

    int maxn = 0;
    for(int i = 0; i < n; i ++){
      //  printf("~%d\n", dp[i]);
        if(maxn < dp[i]) maxn = dp[i];
    }
    return maxn;
}

int main()
{
    int n;
    int data[1005];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i ++)
            scanf("%d", &data[i]);
        int ans = LIS(data, n);
        printf("%d\n", ans);
    }
    return 0;
}
