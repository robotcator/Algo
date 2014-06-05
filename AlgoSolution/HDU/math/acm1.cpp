#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string encode = "hjxhdwhvvxxpdemmoijzryfczhgpbzrxdvgqijridstlmczspmvfvuuvbuwuspmwzh";

long long f(int n){
  long long f1 , f2;
  f1 = f2 = 1;
  for(int i = 2; i < n; i ++){
    f1 = f1+f2;
    f2 = f1-f2;
  }
  return f1;
}

int main(){
  /*
  string decode;
  for(int i = 0; i < encode.size(); i ++){
    int x = ( (encode[i]-'a')%26 -f(i+1)%26 +26 )%26;
    decode += x+'a';
  }
  cout << decode << endl;
 */
 // 体会题意，整数和数的说法
  char data[1000];
  while(scanf("%s", data) != EOF){
      long long ans = 0;
      for(int i = 0; i < strlen(data); i ++){
        if(data[i] >= '0' && data[i] <= '9')
          ans += data[i] - '0';
      }
      cout << ans << endl;
  }
  return 0;
}
