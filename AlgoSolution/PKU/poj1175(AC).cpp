// 824K 32MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const double eps = 1E-8;
int gaze[105][105];
int vis[105][105];
vector<double> hash[997];
// 判重
int cnt[997][300];
int num;
// 连通块的个数
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};


struct point{
  int x, y;
};

double get_sum(vector<point> a){
  double sum = 0;
  int size = a.size();
  for(int i = 0; i < size; i ++){
    for(int j = (i+1); j < size; j ++){
      sum += sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y));
    }
  }
  return sum;
}

void dfs(int i, int j, vector<point>& a){
  point cur;
  cur.x = i, cur.y = j;
  a.push_back(cur);
  vis[i][j] = 1;
  point next;
  for(int i = 0; i < 8; i ++){
    next.x = cur.x + dx[i];
    next.y = cur.y + dy[i];
    if(vis[next.x][next.y] == 0 && gaze[next.x][next.y] == 1){
      dfs(next.x, next.y , a);
    }
  }
}

int get_key(double sum){
  return ((int)sum)%997;
}

int get_hash(double sum){
  int key = get_key(sum);
  int size = hash[key].size();
  for(int i = 0; i < size; i ++){
    if(fabs(hash[key][i] - sum) < eps) return cnt[key][i];
  }
  hash[key].push_back(sum);
  cnt[key][size] = ++num ;
  return num;
}
// 哈希的作用
// 有则插入没有则增加，且返回哈希表中元素映射的值
void paint(vector<point>& a, int temp){
  for(int i = 0; i < a.size(); i ++){
    gaze[a[i].x][a[i].y] = temp+'a'-1;
  }
}

int main()
{
  int w, h;
  char data[105];
  scanf("%d%d", &w, &h);
  for(int i = 0; i < h; i ++){
    scanf("%s", data);
    for(int j = 0; j < w; j ++){
      gaze[i][j] = data[j]-'0';
    }
  }
  vector<point> a;
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < 997; i ++){
    hash[i].clear();
  }
  num = 0;
  for(int i = 0; i < h; i ++){
    for(int j = 0; j < w; j ++){
      if(gaze[i][j] != 0 && vis[i][j] == 0){
        a.clear();
        dfs(i, j, a);
        if(a.size() > 0){
          double sum = get_sum(a);
          //cout << sum << endl;
          int temp = get_hash(sum);
          //cout << temp << endl;
          paint(a, temp);
        }
      }
    }
  }

  for(int i = 0; i < h; i ++){
    for(int j = 0; j < w; j ++){
     if(gaze[i][j] != 0) printf("%c", gaze[i][j]);
     else printf("%c", gaze[i][j]+'0');
    }
    printf("\n");
  }

  return 0;
}
