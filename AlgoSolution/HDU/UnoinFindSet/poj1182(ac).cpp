// 1092K 250MS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
// ����Ҫע�⵽a��b,b��c����ôcһ����a
// ��ʵ���ľ��ú�����
/*
��Ϊ���鼯�е�Ԫ�ؾ�������ϵ�ģ�����Ҳ���ᱻ�ϲ�����ǰ�����С���ô����

�Ͱ���2��Ԫ��֮��Ĺ�ϵ��ת��Ϊһ��ƫ��������ʳ�����Ĺ�ϵ���ԣ���������

a->b ƫ����0ʱ a��bͬ��

a->b ƫ����1ʱ a��b

a->b ƫ����2ʱ a��b�ԣ�Ҳ����b��a

������Щ���������ǾͿ����ڲ��鼯�������������Ԫ��֮��Ĺ�ϵת���ˡ�

�����������裬a�ĵ�ǰ���ϸ��ڵ�aa��b�ĵ�ǰ���ϸ��ڵ�bb��a->b��ƫ��ֵΪd-1�����и�����ѯ����֪������

(1)���aa��bb����ͬ����ô���ǰ�bb�ϲ���aa�ϣ����Ҹ���delta[bb]ֵ��delta[i]��ʾi�ĵ�ǰ���ϸ��ڵ㵽i��ƫ������

    ��ʱ aa->bb = aa->a + a->b + b->bb��������һ��������ν����˼άģʽ��

    ��ʽ��һ��ת��Ϊ��aa->bb = (delta[a]+d-1+3-delta[b])%3 = delta[bb]����ģ3�Ǳ�֤ƫ����ȡֵʼ����[0,2]�䣩

(2)���aa��bb��ͬ����ô���Ǿ���֤a->b֮���ƫ�����Ƿ������и�����d-1һ��

    ��ʱ a->b = a->aa + aa->b = a->aa + bb->b��

    ��ʽ��һ��ת��Ϊ��a->b = (3-delta[a]+delta[b])%3��

    ��һ����Ϊ�棬����Ϊ�١�

*/

const int maxn = 50000+10;
int Set[maxn];
// ÿ���ڵ�ĸ���˭
int Rank[maxn];
// ÿ���ڵ�������ڼ��ϵĸ��Ĺ�ϵ

void init(int n){
  memset(Rank, 0, sizeof(Rank));
  for(int i = 0; i <= n; i ++){
    Set[i] = i;
  }
}

int Find(int x){
  if(x != Set[x]){
    int fa = Set[x];
    Set[x] = Find(Set[x]);
    Rank[x] = (Rank[x]+Rank[fa])%3;
  }
  // �Լ������ڵ�ĺ�
  return Set[x];
}

void Union(int a, int b, int fa, int fb, int d){
  Set[fa] = b;
  Rank[fa] = (3-Rank[a] + d-1 + Rank[b]);
  // Ϊʲô�ǶԸ�
}
/*
        int a = findParent(ani[X]);
        int b = findParent(ani[Y]);
        ani[b].parent = a;
        ���ǰ�Y���ڼ��ϵĸ��ڵ�ĸ������ó�X���ڼ��ϵĸ��ڵ㡣
        ���ǣ����ǣ�������
        Y���ڼ��ϵĸ������X���ڼ��ϵĸ��ڵ�Ĺ�ϵ������Ҫ��ôȷ���أ�
        ������X,Y���϶���·��ѹ�����ģ��߶�ֻ��2��
        �����ȸ�������Ĺ�ʽ
        ani[b].relation = ( 3 - ani[Y].relation + ( d - 1 ) + ani[X].relation) % 3;
        �����ʽ���Ƿ������֣���ô�Ƴ�����
        ��һ���֣�������һ���֣�
        ( d - 1 ) :����X��Y֮���relation��X��Y�ĸ��ڵ�ʱ��Y��relation�������
        3 - ani[Y].relation = ����Y����ڵ�Ĺ�ϵ�����Ƹ��ڵ���Y�Ĺ�ϵ
        �ⲿ��Ҳ����ٷ��Ƴ����ģ����Ǿ�����
        j
        ��         ��������ӵ�relation�����������Ǹ��ĸ��ڵ㣬��ô����relationӦ����ʲô����Ϊ�������Ǹ��ڵ㣬���Ը�.relation = 0������ֻ�ܸ��ݸ����ӽڵ㷴���Ӹ����ڵ�Ĺ�ϵ��
         0             ( 3 - 0 ) % 3 = 0
         1�������ӣ�   ( 3 - 1 ) % 3 = 2 //������
         2���ӳԸ�)    ( 3 - 2 ) % 3 = 1 //�ӳԸ���һ����Ŷ��

*/


int main()
{
  int n, k;
  int d, a, b;
  scanf("%d%d", &n, &k);
    init(n);
    int num = 0;
    for(int i = 0; i < k; i ++){
      scanf("%d%d%d", &d, &a, &b);
      if(a > n || b > n ||(d == 2 && a == b))
        num ++;
      else{
        int fa = Find(a);
        int fb = Find(b);
        //cout << fa << fb << endl;
        if(fa != fb){
          Union(a, b, fa, fb, d);
          //cout << Rank[a] << Rank[b] << endl;
        }
        else {
           // cout << Rank[a] << " " << Rank[b]+d-1 << endl;
            if(Rank[a] != (Rank[b]+d-1)%3)
              num ++;
        }
      }
      //cout << num << endl;
    }
    cout << num << endl;
  return 0;
}
