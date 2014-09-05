/*
    ID: problem6
    PROG : ride
    LANG : C++
    Quote : 夫学须静也 才须学也 非学无以广才 非志无以成学
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int maxn = 100000+10;

vector<pair<int , int> > boy;

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int x, maxn = 0;
    boy.clear();
    for(int i = 1; i <= n; i ++){
      scanf("%d", &x);
      if(x > maxn) maxn = x;
      boy.push_back(make_pair(x, i));
    }
    sort(boy.begin(), boy.end());
    vector<pair<int, int> > X;
    vector<pair<int, int> > Y;
    int Xsum, Ysum;
    Xsum = Ysum = 0;
    for(int i = n-1; i >= 0; i --){
      if(i % 2 == 0){
        X.push_back(boy[i]);
        Xsum += boy[i].first;
      }else{
        Y.push_back(boy[i]);
        Ysum += boy[i].first;
      }
    }
    //cout << X[0].first << endl;
   // cout << Xsum << " " << Ysum << endl;
   // cout << maxn << endl;
    while((Xsum - Ysum) > maxn && (abs((int)(X.size() - Y.size()) <= 1))){
      int temps = X[0].first;
      int tempi = X[0].second;
      Xsum -=  temps;
      Ysum += temps;
      X.erase(X.begin());
      Y.push_back(make_pair(temps, tempi));
    }
    if(Xsum - Ysum > maxn) {
        printf("%d\n",-1);
        continue;
    }
    cout << X.size() << endl;
    for(int i = 0; i < X.size(); i ++){
      cout << X[i].second << " ";
    }
    cout << endl;
    cout << Y.size() << endl;
    for(int i = 0; i < Y.size(); i ++){
      cout << Y[i].second << " ";
    }
    cout << endl;

  }
  return 0;
}
