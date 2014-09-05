/*
    ID : problem6
    PROG : ride
    LANG : C++
    Quote : ��ѧ�뾲Ҳ ����ѧҲ ��ѧ���Թ�� ��־���Գ�ѧ
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct point{
  int x, y;
  bool operator < (const point & b) const{
    return x == b.x ? y < b.y : x < b.x;
  }
};
point p[maxn];


int n , t , x , f[maxn] , c[maxn];

struct bit
{
    int t[100100] , n;
    void cl() { memset(t, 0, sizeof(t)); }
    void add(int x,int y) {
        for ( ; x; x -= x & (-x) ) if( c[y] < c[t[x]] ) t[x] = y;
    }
    int ask(int x) {
        int s = 0;
        for ( ; x <= 100000; x += x & (-x) ) if ( c[s] > c[t[x]] ) s = t[x];
        return s;
    }
} T;

int main(){
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF){
    for(int i = 0; i < n; i ++){
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p, p+n);

  }
  return 0;
}
