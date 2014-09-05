#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007
#define UPD(a,b) { a = max(a,b); }

int v[MaxN], next[MaxN], h[233], tot;
void add(int b, int e) {
	v[++tot] = e; next[tot] = h[b]; h[b] = tot;
	v[++tot] = b; next[tot] = h[e]; h[e] = tot;
}

int n,m,A[233][233];
int isOther[233];
PII Range[233];
int f[233][233][233];
int F[233][233], tmp[233][233][233], Max[233][233];
bool vis[233];
int size[233], q[233], fa[233], s[233];

int main() {
	//freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
	while (cin >> n >> m) {
		Fill(h,tot = 0); For(i,1,n) For(j,1,n) A[i][j] = INF;
		For(i,1,n) A[i][i] = 0;
		For(i,1,n - 1) {
			int b,e,wei;
			scanf("%d%d%d",&b,&e,&wei);
			add(b,e);
			A[b][e] = A[e][b] = wei;
		}
		
		For(i,1,n) scanf("%d",&isOther[i]);
		For(k,1,n) For(i,1,n) For(j,1,n) A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
		
		For(i,1,n) {
			PII Min = MP(INF, 0);
			For(j,1,n) if (isOther[j]) Min = min(Min, MP(A[i][j], j));
			Range[i] = Min;
		}
		
		int hd = 0, tl = 1; Fill(vis,0);
		vis[q[1] = 1] = true;
		//Fill(f,-INF);
		For(i,0,n) For(j,0,m) For(k,0,n) f[i][j][k] = -INF;
		while (hd < tl) {
			int vex = q[++hd];
			for (int z = h[vex]; z; z = next[z]) if (!vis[v[z]]) {
				vis[q[++tl] = v[z]] = true;
				fa[v[z]] = vex;
			}
		}
		
		Cor(I,tl,1) {
			int vex = q[I];
			int Tot = 0;
			size[vex] = 1;
			for (int z = h[vex]; z; z = next[z]) if (v[z] != fa[vex]) {
				++Tot;
				s[Tot] = size[v[z]];
				For(j,0,m) {
					Max[Tot][j] = -INF;
					For(k,1,n) Max[Tot][j] = max(Max[Tot][j], tmp[Tot][j][k] = f[v[z]][j][k]);
				}
				size[vex] += size[v[z]];
			}
			For(belong,1,n) if (MP(A[vex][belong],belong) <= Range[vex]) {
				if (isOther[belong]) {
					// not to occupy this node
					For(i,0,Tot) For(j,0,m) F[i][j] = -INF;
					F[0][0] = 0;
					int curS = 0;
					For(i,0,Tot - 1) {
						For(j,0,curS) {
							For(k,0,s[i + 1]) if (j + k <= m) UPD(F[i + 1][j + k], F[i][j] + Max[i + 1][k]);
						}
						curS += s[i + 1];
					}
					For(j,0,m) f[vex][j][belong] = F[Tot][j];
					continue ;
				}
				For(i,0,Tot) For(j,0,m) F[i][j] = -INF;
				int curS = 1;
				F[0][1] = 0;
				For(i,0,Tot - 1) {
					For(j,0,curS) {
						For(k,0,s[i + 1]) if (j + k <= m) {
							UPD(F[i + 1][j + k], F[i][j] + max(Max[i + 1][k], tmp[i + 1][k + 1][belong]));
						}
					}
					curS += s[i + 1];
				}
				For(j,0,m) f[vex][j][belong] = F[Tot][j] + 1;
			}
		}
		
		int ans = -INF;
		For(i,0,m) For(j,1,n) UPD(ans, f[1][i][j]);
		
		cout << ans << endl;
		
	}
	return 0;
}

