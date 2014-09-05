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

const int maxn = 1000000+10;
int a[maxn];
int b[maxn];
int R[maxn];
 // hang on a second

int main(){
  int n;
  cout << uinf << endl;
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  memset(R, 0, sizeof(R));
  int m = unique(b+1, b+n+1)-b-1;
  for(int i = 1; i <= n; i++){
    a[i] = lower_bound(b+1, b+m+1, a[i])-b;

  }
  return 0;
}
