#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 10 + 10;
const int MOD = int(1e9) + 7;
int n, k, L;
int cnt[MAX_N];
int comb[MAX_N][MAX_N];
int pw[MAX_N * MAX_N];

int ans;

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int calcDp(int i) {
	int dp[MAX_N][2] = { };
	int o = 0;
	dp[o][0] = 1;

	for (int j = 0; j < i; ++j) {
		for (int it = 0; it < cnt[j]; ++it) {
			int minL = i - j;
			if (minL > L)
				return 0;
			int upd[2] = { L - minL, 1 };
			for (int u = 0; u < 2; ++u) {
				for (int v = 0; v < 2; ++v) {
					addIt(dp[o + 1][u | v], 1LL * dp[o][u] * upd[v] % MOD);
				}
			}
			++o;
		}
	}

//		w *= dp[o][1];
	int one = dp[o][1];
	if (i == k + 1)
		addIt(one, dp[o][0]);

	return one;
}

int calc() {
	int w = 1; //calculate the way
	int rem = n - 2;
	for (int i = 1; i <= k + 1; ++i) {
		int need = cnt[i];
		if (i == k)
			--need;
		w = 1LL * w * comb[rem][need] % MOD;
		rem -= need;
	}

//	for (int i = 0; i <= k + 1; ++i) {
//		cout << cnt[i] << " ";
//	}
//	cout << endl;

	//calcualte the way to put it
	for (int i = 1; i <= k + 1; ++i)
		if (cnt[i] > 0) {
			int dp[MAX_N][2] = { };
			int o = 0;
			dp[o][0] = 1;

			for (int j = 0; j < i; ++j) {
				for (int it = 0; it < cnt[j]; ++it) {
					int minL = i - j;
					if (minL > L)
						return 0;
					int upd[2] = { L - minL, 1 };
					for (int u = 0; u < 2; ++u) {
						for (int v = 0; v < 2; ++v) {
							addIt(dp[o + 1][u | v],
									1LL * dp[o][u] * upd[v] % MOD);
						}
					}
					++o;
				}
			}

//		w *= dp[o][1];
			int one = dp[o][1];
			if (i == k + 1)
				addIt(one, dp[o][0]);

			int t = cnt[i];

			for (int j = 0; j < t; ++j) {
				w = 1LL * w * one % MOD;
			}
			w = 1LL * w * pw[t * (t - 1) / 2] % MOD;
		}
//	ans +=
//	addIt(ans, w);
	return w;
}

void search(int at, int rem, int w) {
	if (at == k + 2) {
		if (rem == 0) {
			addIt(ans, w);
//			cout << w << " " << calc() << endl;
		}
		return;
	}
	int one = calcDp(at);
	if (at != k) {
		for (int now = 0; now <= rem; ++now) {
			cnt[at] = now;
			search(at + 1, rem - now, 1LL * w * comb[rem][now] % MOD);
			w = 1LL * w * one % MOD * pw[now] % MOD;
			if (w == 0)
				break;
		}
	} else {
		w = 1LL * w * one % MOD;

		for (int now = 0; now <= rem; ++now) {
			cnt[at] = now + 1;
			search(at + 1, rem - now, 1LL * w * comb[rem][now] % MOD);
			w = 1LL * w * one % MOD * pw[now + 1] % MOD;
			if (w == 0)
				break;
		}
	}
}

int main() {
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] =
					(i == 0 || j == 0) ?
							1 : (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}

	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d %d",&n,&k,&L);

		pw[0] = 1;
		for (int i = 1; i <= n * n; ++i) {
			pw[i] = 1LL * pw[i - 1] * L % MOD;
		}

		memset(cnt, 0, sizeof cnt);
		ans = 0;
		cnt[0] = 1;
		search(1, n - 2, 1);

		printf("%d\n",ans);
	}
}
