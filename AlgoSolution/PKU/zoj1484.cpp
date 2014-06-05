/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cnt;

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

int main()
{
  int n;
  int data[5005];
  int a[5005];
  int T[5005];
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i ++){
      scanf("%d", &data[i]);
    }
    int res = 0x3f3f3f3f;
    for(int i = 0; i < n; i ++){
      cnt = 0;
      int k = 0;
      for(int j = i; j < n; j ++)
        a[k++] = data[j];
      for(int j = 0; j < i; j ++)
        a[k++] = data[j];
     //  for(int i = 0; i < n; i ++)
     //   cout << a[i] << endl;
     // cout << endl;

      merge_sort(a, 0, n, T);
      if(cnt < res) res = cnt;
    }
    cout << res << endl;
  }
  return 0;
}
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cnt;
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

int main()
{
  int n;
  int data[5005];
  int a[5005];
  int T[5005];
  while(scanf("%d", &n) != EOF){
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
      a[i] = data[i];
    }
    cnt = 0;
    merge_sort(a, 1, n+1, T);
    int res = cnt;
    //cout << cnt << endl;
    for(int i = 1; i < n; i ++){
      cnt += n - 2*data[i] - 1;
     // 归并后data是有序的
     // cout << cnt << endl;
      if(res > cnt) res = cnt;
    }
    cout << res << endl;
  }
  return 0;
}
