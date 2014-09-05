#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int data[100005];
int sum[100005];
int dp[100005];

const int inf = 0x3f3f3f3f;

struct heap{
  int elem[100005];
  int size;
  heap(){
    memset(elem, 0, sizeof(elem));
    size = 0;
  }
};

// 要对数据进行修改，采用引用比指针较好理解

 void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swim(heap &a, int pos){
  int q = pos >> 1, x = a.elem[pos];
  while(q && x < a.elem[q]){
    a.elem[pos] = a.elem[q];
    pos = q;
    q = pos >> 1;
  }
  a.elem[pos] = x;
}

void Insert(heap& a, int key){
    a.elem[++a.size] = key;
    swim(a, a.size);
}


void sink(heap &a, int pos){
  int q = pos << 1, x = a.elem[pos];
  while(q <= a.size){
    if(q < a.size && a.elem[q+1] < a.elem[q]) q ++;
    // 左右节点比较,看往哪边下沉
    if(a.elem[q] >= x) break;
    a.elem[pos] = a.elem[q];
    pos = q;
    q = pos << 1;
  }
  a.elem[pos] = x;
}

/*
void sink(heap &a, int pos){
  int l = 2*pos, r =  2*pos + 1;
  int minn;
  if(l <= a.size && a.elem[pos] < a.elem[l]) minn = l;
  else minn = pos;
  if(r <= a.size && a.elem[pos] < a.elem[minn]) minn = r;
  if(minn != pos){
    swap(a.elem[minn], a.elem[pos]);
    sink(a, minn);
  }
}
*/

void build(heap& a, int n){
  a.size = n;
  for(int i = a.size/2; i > 0; i --)
    sink(a, i);
}


void Delete(heap& a, int key){
  int pos = 0;
  for(int i = 1; i <= a.size; i ++)
    if(a.elem[i] == key) {
        pos = i; break;
    }
  if(pos != 0){
    a.elem[pos] = a.elem[a.size--];
    sink(a, pos);
  }
}

void DeleteMin(heap& a){
  a.elem[1] = a.elem[a.size--];
  sink(a, 1);
}

int Minn(heap a){
  return a.elem[1];
}


int main()
{
  int n, m;
  /*
  heap b;
  for(int i = 0; i < 6; i ++){
    scanf("%d", &n);
    Insert(b, n);
  }
  for(int i = 1; i <= 6; i++)
    cout << b.elem[i] << endl;
  for(int i = 1; i <= 6; i ++){
    scanf("%d", &n);
    Delete(b, n);
    for(int i = 1; i <= b.size; i ++){
      cout << b.elem[i] << endl;
    }
  }
  return 0;
*/
  //freopen("in.txt", "r", stdin);
  // 如何处理负数的问题
  while(scanf("%d%d", &n, &m) != EOF){
    sum[0] = 0;
    for(int i = 1; i <= n; i ++){
      scanf("%d", &data[i]);
      sum[i] = sum[i-1] + data[i];
      // dp[i] = data[i];
    }
    heap a;
    int minn;
    dp[0] = -0x3f3f3f3f;
    for(int i = 1; i <= n; i ++){
      Insert(a, sum[i-1]);
      if(i-m-1 >= 0) Delete(a, sum[i-m-1]);
      minn = Minn(a);
      //  注意如何处理负数
      if(dp[i-1] < sum[i]- minn)
        dp[i] = sum[i] - minn;
      else dp[i] = dp[i-1];
    }
    cout << dp[n] << endl;
  }
  return 0;
}
