// Accepted	220K	0MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 500+10;
const int inf = 0x3f3f3f3f;
const double eps = 1E-32;

struct Hnode{
  int v, dist;
  bool operator < (const Hnode& a) const{
    return dist > a.dist;
  }
};

struct node{
  int to, cost;
};
// �����洢ͼ
vector<node> G[maxn];
int vis[maxn];
int d[maxn];
int fa[maxn];

void dijkstra(int src, int n){
  //memset(vis, 0, sizeof(node));
  // ��ʼ��Ҫע�Ⱑ������������ ��������������
  memset(vis, 0, sizeof(vis));
  memset(d, inf, sizeof(d));
  memset(fa, -1, sizeof(fa));
  priority_queue<Hnode> q;
  Hnode temp;
  temp.v = src, temp.dist = 0;
  q.push(temp);
  d[src] = 0;
  while(!q.empty()){
    Hnode cur = q.top();
    q.pop();
    if(vis[cur.v] != 0) continue;
    vis[cur.v] = 1;
    for(int j = 0; j < G[cur.v].size(); j ++){
      node next = G[cur.v][j];
      if(d[next.to] > d[cur.v] + next.cost){
          d[next.to] = d[cur.v] + next.cost;
          fa[next.to] = cur.v;
          Hnode newnode ;
          newnode.v = next.to , newnode.dist = d[next.to];
          q.push(newnode);
      }
    }
  }
  //for(int i = 1; i <= n; i ++){
  //  cout << i << " " << fa[i] << " " << d[i] << endl;
  //}
}

/*
����ÿһ����ȫ���µ�ʱ�䡣��ÿһ�е����˵Ĺؼ���Ϊi ��j��
����һ����ȫ���µ�ʱ��Ϊ
(dist[i] + dist[j] + edge[i][j])/2.0��
(ȷʵ����)�����ͬһֱ���ϺͲ�ֱͬ���϶��У����Ի��ǵ������ѧ����
����edge[i][j]Ϊ���ӵ�i��j ���Źؼ��Ƶ��е���
������ʱ�䡣ȡ��������ȫ����ʱ������ֵ����Ϊmax2
*/

void solve(int n){
  double lastfall = -inf;
  int k = 0;
  for(int i = 1; i <= n; i++){
      if( lastfall < (double)d[i]){
        //��Щ��ͨ
        lastfall = d[i];
        k = i;
      }
  }
  // ö��ÿһ����,�����бߵ��µ����ֵ
  int a, b;
  double bettwen = -inf;
  for(int i = 1; i <= n; i ++){
    for(int j = 0; j < G[i].size(); j ++)
      if((d[i] + d[G[i][j].to] + G[i][j].cost)/2.0 > bettwen){
        bettwen = (d[i]+d[G[i][j].to]+G[i][j].cost)/2.0;
        a = i;
        b = G[i][j].to;
      }
  }
  if(lastfall >= bettwen ){
    printf("The last domino falls after %.1f seconds, at key domino %d.\n", lastfall, k);
    // G++ ��%.1f��   c++ ��.1lf��
    // һ��ϰ���϶���%lf���룬%f���
    // MinGW���gcc��g++�в�֧����"%lf"��Ϊ���
    //C89��׼��double������"%lf"���룬��"%f"�����
    //C99��׼�� double������"%lf"���룬��"%lf"�����
    //Ȼ����ĳЩlibc�Ķ�̬����δ���µ�C99��׼����Ȼ����C89��׼���﷨��
  }
  else {
    printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", bettwen, a>b?b:a, a>b?a:b);
  }
  printf("\n");
  //�������һ�����ܴ�
}

int main()
{
  int n, m;
  int Case = 1;
  //freopen("in.txt", "r", stdin);
  while(scanf("%d%d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    for(int i = 0; i <= maxn; i ++){
      G[i].clear();
    }
    int a, b, l;
    for(int i = 0; i < m; i ++){
      scanf("%d%d%d", &a, &b, &l);
      node temp;
      temp.to = b, temp.cost = l;
      G[a].push_back(temp);
      temp.to = a, temp.cost = l;
      G[b].push_back(temp);
    }
    /*
   for(int i = 1; i <= n; i ++){
    for(int j = 0; j < G[i].size(); j ++){
      cout << i << " " << G[i][j].to << " " << G[i][j].cost << endl;
    }
   }
  */
   printf("System #%d\n", Case++);
   dijkstra(1, n);
   solve(n);
  }
  return 0;
}
