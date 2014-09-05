#include <cstdio>
#include <cstring>

using namespace std;
//  1--32001
//
int C[35000];
int size;
//
int lowbit(int x) { return (x & -x); }
void add(int x, int v) {
  while(x <= size){
    // printf("%d\n", x);
    C[x] += v; x += lowbit(x);
  }
}
int sum(int x){
  int ret = 0;
  while(x > 0){
    ret += C[x]; x -= lowbit(x);
  }
  return ret;
}

int main()
{
  int n;
  int cnt[15005];
  size = 32001;
  freopen("in.txt", "r", stdin);
  // for(int i = 1; i <= 15; i ++)
  //  printf("%d %d\n", i, lowbit(i));
  while(scanf("%d", &n) != EOF){
    memset(C, 0, sizeof(C));
    // printf("%d %d\n", m, size);
    int x, y;
    for(int i = 1; i <= n; i ++){
      scanf("%d%d", &x, &y);
      add(x+1, 1);
      int num = sum(x+1);
      cnt[num-1] ++;
    }
    for(int i = 0; i < n; i ++)
      printf("%d\n", cnt[i]);
  }
  return 0;
}
