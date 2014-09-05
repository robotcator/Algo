#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 3000 + 10;
typedef long long int64;
int gcd[MAX_N][MAX_N], opt[MAX_N][MAX_N];
int a[MAX_N], n;
int64 dp[MAX_N][MAX_N];

int main() {
	int T;
	scanf("%d",&T); 
	while (T--) {
			scanf("%d",&n); 
		for (int i = 0; i < n; ++i) {
			scanf("%d",&a[i]); 
		}
		for (int i = 0; i < n; ++i) {
			gcd[i][i] = a[i];
			for (int j = i + 1; j < n; ++j) {
				gcd[i][j] = __gcd(gcd[i][j - 1], a[j]);
			}
		}
//		memset(opt, 0, sizeof opt);
//		memset(dp, 0, sizeof dp);

		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = a[i];
			opt[i][i] = i;

			for (int j = i + 1; j < n; ++j) {
				int64 t = -1;
				int o;
				for (int k = opt[i][j - 1]; k <= opt[i + 1][j] && k < j; ++k) {
					int64 p = dp[i][k] + dp[k + 1][j];
					if (p > t) {
						t = p;
						o = k;
					}
				}
				opt[i][j] = o;
				dp[i][j] = t + gcd[i][j];
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	return 0;
}
