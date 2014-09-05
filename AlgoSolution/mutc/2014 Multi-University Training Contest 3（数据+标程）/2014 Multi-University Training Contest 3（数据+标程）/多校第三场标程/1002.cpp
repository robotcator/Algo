#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;

const int maxn=500,maxm=maxn*maxn;
int next[maxm*2],num[maxm*2],r[maxm*2],a[maxn*2],row_sum[maxn],col_sum[maxn],n,m,K,tt,T,d[maxn*2],st[maxn*2],cod[maxn][maxn];
int h[maxn*2],vh[maxn*2];
bool don[maxm*2],in[maxn*2];


void insert(int x,int y,int rr)
{
	next[++tt]=a[x];num[tt]=y;r[tt]=rr;a[x]=tt;
	next[++tt]=a[y];num[tt]=x;r[tt]=0;a[y]=tt;
}

void construct()
{
	tt=1;T=n+m+1;
	for (int i=0;i<=T;i++) a[i]=0;
	for (int i=1;i<=n;i++) insert(0,i,row_sum[i]);
	for (int i=1;i<=m;i++) insert(i+n,T,col_sum[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			insert(i,j+n,K);
			cod[i][j]=tt;
		}
	}
}

int dfs(int x,int y)
{
	if (x==T) return y;
	int sig=st[x],minh=T+1;
	do
	{
		if (r[st[x]])
		{
			if (h[num[st[x]]]+1==h[x])
			{
				int k=dfs(num[st[x]],min(y,r[st[x]]));
				if (k)
				{
					r[st[x]]-=k;
					r[st[x]^1]+=k;
					return k;
				}
			}
			minh=min(minh,h[num[st[x]]]+1);
			if (h[0]>T) return 0;
		}
		st[x]=next[st[x]];
		if (st[x]==0) st[x]=a[x];
	}while (sig!=st[x]);
	if (vh[h[x]]--==0) h[0]=T+1;
	vh[h[x]=minh]++;
	return 0;
}

int max_flow()
{
	for (int i=0;i<=T;i++) h[i]=vh[i]=0;
	for (int i=0;i<=T;i++) st[i]=a[i];
	vh[0]=T+1;
	int ret=0;
	while (h[0]<=T) ret+=dfs(0,K+1);
	return ret;
}

/*bool find_circle()
{
	deque <int> q;
	for (int i=0;i<=T;i++) d[i]=0;
	for (int i=0;i<=T;i++)
	{
		for (int p=a[i];p;p=next[p])
		{
			if (r[p]) d[i]++;
		}
		if (d[i]==0) q.push_back(i);
	}
	int cnt=T+1;
	while (!q.empty())
	{
		int x=q.front();
		cnt--;
		q.pop_front();
		for (int p=a[x];p;p=next[p])
		{
			if (r[p^1]) 
			{
				d[num[p]]--;
				if (d[num[p]]==0) q.push_back(num[p]);
			}
		}
	}
	return cnt;
}*/

bool visit(int x,int ed)
{
	if (don[ed]) 
		return in[x];
	don[ed]=true;
	in[x]=true;
	for (int p=a[x];p;p=next[p])
	{
		if (r[p] && (ed^p)!=1)
			if (visit(num[p],p)) return true;
	}
	in[x]=false;
	return false;
}

bool find_circle()
{
	for (int i=0;i<=T;i++) in[i]=false;
	for (int i=1;i<=tt;i++) don[i]=false;
	int col=0;
	for (int i=2;i<=tt;i++)
	{
		if (r[i] && !don[i])
		{
			in[num[i^1]]=true;
			if (visit(num[i],i)) return true; 
			in[num[i^1]]=false;
		}
	}
	return false;
}

void print_scheme()
{
	printf("Unique\n");
	for (int i=1;i<=n;i++)
	{
		printf("%d",r[cod[i][1]]);
		for (int j=2;j<=m;j++) printf(" %d",r[cod[i][j]]);
		printf("\n");
	}
}

int main()
{
	while (scanf("%d%d%d",&n,&m,&K)!=EOF)
	{
		int tmp=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&row_sum[i]);
			tmp+=row_sum[i];
		}
		int sum=tmp;
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&col_sum[i]);
			tmp-=col_sum[i];
		}
		if (tmp) 
		{
			printf("Impossible\n");
			continue;
		}
		construct();
		if (max_flow()<sum)
		{
			printf("Impossible\n");
			continue;
		}
		if (find_circle())
		{
			printf("Not Unique\n");
		}else print_scheme();
	}
	

	return 0;
}