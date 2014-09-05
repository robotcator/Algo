/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000+100;
int data[maxn][maxn];
int n;

int lowbit(int x) { return x&(-x); }

void add(int x, int y, int val){
  for(int i = x; i <= n; i += lowbit(i)){
    for(int j = y; j <= n; j += lowbit(j)){
    //cout << i << " " << j << endl;
      data[i][j] += val;
    }
  }
}

int sum(int x, int y){
  int ans = 0;
  for(int i = x; i > 0; i -= lowbit(i)){
    for(int j = y; j > 0 ; j -= lowbit(j)){
     // cout << "i" << i << " " << j << endl;
      ans += data[i][j];
    }
  }
  return ans;
}

int main(){
  int t, q;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &q);
    memset(data, 0, sizeof(data));
    char comm[5];
    int x1, y1, x2, y2;
    for(int i = 1; i <= q; i ++){
      scanf("%s", comm);
      if(strcmp(comm, "C") == 0){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        add(x1, y1, 1);
        add(x2+1, y2+1, 1);
        add(x1, y2+1, 1);
        add(x2+1, y1, 1);
      }else{
        scanf("%d%d", &x1, &y1);
        int ans = sum(x1, y1);
        printf("%d\n", ans%2);
      }
    }
    printf("\n");
  }
  return 0;
}
