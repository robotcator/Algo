/*
    ID: problem6
    PROG : Room and Moor
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
int A[maxn];
int st[maxn], ed[maxn];
int cnt[maxn];

int main(){
  int t, n;
  scanf("%d", &t);
  while(t--){
      scanf("%d", &n);
      for(int i = 0; i < n; i ++){
        scanf("%d", &A[i]);
      }
      int s, e;
      for(int i = 0; i < n;i ++){
        if(A[i]) { s = i; break;}
      }
      for(int i = n-1; i >= 0; i --){
        if(!A[i]) { e = i; break;}
      }
      //cout << s << " " << e << endl;
      int num = 0;
      for(int i = s; i <= e; i ++){
        st[num] = i;
        while(A[i]){
          i ++;
        }
        cnt[num] = i - st[num];
        while(!A[i] && i <= e){
          i ++;
        }
        ed[num++] = --i;
      }
      /*
      for(int i = 0; i < num; i ++){
        cout << st[i] << " " << ed[i] << " " << cnt[i] << endl;
      }
      */



  }
  return 0;
}
