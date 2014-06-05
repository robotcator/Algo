/*
// Accepted 524K 94MS
// check����������
#include <cstdio>
#include <cstring>

using namespace std;

int check(int *money, int n, int mid, int m) {
  int num = 1;
  int sum = 0;
  for(int i = 1; i <= n; i ++){
    if(sum+money[i] <= mid) sum += money[i];
    else{
      num ++;
      sum = money[i];
    }
  }
  if(num <= m) return 1;
  else return 0;
}

int solve(int *money, int st, int ed, int n, int m) {
  // Ū�����½�
  int mid, l = st;
  int r = ed;

  while(l <= r){
    mid = (l+r)/2;
    if(check(money, n, mid, m)) r = mid-1;
    else l = mid+1;
  }
  // ����ֻ�ж���������mid�����ж�
  return mid;
}

int main()
{
  int n, m;
  int money[100005];
  int maxn, minn;
  while(scanf("%d%d", &n, &m) != EOF){
    minn = maxn = 0;
    // �Ͻ���½�
    for(int i = 1; i <= n; i ++){
      scanf("%d", &money[i]);
      if(money[i] > minn) minn = money[i];
    // �½磬ĳ�컨�����
      maxn += money[i];
    }
    int ans = solve(money, minn, maxn, n, m);
    printf("%d\n", ans);
  }
  return 0;
}
*/
//Memory Time
//420K   391MS

#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int L;  //���ܳ�
	int n;  //����ʯͷ���������S���յ���E��
	int m;  //�Ƴ�ʯͷ��

	while(cin>>L>>n>>m)
	{
		/*Input & Initial*/

		int* dist=new int[n+2];  //��i��ʯͷ�����ʯͷ�ľ���Ϊdist[i]
		dist[0]=0;    //���S
		dist[n+1]=L;  //�յ�E

		int low=L;   //�Ͻ�(һ����Ծ����̾���)
		int high=L;   //�½�(һ����Ծ��������)
		for(int i=1;i<=n+1;i++)
		{
			if(i<=n)   //������1~n����i=n+1ʱ������Ѱ��low
				cin>>dist[i];

			if(low > dist[i]-dist[i-1])
				low=dist[i]-dist[i-1];
		}

		sort(dist,dist+(n+2));   //����ʯͷ��S�ľ�����������

		/*Binary-Search*/

		while(low<=high)
		{
			int mid=(low+high)/2;  //�����������С���ľ������У����ֲ���mid��������Ž���ƫ����ƫС
			                       //����mid���Ƴ�m��ʯͷ�����̾���

			int delrock=0;    //���õ�ǰ��midֵ���Ƴ���ʯͷ��
			int sum=0;   //���POJ 3273, ������ ����������ۼ�ֵ
			             //���ڵ�i�������ۼӺ�sum

			for(int i=1;i<=n+1;)
			{
				if( (sum+=dist[i]-dist[i-1]) <= mid)
				{
					i++;
					delrock++;
				}
				else   //���ӵ�i�������ۼӵ�i+k���������sum>mid����k��������Ϊһ��
				{
					i++;
					sum=0;  //sum��0���ӵ�i+k+1�����������ۼ�
				}
			}

			if(delrock<=m)   //�����ѵ�֮һ����ʹdelrock==mҲ��һ���ҵ������Ž�
				low=mid+1;   //�õ�ǰmidֵ�Ƴ���ʯͷ��С�ڹ涨����˵��midƫС
			else
				high=mid-1;  //��֮midƫ��
		}

		/*Output & Relax*/

		cout<<low<<endl;

		delete dist;
	}

	return 0;
}
