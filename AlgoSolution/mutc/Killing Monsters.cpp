/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
/*
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100000+10;
const int inf = 0x3f3f3f3f;

int path[4*maxn];
int setv[4*maxn];

void pushdown(int root, int l, int r){
  int len = r-l+1, lc = 2*root, rc = 2*root+1;
  if(setv[root]){
    setv[lc] += setv[root];
    setv[rc] += setv[root];
    path[lc] +=  setv[root]*(len/2+1);
    path[rc] += setv[root]*(len-len/2-1);
    // 注意这里的个数
    setv[root] = 0;
  }
}

void pushup(int root, int l, int r){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  path[root] = path[lc] + path[rc];
}

void modify(int root, int l, int r, int x, int y, int z){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(x <= l && r <= y){
    setv[root] += z;
    path[root] += z*(r-l+1);
  }else{
    pushdown(root, l, r);
    if(x <= mid) modify(lc, l, mid, x, y, z);
    if(y > mid) modify(rc, mid+1, r, x, y, z);
    pushup(root, l, r);
  }
}

long long ans = 0;
void query(int root, int l, int r, int x, int y){
  int mid = (l+r)/2, lc = 2*root, rc = 2*root+1;
  if(setv[root]){
    if(x <= l && r <= y){
      ans += setv[root]*(r-l+1);
    }else{
      pushdown(root, l, r);
      if(x <= mid) query(lc, l, mid, x, y);
      if(y > mid) query(rc, mid+1, r, x, y);
      pushup(root, l, r);
    }
  }
  else if(x <= l && r <= y){
    ans += path[root];
  }else{
    if(x <= mid) query(lc, l, mid, x, y);
    if(y > mid) query(rc, mid+1, r, x, y);
    pushup(root, l, r);
  }
}

void print(int root, int l, int r){
  printf("root %d %d\n", root, path[root]);
  if(l < r){
    print(2*root, l, (l+r)/2);
    print(2*root+1, (l+r)/2+1, r);
  }
}

int main(){
  int n, m, k;
  while(scanf("%d", &n) != EOF){
    memset(path, 0, sizeof(path));
    memset(setv, 0, sizeof(setv));
    if(n == 0) break;
    int l, r, d;
    scanf("%d", &m);
    memset(path, 0, sizeof(path));
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &l, &r, &d);
      modify(1, 1, n, l, r, d);
    }
    scanf("%d", &k);
    int h, x, num;
    num = 0;
    for(int i = 0; i < k; i ++){
      scanf("%d%d", &h, &x);
      ans = 0;
      query(1, 1, n, x, n);
   //   print(1, 1, n);
      if(ans < h) num ++;
    }
    printf("%d\n", num);
  }
  return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100000+10;
const int inf = 0x3f3f3f3f;

long long path[maxn];

int main(){
  int n, m, k;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    int l, r, d;
    scanf("%d", &m);
    memset(path, 0, sizeof(path));
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &l, &r, &d);
      path[l] += d;
      path[r+1] += -d;
    }
    for(int i = 1; i <= n; i ++){
      path[i] += path[i-1];
     // printf("%d ", path[i]);
    }
    //printf("\n");

    for(int i = n-1; i > 0; i --)
      path[i] += path[i+1];
    scanf("%d", &k);
    long long h, x, num;
    num = 0;
    for(int i = 0; i < k; i ++){
      scanf("%I64d%I64d", &h, &x);
      if(h > path[x]) num ++;
    }
    printf("%I64d\n", num);
  }
  return 0;
}
