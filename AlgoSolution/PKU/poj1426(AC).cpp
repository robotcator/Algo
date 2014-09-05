// 712K 282MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
// 整除性可以考虑取模操作
// 大整数取模可以拆分成十进制数
// 如果不进行标记，这样会出现mle
// 怎么判重还得多思考

int n;
int vis[205];
int get_div(string a){
    int len = a.size();
    int ans = 0;
    for(int i = 0; i < len; i++){
      ans = (ans*10 + (a[i]-'0'))% n;
      //cout << ans << endl;
    }
    return ans;
}

void bfs(){
   memset(vis, 0, sizeof(vis));
   queue<string> q;
   q.push("1");
   while(!q.empty()){
      string temp = q.front();
      q.pop();
     // cout << temp << endl;
     // 对n取余分为N类
      if(get_div(temp) == 0) {
          cout << temp << endl;
          return ;
      }
      for(int i= 0; i < 2; i ++){
        if(i == 0){
          string next = temp + '0';
          int m = get_div(next);
          if(vis[m] == 0){
            q.push(next);
            vis[m] = 1;
          }
        }
        else if(i == 1){
          string next = temp + '1';
          int m = get_div(next);
          if(vis[m] == 0 ){
            q.push(next);
            vis[m] = 1;
          }
        }
      }
   }
}

int main()
{
  while(scanf("%d", &n) != EOF){
    if(n == 0) break;
    bfs();
  }
  return 0;
}
