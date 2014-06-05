#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int a[5];
  while(scanf("%d", &a[1]) != EOF){
    for(int i = 2; i < 5; i ++)
      scanf("%d", &a[i]);
    char data[100000+10];
    scanf("%s", data);
    int sum = 0;
    for(int i = 0; i < strlen(data); i ++)\
      sum += a[data[i]-'0'];
    cout << sum << endl;
  }
  return 0;
}
