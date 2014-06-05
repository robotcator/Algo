#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[50005];

int suffix[100005];
int size;


int lowbit(int x) { return x & -x; }

void add(int x, int v){
  while(x <= size){
      suffix[x] += v;
      x += lowbit(x);
  }
}

int query(int x){
  int sum = 0;
  while(x > 0){
    sum += suffix[x];
    x -= lowbit(x);
  }
  return sum;
}



int main()
{
  int t, n, flag;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    size = n;
    flag = 1;
    memset(suffix, 0, sizeof(suffix));
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        add(i, a[i]);
    }
    int x, y;
    char data[10];
    printf("Case %d:\n", flag ++);
    while(scanf("%s", data) && strcmp(data, "End") != 0){
        scanf("%d%d", &x, &y);
        if(strcmp(data, "Query") == 0){
          cout << query(y)-query(x-1) << endl;
        }
        else if(strcmp(data, "Add") == 0){
          add(x, y);
        }
        else if(strcmp(data, "Sub") == 0){
          add(x, -y);
        }
    }
  }
  return 0;
}
