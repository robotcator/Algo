#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

inline int scanf(int &num)
{
    char in;
    bool neg=false;
    while((in=getchar())!=EOF && (in>'9' || in<'0') && in!='-');
    if(in==EOF) return 0;
    else if(in=='-') neg=true,num=0;
    else  num=in-'0';
    while(in=getchar(),in>='0' && in<='9') num*=10,num+=in-'0';
    if(neg) num=-num;
    return 1;
    // 464 MS
}

const int maxn = 100000+10;
int data[maxn];
int cnt[maxn];

int main(){
  int n;
  while(scanf(n)){
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i ++){
      scanf(data[i]);
      cnt[data[i]] ++;
    }
    long long res = (long long)(n)*(long long)(n-1)/2;
    for(int i = 1; i <= 100000; i ++){
      if(cnt[i] == 0) continue;
      res -= (cnt[i])*(cnt[i]-1)/2;
      for(int j = i+i; j <= 100000; j += i)
        res -= (cnt[i])*(cnt[j]);
    }
    cout << res << endl;
  }
  return 0;
}
