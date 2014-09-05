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

template <class T>
inline void Input(T &x){
  char c; x = 0;
  while((c = getchar()) < '0' || c > '9');
  while(c >= '0' && c <= '9') x = x*10 + (c-'0'), c = getchar();
}
template <class T>
inline void Output(T x){
  if(x > 9) Output(x/10);
  putchar(x%10+'0');
}
const int maxn = 25;
__int64 ex[maxn];
int main(){
  int n;
  ex[1] = 0; ex[2] = 1;
  for(int i = 3; i <= 20; i ++)
    ex[i] = (i-1)*(ex[i-2] + ex[i-1]);
  while(scanf("%d", &n) != EOF){
    //cout << ex[n] << endl;
    Output(ex[n]);
    puts("");
  }
  return 0;
}

