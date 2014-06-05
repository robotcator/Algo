#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100+10;
int p[maxn];
struct seg{
  int l, r;
}s[maxn];
int cmp(seg a, seg b){
  return a.l < b.l;
}
int cnt[maxn];
int vis[maxn];
int num[maxn];
int color[maxn];

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF){
    for(int i = 0; i < n; i ++)
      scanf("%d", &p[i]);
    for(int i = 0; i < m; i ++)
      scanf("%d%d", &s[i].l, &s[i].r);
    sort(s, s+m, cmp);
    memset(vis, -1, sizeof(vis));
    for(int j = 0; j < m; j ++){
        for(int i = 0; i < n; i ++){
          if( p[i] >= s[j].l && p[i] <= s[j].r){
            cnt[j] ++;
            vis[i] = j;
          }
        }
    }
    memset(num , 0 , sizeof(num));
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j ++){
        if( p[i] >= s[j].l && p[i] <= s[j].r){
           if(num[j] < cnt[j] && color[i] == -1)   color[i] = 0;
           else if(color[i] == -1) color[i] = 1;
           num[j] ++;
        }
      }
    }
    for(int i = 0; i < n; i ++)
      printf("%d ", color[i]);
  }
  return 0;
}
