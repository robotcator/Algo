/*
    ID: problem6
    PROG : Bender Problem
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int maxn = 500+10;
struct point {
  int x, y;
};
point p[maxn];
int path[maxn];
int x[maxn];

int main(){
    int n, m;
    // 容器和迭代器联合使用
    while(scanf("%d%d", &n, &m) != EOF){
      for(int i = 1; i <= n; i ++){
        scanf("%d%d", &p[i].x, &p[i].y);
      }
      p[0] = p[n];
      p[n+1] = p[1];

      for(int i = 0; i <= n; i ++){
        x[i] = abs(p[i+1].x-p[i].x) + abs(p[i+1].y-p[i].y);
      }
      int d;
      multimap<int, int> r, rr;
      multimap<int, int>::iterator it;
      for(int i = 1; i <= m; i ++){
        scanf("%d", &d);
        rr.insert(make_pair(d, i));
      }
      int flag = 1;
      for(int i = 1; i <= 2; i ++){
        flag = 1;
        path[i-1] = -1;
        r = rr;
        for(int j = i; j <= n; j += 2){
          it = r.find(x[j-1]+x[j]);
          //cout << j << " " << it->first << endl;
          if(it == r.end()){
            flag = 0;
            break;
          }
          path[j] = it->second;
          path[j+1] = -1;
          r.erase(it);
        }
        if(flag){
          puts("YES");
          for(int k = 1; k <= n; k ++){
            printf("%d ", path[k]);
          }
          printf("\n");
          break;
        }
      }
      if(!flag) puts("NO");
    }
    return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
7342439 	2014-08-04 11:01:19 	xiao_robot 	A - Bender Problem 	GNU C++0x 	Accepted 	62 ms 	196 KB
*/
