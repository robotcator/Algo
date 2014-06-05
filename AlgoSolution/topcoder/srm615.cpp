/*
// A 250 225.70
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class AmebaDiv2{
  public:
  int simulate(vector <int> X, int A){
    for(int i = 0; i < X.size(); i ++){
        if(X[i] == A) {
          A = A*2;
        }
    }
   return A;
  }
};

int main()
{
  AmebaDiv2 a;
  for(int i = 0; i < n; i ++)
  return 0;
}
*/

/*
// B 500 299.55
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class LongLongTripDiv2{
  public:
  string isAble(long long D, int T, int B){
    double x = (D-T)*1.0/(B-1);
    double y = T - x;
    cout << x << " " << y << endl;
    if(x >= 0 && y >= 0 && (long long)x == x && (long long)y == y)
      return  "Possible";
    else return "Impossible";
  }
};

int main()
{
  int d, t, b;
  while(scanf("%d%d%d", &d, &t, &b) != EOF){
    LongLongTripDiv2 a;
    string ans = a.isAble(d, t, b);
    cout << ans << endl;
  }
  return 0;
}


*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class  MergeStrings{
  public :
  string dp[55][55];
  string getmin(string S, string A, string B){
    int slen = S.size();
    int alen = A.size();
    int blen = B.size();
    for(int i = 0; i <= alen; i ++)
      dp[i][0] = "";
    for(int j = 0; j <= blen; j ++)
      dp[0][j] = "";
    for(int i = 1; i  <= alen; i ++){
      for(int j = 1; j <= blen; j ++){
        string s1 = "";
        string s2 = "";

      }
    }
  }
};

int main()
{

  return 0;
}
