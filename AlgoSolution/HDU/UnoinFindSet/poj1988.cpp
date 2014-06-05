#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 30000+10;
int Set[maxn];
int Rank[maxn];
// 表示在i的下面有多少个数
void Init(){
  memset(Rank, 0, sizeof(Rank));
  for(int i = 0; i <= maxn; i++){
    Set[i] = i;
  }
}

int Find(int x){
  if(x != Set[x]){
    int fa = Set[x];
    Set[x] = Find(Set[x]);
    Rank[x] = Rank[fa]+1;
  }
  return Set[x];
  //  无论如何都要带返回值
}

void Unoin(int a, int b){
  int fa = Find(a);
  int fb = Find(b);
  Set[fb] = fa;
  Rank[fa] = Rank[fb]+Rank[fa]+1;
}

int main()
{
  int p, a, b;
  char ch;
  while(scanf("%d\n", &p) != EOF){
    Init();
    for(int i = 0; i < p; i ++){
      ch = getchar();
      if(ch == 'M'){
        scanf("%d%d", &a, &b);
        getchar(); // 吃掉回车
        Unoin(a, b);
      }
      else if(ch == 'C'){
        scanf("%d", &a);
        //int fa = Find(a);
        //cout << fa << endl;
        getchar(); // 吃掉回车
        printf("%d\n", Rank[a]);
      }
      for(int i = 1; i < 10; i ++)
        cout << Rank[i] << " ";
      cout << endl;

    }
      //printf("%c %d %d\n", ch, a, b);

  }
  return 0;
}
