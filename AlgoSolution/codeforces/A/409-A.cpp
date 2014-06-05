// robotcator 	409A - The Great Game 	GNU C++0x 	Accepted 	15 ms 	0 KB
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int check(char *a, char *b){
  int cnt1, cnt2;
  cnt1 = cnt2 = 0;
  for(int i = 0; i < strlen(a); i += 2){
    if(a[i] == '[' && a[i+1] == ']'){
      if(b[i] == '8' && b[i+1] == '<') cnt2 ++;
      else if(b[i] == '(' && b[i+1] == ')') cnt1 ++;
    }
    else if(a[i] == '(' && a[i+1] == ')'){
      if(b[i] == '8' && b[i+1] == '<') cnt1 ++;
      else if(b[i] == '[' && b[i+1] == ']') cnt2 ++;
    }
    else if(a[i] == '8' && a[i+1] == '<'){
      if(b[i] == '(' && b[i+1] == ')') cnt2 ++;
      else if(b[i] == '[' && b[i+1] == ']') cnt1 ++;
    }
  }
  if(cnt1 > cnt2) return 1;
  else if(cnt1 < cnt2) return 2;
  else return 0;
}

int main(){
  char data1[25], data2[25];
  while(scanf("%s %s", data1, data2) != EOF){
    int ans = check(data1, data2);
    if(ans == 0) printf("TIE\n");
    else if(ans == 1) printf("TEAM 1 WINS\n");
    else printf("TEAM 2 WINS\n");
  }
  return 0;
}
