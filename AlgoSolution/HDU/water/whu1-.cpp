#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int maxn = 100000+10;
int vis[maxn];

int Set[maxn];

int Find(int x) {
  return x == Set[x] ? Set[x] : Set[x] = Find(Set[x]);
}

void Union(int a, int b){
  int fa = Find(a);
  int fb = Find(b);
  if(fa != fb) {
    Set[b] = fa;
  }
}


int main()
{
  int n, m, q;
  int v, e;
  map<int, int> a;
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    scanf("%d", &m);
    int a, b, c;
    for(int i = 1; i <= n; i++) Set[i] = i;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &a, &b, &c);
      if(c == 0) Union(a, b);
    }
    v = 0;
    for(int i = 1; i <= n; i ++){
        cout << Set[i] << endl;
    }

    scanf("%d", &q);
    int s, t;
    for(int i = 0; i < q; i ++){
        scanf("%d%d", &s, &t);
    }
  }
  return 0;
}
