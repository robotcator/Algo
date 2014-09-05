/*
// Accepted 524K 94MS
// check函数有问题
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
  // 弄好上下界
  int mid, l = st;
  int r = ed;

  while(l <= r){
    mid = (l+r)/2;
    if(check(money, n, mid, m)) r = mid-1;
    else l = mid+1;
  }
  // 或者只判断两个对于mid不做判断
  return mid;
}

int main()
{
  int n, m;
  int money[100005];
  int maxn, minn;
  while(scanf("%d%d", &n, &m) != EOF){
    minn = maxn = 0;
    // 上界和下界
    for(int i = 1; i <= n; i ++){
      scanf("%d", &money[i]);
      if(money[i] > minn) minn = money[i];
    // 下界，某天花费最大
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
	int L;  //河总长
	int n;  //河中石头数（除起点S和终点外E）
	int m;  //移除石头数

	while(cin>>L>>n>>m)
	{
		/*Input & Initial*/

		int* dist=new int[n+2];  //第i块石头到起点石头的距离为dist[i]
		dist[0]=0;    //起点S
		dist[n+1]=L;  //终点E

		int low=L;   //上界(一次跳跃的最短距离)
		int high=L;   //下界(一次跳跃的最大距离)
		for(int i=1;i<=n+1;i++)
		{
			if(i<=n)   //仅输入1~n，当i=n+1时仅用于寻找low
				cin>>dist[i];

			if(low > dist[i]-dist[i-1])
				low=dist[i]-dist[i-1];
		}

		sort(dist,dist+(n+2));   //根据石头到S的距离升序排列

		/*Binary-Search*/

		while(low<=high)
		{
			int mid=(low+high)/2;  //对最大跳和最小跳的距离折中，二分查找mid相对于最优解是偏大还是偏小
			                       //假设mid是移除m个石头后的最短距离

			int delrock=0;    //利用当前的mid值能移除的石头数
			int sum=0;   //类比POJ 3273, 这里是 连续距离的累加值
			             //当在第i个距离累加后sum

			for(int i=1;i<=n+1;)
			{
				if( (sum+=dist[i]-dist[i-1]) <= mid)
				{
					i++;
					delrock++;
				}
				else   //当从第i个距离累加到i+k个距离后，若sum>mid，则k个距离作为一段
				{
					i++;
					sum=0;  //sum置0，从第i+k+1个距离重新累加
				}
			}

			if(delrock<=m)   //本题难点之一：即使delrock==m也不一定找到了最优解
				low=mid+1;   //用当前mid值移除的石头数小于规定数，说明mid偏小
			else
				high=mid-1;  //反之mid偏大
		}

		/*Output & Relax*/

		cout<<low<<endl;

		delete dist;
	}

	return 0;
}
