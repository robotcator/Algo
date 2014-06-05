/*
// Time Limit Exceeded
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

char data[20000000];

int main()
{
  int n, nc;
  set<string> a;
  while(scanf("%d%d", &n, &nc) != EOF){
    scanf("%s", data);
    a.clear();
    if(strlen(data)-n < 0) printf("0\n");
    else {
      string temp;
      for(int i = 0; i <= strlen(data)-n; i ++){
        for(int j = i; j < i+n; j ++)
          temp += data[j];
      a.insert(temp);
      }
      printf("%d\n", a.size());
    }
  }
  return 0;
}
*/

// ��ι����ϣ��������������ͻ
// Time Limit Exceeded
// Accepted 30388K 79MS
// �����룬Ϊ�˽�Լʱ��һ����len = strlen(data);
// �����ж����ظ�����
// �������ٴ����е��ظ�����Ϳռ����ȴ���
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
using namespace std;

char data[1000000];
int Hash[17000000];
// ��ϣ����Ϊ������Ϊn���ַ�ת��Ϊnc���Ƶ���
int main()
{
  int n, nc;
  int asc[257];
  //while(scanf("%d%d", &n, &nc) != EOF){
    scanf("%d%d", &n, &nc);
    scanf("%s", data);
    memset(asc, 0, sizeof(asc));
    memset(Hash, 0, sizeof(asc));
    int key  = 0;
    int len = strlen(data);
    for(int i = 0; i < len; i ++){
        if(asc[data[i]] == 0) asc[data[i]] = ++key;
        if(key == nc) break;
    }
    // ��β���������ַ�,���ֵ��ַ��ֱ��λ1,2,3 ... n
    // ���Թ���nc���Ƶ���
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < len-n+1; i ++){
      sum = 0;
      for(int j = i; j < i+n; j ++){
        sum = sum*nc + asc[data[j]]-1;
        // ����n�������ļ��㣬��Ȩ���
      }
      if(Hash[sum] == 0){
        Hash[sum] = 1;
        cnt ++;
      }
    }
    printf("%d\n", cnt);

  //}
  return 0;
}
