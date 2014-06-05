#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100000+10;
char data[maxn];

int main()
{
  while(scanf("%s", data) != EOF){
   int len = strlen(data);
    int flag = 1;
    for(int i = 0; i < len; i ++){
      if(data[i] == 'B' || data[i] == 'C' || data[i] == 'D'
         || data[i] == 'E' || data[i] == 'F' || data[i] == 'G'
         || data[i] == 'J' || data[i] == 'K' || data[i] == 'L'
         || data[i] == 'N' || data[i] == 'P' || data[i] == 'Q'
         || data[i] == 'R' || data[i] == 'S' || data[i] == 'Z'){
          flag = 0; break;
      }
    }
    if(flag == 0) printf("NO\n");
    else {
        for(int i = 0; i < len; i ++){
          if(data[i] != data[len-1-i]) {
              flag = 0;
              break;
          }
        }
       if(flag == 1) printf("YES\n");
       else printf("NO\n");
    }
  }
  return 0;
}
