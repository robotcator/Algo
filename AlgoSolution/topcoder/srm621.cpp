#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class TwoWaysSorting{
  public :
  string sortingMethod(vector <string> stringList){
    int flag1, flag2 ;
    flag1 = flag2 = 1;
    for(int i = 1; i < stringList.size(); i ++){
      if(stringList[i].length() < stringList[i-1].length()) flag1 = 0;
    }
    for(int i = 1; i < stringList.size(); i ++){
      if(stringList[i] < stringList[i-1]) flag2 = 0;
    }
    if(flag1 == 1 && flag2 == 0) return "lengths";
    else if(flag1 == 0 && flag2 == 1) return "lexicographically";
    else if(flag1 == 1 && flag2 == 1) return "both";
    else return "none";
  }
};

int main(){

  return 0;
}
