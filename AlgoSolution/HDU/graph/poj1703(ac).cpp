// Accepted 1444K 672MS
// 去回车，因为后面读取字符，快哭了,用getchar,或者在输入那里加\n
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100000+10;
int Set[maxn];
int Rank[maxn];

void Init(int n){
  memset(Rank, 0, sizeof(Rank));
  for(int i = 0; i <= n; i++){
    Set[i] = i;
  }
}

int Find(int x){
  if(x != Set[x]){
    int fa = Set[x];
    Set[x] = Find(Set[x]);
    Rank[x] = (Rank[x]+Rank[fa])%2;
    // 1444K 672MS  自己写的偏移函数
    //Rank[x] = Rank[x]^Rank[fa];
  }
  return Set[x];
}

void Unoin(int a, int b, int fa, int fb, int d){
  Set[fb] = fa;
  // 谁的根指向谁
   Rank[fb] = (d+2-Rank[a]+Rank[b])%2;
  //  Rank[fb] = ~(Rank[a]^Rank[b]);
}


int main()
{
  int t, n, m;
  int a, b;
  char ch;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d\n", &n, &m);

    //getchar();
    Init(n);
    for(int i = 0; i < m; i ++){
        //scanf("%c %d %d\n", &ch, &a, &b);
        // 实在不行用c++
        cin >> ch >> a >> b;
        printf("%c %d %d\n", ch, a, b);
        /*
        int fa = Find(a);
        int fb = Find(b);
        //cout << fa << " " << fb << endl
        if(ch == 'A'){
            if(fa != fb){
              printf("Not sure yet.\n");
            }
            else{
             // cout << Rank[a] << Rank[b] << endl;
              if(n == 2) printf("In different gangs.\n");
              else if(Rank[a] == Rank[b])
                printf("In the same gang.\n");
              else printf("In different gangs.\n");
            }
        }
        else if(ch == 'D'){
            Unoin(a, b, fa, fb, 1);
        }
        */
    }
  }


  return 0;
}
