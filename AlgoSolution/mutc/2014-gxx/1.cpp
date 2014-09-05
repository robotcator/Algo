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

const int maxn = 100000+10;
long long cnt;
int d[maxn];
int t[maxn];

void merge_sort(int *a, int l, int r, int *t){
  if(r - l > 1){
    int mid = l + (r-l)/2;
    int p = l, q = mid, i = l;
    merge_sort(a, l, mid, t);
    merge_sort(a, mid, r, t);
    while(p < mid || q < r){
      if(q >= r || (p < mid && a[p] <= a[q]))
        t[i++] = a[p++];
      else {
        t[i++] = a[q++];
        cnt += mid-p;
      }
    }
    for(i = l; i < r; i ++)
      a[i] = t[i];
  }
}

int main(){
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    cnt = 0;
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i ++){
      scanf("%d", &d[i]);
    }
    merge_sort(d, 0, n, t);
    //cout<< cnt << endl;
    //printf("%d\n", cnt-k >= 0 ? cnt-k : 0);
    long long ans = cnt;
    if(cnt-k >= 0) cout << cnt-k << endl;
    else cout << "0" << endl;
  }
  return 0;
}
