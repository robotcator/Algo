/*
    ID: problem6
    PROG : Crime Wave ¨C The Sequel
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cmath>
using namespace std;

const int maxn = 25;
const double inf = 1000000000;
const double eps = 1e-7;
double graph[maxn][maxn];

double Lx[maxn], Ly[maxn];
bool S[maxn], T[maxn];
int Mx[maxn], My[maxn];
int n, m;

bool dfs(int u){
  S[u] = true;
  for(int v = 0; v < m; v ++){
    if(!T[v] && (fabs(Lx[u]+Ly[v]-graph[u][v])< eps)){
      T[v] = true;
      if(My[v] == -1 || dfs(My[v])){
        Mx[u] = v; My[v] = u;
        return true;
      }
    }
  }
  return false;
}

void update(){
  double a = inf;
  for(int i = 0; i < n; i ++) if(S[i])
    for(int j = 0; j < m; j ++) if(!T[j])
        a = min(a, Lx[i]+Ly[j]-graph[i][j]);
  for(int i = 0; i < n; i ++)
    if(S[i]) Lx[i] -= a;
  for(int j = 0; j < m; j ++)
    if(T[j]) Ly[j] += a;
}

void KM(){
  memset(Mx, -1, sizeof(Mx));
  memset(My, -1, sizeof(My));
  memset(Ly, 0, sizeof(Ly));
  for(int i = 0; i < n; i ++){
    Lx[i] = -inf;
    for(int j = 0; j < m; j ++){
      Lx[i] = max(Lx[i], graph[i][j]);
    }
  }
  for(int i = 0; i < n; i ++){
    while(true){
      memset(S, 0, sizeof(S));
      memset(T, 0, sizeof(T));
      if(dfs(i)) break;
      else update();
    }
  }
}


int main(){
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j ++){
        scanf("%lf", &graph[i][j]);
        graph[i][j] = -graph[i][j];
      }
    }
    KM();
//    cout << 123 << endl;
//    return 0;
    double sum = 0;
    for(int i = 0; i < n; i ++){
      if(Mx[i] != -1){
        sum += graph[i][Mx[i]];
      }
    }
    printf("%.2f\n", -sum/(1.0*n));
  }
  return 0;
}
