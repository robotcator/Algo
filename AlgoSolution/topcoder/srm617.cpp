/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int x){
  if(x == 2) return true;
  for(int i = 2; i <= sqrt(x); i ++)
    if(x % i == 0) return false;
  return true;
}

class SilverbachConjecture{
  public :
  vector <int> solve(int n){
    vector<int> a;
    int x, y;
    for(int i = 2; i <= n; i ++){
      x = i;
      y = n - i;
      if(!is_prime(x) && !is_prime(y) )
        break;
    }
    a.push_back(x);
    a.push_back(y);
    return a;
  }
};

int main()
{
  SilverbachConjecture a;
  int n;
  scanf("%d", &n);
  vector<int> b = a.solve(n);
  for(int i = 0; i < b.size(); i ++)
    cout << b[i] << endl;
  return 0;
}
*/


/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SlimeXSlimonadeTycoon{
  public :
  int sell(vector <int> morning, vector <int> customers, int stale_limit){
      int n = morning.size();
      int sum = 0;
      for(int i = 0; i < n; i ++){
        int s = i-stale_limit+1 >= 0 ? i-stale_limit+1 : 0;
        //cout << s << endl;
        for(int j = s; j <= i; j ++){
          int temp =  customers[i] > morning[j] ? morning[j] : customers[i];
          customers[i] -= temp;
          morning[j] = morning[j] - temp;
          sum += temp;
        }
      }
      //cout << sum << endl;
      return sum;
  }
};

int main()
{

  int n, x, y;
  for(int l = 0; l < 10; l ++){
    scanf("%d", &n);
    vector<int> a, b;
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      a.push_back(x);
    }
    for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      b.push_back(x);
    }
    scanf("%d", &y);
    SlimeXSlimonadeTycoon s;
    int ans = s.sell(a, b, y);
    cout << ans << endl;
  }
  return 0;
}
*/




#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MyVeryLongCake{
  public:
    int cut(int n){

    }
};

int main()
{

  int n, x, y;

  return 0;
}
