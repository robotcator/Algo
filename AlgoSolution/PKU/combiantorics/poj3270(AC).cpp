//Accepted 1024K 0MS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int cmp(int a, int b) { return a < b; }
int minx(int a, int b) { return a < b ? a : b; }

int main()
{
  int n, flag ;
  int cow[10005];
  int id[100005];
  int End[10005];
  int vis[100005];
  // ���ڼ�¼�Ƿ���ͬһ���ȼ�����
  while(scanf("%d", &n) != EOF){
    int minn = inf;
    // ��¼ȫ����Сֵ
    int sum = 0;
    // ��¼����
    for(int i = 1; i <= n; i ++){
      scanf("%d", &cow[i]);
      id[cow[i]] = i;
      // ��¼ÿ��Ƣ����Ӧ��
      //Each cow has a unique "grumpiness" level
      End[i] = cow[i];
      // ĩ̬
      sum += cow[i];
      if(cow[i] < minn) minn = cow[i];
    }
    sort(End+1, End+n+1, cmp);
    // ע��Ԫ�ؿ�ʼλ�úͽ���λ�ú�һλ
    flag = 1;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
      int temp = cow[i];
      if(vis[temp] == 0){
        int num = 0;
        // ѭ����Ԫ�ظ���
        int tempmin = inf;
        if(temp < tempmin) tempmin = temp;
        num ++;
        vis[temp] = flag ;
        temp = End[id[temp]];
        while(vis[temp] == 0 && temp != cow[i]){
          //vis�жϿ��п���
          if(temp < tempmin) tempmin = temp;
          num ++;
          vis[temp] = flag;
          temp = End[id[temp]];
        }
        flag ++;
       // printf("~%d %d\n", num, tempmin);
        sum = sum + minx((num-2)*tempmin , minn*(num+1)+tempmin);
      }
    }
    printf("%d\n", sum);

  //  for(int i = 0; i < 10; i ++)
  //    printf("%d %d\n", i, vis[i]);

  }
  return 0;
}
