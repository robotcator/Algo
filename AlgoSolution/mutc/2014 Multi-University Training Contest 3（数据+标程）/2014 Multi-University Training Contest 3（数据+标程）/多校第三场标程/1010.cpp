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
#define UPD(a,b) { a = min(a,(b)); }

int x;
void set_seed(int seed) {
	x = seed;
}

int rand() {
	return x = x * 907 % 2333333;
}

void addEdge(int b, int e, int w) {
	//add an edge to your graph connecting node b and node e with weight w.
}

void initGraph(int N, int seed) {
	set_seed(seed);
	for (int i = 1; i <= N; ++i) {
		int T = rand();
		for (int j = max(1, i - 5); j < N; ++j) {
			addEdge(j, i, T ^ rand());
		}
	}
}

map<vector<int>, int> MAP;
vector<int> v[100000];
int n,a[11],number[100000];
int tot;
int m = 5;
void dfs(int l, int num) {
	if (l > m) {
		v[++tot].clear();;
		For(i,1,m) v[tot].push_back(a[i]);
		number[tot] = num;
		MAP[v[tot]] = tot;
		return ;
	}
	For(j,1,num + 1) {
		a[l] = j;
		dfs(l + 1, max(j,num));
	}
}

int app[11];

int go(vector<int> s, int nex) {
	vector<int> t;
	For(i,1,m + 1) app[i] = 0; int cnt = 0;
	For(i,1,m - 1) {
		int c = s[i], r;
		if (app[c]) r = app[c];
		else app[c] = r = ++cnt;
		t.push_back(r);
	}
	if (app[nex]) t.push_back(app[nex]);
	else t.push_back(++cnt);
	if (MAP.count(t)) {
		return MAP[t];
	} else return 0;
}

int print(vector<int> t) {
	For(i,1,m) {
		printf("%d ",t[i - 1]);
	}
	puts("");
}
long long f[11][55];
long long A[55][55], peri[10][55][55], C[55][55];
int seed;
long long cost[11], vec[55], nextvec[55];
int main() {

	tot = 0;
	dfs(1,0);

	while (cin >> n >> seed) {
		set_seed(seed);

		//cout << tot << endl;

		Fill(f,INF);
		f[1][1] = 0;
		For(i,1,min(n,m) - 1) {
			int T = rand();
			For(j,1,i) cost[j] = T ^ rand();
			For(state,1,tot) {
				For(Mask,0,(1 << i) - 1) {
					long long sum = 0;
					vector<int> tmp = v[state];
					int clr[11];
					memset(clr,0,sizeof(clr));
					For(j,m - i + 1, m) {
						if (Mask >> (j - (m - i + 1)) & 1) {
							sum += cost[j - (m - i)];
							clr[tmp[j - 1]] = true;
						}
					}
					For(j,1,m) if (clr[tmp[j - 1]]) tmp[j - 1] = m + 1;
					int nextnumber = m + 1;
					bool fl = false ;
					For(j,1,m - 1) if (tmp[j] == tmp[0]) fl = true;
					if (!fl && nextnumber != tmp[0]) continue ;
					int nextState = go(tmp, nextnumber);
					UPD(f[i + 1][nextState], f[i][state] + sum);
				}
			}
		}

		if (n <= m) {
			cout << f[n][1] << endl;
			continue ;
		}

		Fill(A,INF);
		For(i,1,tot) A[i][i] = 0;
		For(TIME,1,9) {
			int T = rand();
			For(j,1,m) {
				cost[j] = T ^ rand();
			}
			Fill(peri[TIME],INF);
			For(i,1,tot) {
				For(Mask,0,(1 << m) - 1) {
					long long sum = 0;
					vector<int> tmp = v[i];
					int clr[11];
					memset(clr,0,sizeof(clr));
					For(j,1,m) {
						if (Mask >> j - 1 & 1) {
							sum += cost[j];
							clr[tmp[j - 1]] = true;
						}
					}
					For(j,1,m) if (clr[tmp[j - 1]]) tmp[j - 1] = m + 1;
					int nextnumber = m + 1;
					bool fl = false ;
					For(j,1,m - 1) if (tmp[j] == tmp[0]) fl = true;
					if (!fl && nextnumber != tmp[0]) continue ;
					int nextState = go(tmp, nextnumber);
					peri[TIME][i][nextState] = min(peri[TIME][i][nextState], sum);
				}
			}
			Fill(C,INF);
			For(i,1,tot) For(j,1,tot) For(k,1,tot) C[j][k] = min(C[j][k], A[j][i] + peri[TIME][i][k]);
			memcpy(A,C,sizeof(A));
		}
		For(i,1,tot) vec[i] = f[m][i];
		int numPeriod = (n - m) / 9;
		for (int j = numPeriod; j; j >>= 1) {
			if (j & 1) {
				Fill(nextvec,INF);
				For(i,1,tot) For(j,1,tot) nextvec[j] = min(nextvec[j], vec[i] + A[i][j]);
				memcpy(vec, nextvec, sizeof(nextvec));
			}
			Fill(C,INF);
			For(i,1,tot) For(j,1,tot) For(k,1,tot) C[j][k] = min(C[j][k], A[j][i] + A[i][k]);
			memcpy(A,C,sizeof(A));
		}
		For(TIME,1,(n - m) % 9) {
			Fill(nextvec,INF);
			For(i,1,tot) For(j,1,tot) nextvec[j] = min(nextvec[j], vec[i] + peri[TIME][i][j]);
			memcpy(vec, nextvec, sizeof(nextvec));
		}
		cout << vec[1] << endl;
	}
	return 0;
}

