#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class NumbersChallenge{
  public:
  int MinNumber(vector <int> S){
    int n = S.size();
    vector<int> temp;
    temp.clear();
    for(int i = 0; i < (1<<n); i ++){
      int sum = 0;
      for(int j = 0; j < n; j ++){
        if(i & (1<<j)) sum += S[j];
      }
      temp.push_back(sum);
    }
    sort(temp.begin(), temp.end());
    vector<int>::iterator it = unique(temp.begin(), temp.end());
    temp.erase(it, temp.end());
    //for(int i = 0; i < temp.size(); i ++)
     // cout << temp[i] << endl;
    int i, j = 0;
    for(i = 0; j < temp.size(); i ++){
      if(i == temp[j]) j ++;
      else {
          return i;
      }
    }
    return i;
  }
};

int main(){
  vector<int> g;
  int n;
  while(scanf("%d", &n) != EOF){
    NumbersChallenge sovle;
    int x;
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      g.push_back(x);
    }
    int ans = sovle.MinNumber(g);
    cout << ans << endl;
  }
  return 0;
}
