// 712K 282MS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
// �����Կ��Կ���ȡģ����
// ������ȡģ���Բ�ֳ�ʮ������
// ��������б�ǣ����������mle
// ��ô���ػ��ö�˼��

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
     // ��nȡ���ΪN��
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
