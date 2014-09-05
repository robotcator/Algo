#include <cstdio>
#include <cstring>

const int maxn = 1000 + 10;

void swap(int i, int m, int *heap)
{
  int temp = heap[i];
  heap[i] = heap[m];
  heap[m] = temp;
}

void Adjust(int *heap, int n, int i)
{
  int l = 2*i, r = 2*i+1;
  int m ;
  if(l <= n && heap[l] < heap[i]) m = l;
  else m = i;
  if(r <= n && heap[r] < heap[m]) m = r;
  if(m != i){
    swap(i, m, heap);
    Adjust(heap, n, m);
  }
}

void buildHeap(int *heap, int n)
{
  for(int i = n/2; i > 0; i --){
    Adjust(heap, n, i);
  }
}

int minn(int *heap)
{
  return heap[1];
}

void DeleteMin(int *heap, int& n)
{
  swap(1, n, heap);
  n --;
  Adjust(heap, n, 1);
}

void Insert(int *heap, int key, int n){
  heap[++n] =
}

int main()
{
  int n;
  int heap[50];
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++)
    scanf("%d", &heap[i]);
  buildHeap(heap, n);
  DeleteMin(heap, n);
  for(int i = 1; i <= n; i ++)
    printf("%d ", heap[i]);
  return 0;
}
