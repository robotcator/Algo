// Accepted 164K 16MS
// �û�T^2������û�����Ϊn && gcd(n, 2) == 1
// ��T^2������ȻΪn
// ���û�����n ����2 | n,��T^2����Ϊ 2������Ϊ
// n/2��ѭ���Ĳ�
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
  int t;
  int vis[30];
  int cnt[30];
  //  ͳ��ѭ������Ϊi��ѭ������
  char B[30];
  scanf("%d", &t);
  while(t--){
    scanf("%s", B);
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < 26; i ++){
      if(vis[i] == 0){
        vis[i] = 1;
        int temp = B[i] - 'A';
        int num = 1;
        while(temp >= 0 && temp != i){
          vis[temp] = 1;
          temp = B[temp] - 'A';
          num ++;
        }
        cnt[num] ++;
      }
    }
    int ok = 1;
    for(int i = 2; i <= 26; i += 2)
      if(cnt[i] % 2 == 1) ok = 0;
    if(ok == 1) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
