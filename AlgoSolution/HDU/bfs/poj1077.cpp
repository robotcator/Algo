#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char gaze[4][4];

int main()
{
  char data[30];
  int sx, sy;
  while(gets(data)){
    int k = 0, j = 0;
    for(int i = 0; i < strlen(data); i ++){
      if((data[i] >= '0' && data[i] <= '9') || data[i] == 'x'){
          if(j > 2) {
            k ++; j %= 3;
          }
          //cout << k << " " << j << endl;
          if(data[i] == 'x') {sx = k, sy = j;}
          gaze[k][j++] = data[i];
      }
    }
    bfs(sx, sy);

  }
  return 0;
}
