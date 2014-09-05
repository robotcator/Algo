#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

LL a[100005];
vector<LL> G[100005];
bool k[100005];
LL b[100005], c[100005], d[100005], idx[100005];

int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n==0) return 0;
        memset(k,0,sizeof(k));
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            G[a[i]].clear();
            k[a[i]]=1;
        }
        LL now=0;
        for(int i=1;i<=100000;i++){
            if(k[i]){
                d[now++]=i;
            }
        }
        //

        for(int i=0;i<now;i++){
            LL l=d[i];
            for(LL j=1;j*j<=l;j++){
                if(l%j==0){
                    G[l].push_back(j);
                    if(j*j!=l){
                        G[l].push_back(l/j);
                    }
                }
            }
        }
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(idx,-1,sizeof(idx));

        for(LL i=0;i<n;i++){
            if(idx[a[i]]==-1)
                b[i]=i;
            else  b[i]=idx[a[i]];
            for(LL j=0;j<G[a[i]].size();j++){
                LL e=G[a[i]][j];
                idx[e]=i;
            }
        }

        for(LL i=n-1;i>=0;i--){
            if(idx[a[i]]==-1)
                c[i]=i;
            else  c[i]=idx[a[i]];
            for(LL j=0;j<G[a[i]].size();j++){
                LL e=G[a[i]][j];
                idx[e]=i;
            }
        }

        LL ans=0;
        for(LL i=0;i<n;i++){
            ans+=(a[b[i]])*(a[c[i]]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}


/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100000+10;
const int inf = 0x3f3f3f3f;
struct T{
  int l, r;
  int d;
}t[maxn];

struct M{
  int h, x;
}mon[maxn];

int cmp1(M a, M b){
  if(a.x == b.x) return a.h < b.h;
  else return a.x < b.x;
}
int cmp2(T a, T b){
  if(a.l == b.l) return a.r < b.r;
  else return a.l < b.l;
}
int path[maxn];

int main(){
  int n, m, k;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    scanf("%d", &m);
    memset(path, 0, sizeof(path));
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &t[i].l, &t[i].r, &t[i].d);
      for(int j = t[i].l; j <= t[i].r; j ++){
        path[j] += t[i].d;
      }
    }
    sort(t, t+m, cmp2);
    scanf("%d", &k);
    for(int i = 0; i < k; i ++){
      scanf("%d%d", &mon[i].h, &mon[i].x);
    }
    sort(mon, mon+k, cmp1);
    for(int i = 1; i <= n; i ++){
      path[i] += path[i-1];
    }
    int ans = 0;

    for(int i = 0; i < k; i ++){
     // cout << mon[i].x << "y" << endl;
     // cout << path[n]-path[mon[i].x-1] << "x" << endl;
      if(path[n]-path[mon[i].x-1] <= mon[i].h) ans ++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
*/
