#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, k, L;

const int MAX_K = 20, MOD = int(1e9) + 7;

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int dp[1 << MAX_K];

int main() {
	int T;
	scanf("%d",&T); 
	while (T--) {
		scanf("%d %d %d",&n,&k,&L);
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		int extra = 0;
		if (L > k) {
			extra = L - k;
			L = k;
		} else {
		}
		int mask = (1 << k) - 1;
		for (int i = 0; i < n; ++i) {
			for (int j = (1 << k) - 1; j >= 0; --j) {
				int c = dp[j];
				if (c == 0)
					continue;
				for (int o = 1; o <= L; ++o) {
					int nj = j | ((j << o) & mask) | (1 << (o - 1));
//				dp[nj] += c;
					addIt(dp[nj], c);
				}
				addIt(dp[j], 1LL * c * extra % MOD);
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << k); ++i) {
			if (i >> (k - 1) & 1)
				addIt(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
