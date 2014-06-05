//Accepted 632K 110MS
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int dp[40005];

int binasearch(int *temp, int left, int right, int key)
{
  int l = left;
  int r = right-1;
  while(l <= r){
    int mid = (l+r)/2;
    if(temp[mid-1] < key && key <= temp[mid]) return mid;
    else if(key < temp[mid]) r = mid - 1;
    else l = mid + 1;
  }
}

int LIS(int *data, int n)
{
  memset(dp, 0, sizeof(dp));
  int temp[40005];
  int tsize = 0;
  dp[0] = 1;
  temp[tsize++] = data[0];
  int pos = 0;
  for(int i = 1; i < n; i ++){
    int x = data[i];
    if(data[i] <= temp[0]) pos = 0;
    else if(data[i] > temp[tsize-1]) pos = tsize ++;
    else pos = binasearch(temp, 0, tsize, x);
    dp[i] = pos+1;
    temp[pos] = x;
  }

  int maxn = 0;
  for(int i = 0; i < n; i ++){
    //printf("~%d\n", dp[i]);
    if(dp[i] > maxn) maxn = dp[i];
  }
  return maxn;
}

int main()
{
  int t;
  int data[40005];
  scanf("%d", &t);
  while(t --){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
      scanf("%d", &data[i]);
    int ans = LIS(data, n);
    printf("%d\n", ans);
  }
  return 0;
}
