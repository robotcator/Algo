#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct HeapNode{
  int d;
  bool operator < (const HeapNode& a) const{
    return d > a.d;
  }
};

struct edge{
  int from, to;
  int dist;
};

vector<int> G[maxn];

priority_queue<HeapNode> p;

void dijkstra(){

}

int main()
{
  int a[1000];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++){
    scanf("%d", &a[i]);
    HeapNode n;
    n.d = a[i];
    p.push(n);
  }
  for(int i = 0; i < n; i ++)
    printf("%d ", a[i]);
  printf("\n");
  while(!p.empty()){
    HeapNode temp;
    temp = p.top();
    p.pop();
    printf("%d ", temp.d);
  }

  return 0;
}
