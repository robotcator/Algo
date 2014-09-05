#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = int(1e3) + 10;
const int MOD = int(1e9) + 7;
int dp1[MAX_N][1024], dp2[MAX_N][1024], n, a[MAX_N];

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int main() {
	int T;
	cin >> T;
	for (int it = 0; it < T; ++it) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		memset(dp1, 0, sizeof dp1);

		dp1[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 1024; ++j) {
				if (dp1[i][j] > 0) {
					addIt(dp1[i + 1][j], dp1[i][j]);
					addIt(dp1[i + 1][j ^ a[i]], dp1[i][j]);
				}
			}
		}
		memset(dp2, 0, sizeof dp2);

		dp2[n][1023] = 1;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 1024; ++j) {
				if (dp2[i + 1][j] > 0) {
					addIt(dp2[i][j], dp2[i + 1][j]);
					addIt(dp2[i][j & a[i]], dp2[i + 1][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 1024; ++j) {
				int w1 = dp1[i + 1][j];
				addIt(w1, MOD - dp1[i][j]);
				int w2 = dp2[i + 1][j];
				if (j == 1023) { //delete the case T is empty
					addIt(w2, MOD - 1);
				}
				addIt(ans, 1LL * w1 * w2 % MOD);
			}
		}
		cout << ans << endl;
	}
}
