#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef long long ll;

#ifdef _WIN32 // FUCK OLD MSVC & LATEST MINGW
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

ll Fib[92];
ll Sum[444444];
ll FibSum[444444];
bool fibnization[444444];

ll nearest_fibonacci(ll x)
{
	int where = lower_bound(Fib,Fib+92,x)-Fib;
	if(where && abs(Fib[where-1]-x) <= abs(Fib[where]-x)) return Fib[where-1];
	return Fib[where];
}

int seg_init(int tl,int tr,int t=1)
{
	if(tl == tr)
	{
		Sum[t] = 0;
		FibSum[t] = 1;
		fibnization[t]= false;
		return 0;
	}
	int mid = (tl+tr) / 2;
	seg_init(tl,mid,t*2);
	seg_init(mid+1,tr,t*2+1);
	Sum[t] = Sum[t*2] + Sum[t*2+1];
	FibSum[t] = FibSum[t*2] + FibSum[t*2+1];
	fibnization[t] = false;
	return 0;
}

int seg_pushdown(int tl,int tr,int t)
{
	if(tl == tr) return 0;
	if(fibnization[t])
	{
		Sum[t*2] = FibSum[t*2];
		Sum[t*2+1] = FibSum[t*2+1];
		fibnization[t*2] = fibnization[t*2+1] = true;
		fibnization[t] = false;
	}
	return 0;
}

int seg_modify(int x,int delta,int tl,int tr,int t=1)
{
	seg_pushdown(tl,tr,t);
	if(tl == tr && tl == x)
	{
		Sum[t] += delta;
		FibSum[t] = nearest_fibonacci(Sum[t]);
		return 0;
	}
	int mid = (tl+tr) / 2;
	if(x <= mid) seg_modify(x,delta,tl,mid,t*2);
	else seg_modify(x,delta,mid+1,tr,t*2+1);
	Sum[t] = Sum[t*2] + Sum[t*2+1];
	FibSum[t] = FibSum[t*2] + FibSum[t*2+1];
	return 0;
}

ll seg_query(int l,int r,int tl,int tr,int t=1)
{
	if(l <= tl && tr <= r) return Sum[t];
	seg_pushdown(tl,tr,t);
	int mid = (tl+tr) / 2;
	ll ans = 0;
	if(l <= mid) ans += seg_query(l,r,tl,mid,t*2);
	if(r > mid) ans += seg_query(l,r,mid+1,tr,t*2+1);
	return ans;
}

int seg_fib(int l,int r,int tl,int tr,int t=1)
{
	if(l <= tl && tr <= r)
	{
		Sum[t] = FibSum[t];
		fibnization[t] = true;
		return 0;
	}
	seg_pushdown(tl,tr,t);
	int mid = (tl+tr) / 2;
	if(l <= mid) seg_fib(l,r,tl,mid,t*2);
	if(r > mid) seg_fib(l,r,mid+1,tr,t*2+1);
	Sum[t] = Sum[t*2] + Sum[t*2+1];
	FibSum[t] = FibSum[t*2] + FibSum[t*2+1];
	return 0;
}

int main(void)
{
	Fib[0] = Fib[1] = 1;
	for(int i = 2;i < 92;i++) Fib[i] = Fib[i-1] + Fib[i-2];

	int n = 0;
	int m = 0;
	while(scanf("%d %d",&n,&m) == 2)
	{
		assert(1 <= n && n <= 100000);
		assert(0 <= m && m <= 100000);

		seg_init(1,n);
		while(m--)
		{
			int type = 0;
			assert(scanf("%d",&type) == 1);
			assert(1 <= type && type <= 3);
			if(type == 1)
			{
				int x = 0;
				int delta = 0;
				scanf("%d %d",&x,&delta);
				assert(1 <= x && x <= n);
				seg_modify(x,delta,1,n);
			}
			else if(type == 2)
			{
				int l = 0;
				int r = 0;
				scanf("%d %d",&l,&r);
				assert(1 <= l && l <= n);
				assert(1 <= r && r <= n);
				assert(l <= r);
				printf(LLD "\n", seg_query(l,r,1,n));
			}
			else
			{
				int l = 0;
				int r = 0;
				scanf("%d %d",&l,&r);
				assert(1 <= l && l <= n);
				assert(1 <= r && r <= n);
				assert(l <= r);
				seg_fib(l,r,1,n);
			}
		}
	}
	assert(scanf("%*s") == EOF);
	return 0;
}
