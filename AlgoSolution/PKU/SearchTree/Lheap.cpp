#include <cstdio>
const int  maxn = 1000 + 10;

struct node{
  int key;
  int f, l, r, dist;
};
node Lheap[maxn];

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int merge(int a, int b) {
   if(a == -1) return b;
   if(b == -1) return a;
   if(Lheap[a].key > Lheap[b].key) swap(a, b);
   Lheap[a].r = merge(Lheap[a].r, b);
   Lheap[Lheap[a].r].f = a;
   if(Lheap[Lheap[a].r].dist > Lheap[Lheap[a].l].dist)
      swap(Lheap[a].l, Lheap[a].r);
   if(Lheap[a].r == -1) Lheap[a].dist = 0;
   else Lheap[a].dist = Lheap[Lheap[a].r].dist + 1;
   return a;
}

void Insert(int root, int i, int key) {
  Lheap[i].key = key;
  Lheap[i].f = Lheap[i].l = Lheap[i].r = -1;
  root = merge(root, i);
}

node DeleteMin(int root) {
  node Min;
  Min.key = Lheap[root].key;
  Min.l = Min.r = -1;
  Min.dist = 0;
  root = merge(Lheap[root].l, Lheap[root].r);
  return Min;
}

node Delete(int root, int i)
{

}
void build(int *data, int n)
{

}

int main()
{
  int n, key;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++){
    scanf("%d", &key);
    Insert(0, i, key);
  }
  return 0;
}
