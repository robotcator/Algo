#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = 4000 + 10;
char S[MAX_N];
int n, k;
int lcp[MAX_N][MAX_N];

struct Sub {
	int l, r; //[l,r)

	Sub(int l, int r) :
			l(l), r(r) {
	}

	int size() {
		return r - l;
	}
	char charAt(int x) {
		if (x < size())
			return S[l + x];
		else
			return 0;
	}
};

int Lcp(Sub a, Sub b) {
	return min(lcp[a.l][b.l], min((int) a.size(), (int) b.size()));
}

bool operator<(Sub a, Sub b) {
	int L = Lcp(a, b);
	return a.charAt(L) < b.charAt(L);
}

int step[MAX_N];

bool check(Sub M) {
	vector<int> nxt(n);
	for (int i = 0; i < n; ++i) {
		int L = Lcp(Sub(i, i + n), M);
		if (S[(i + L) % n] < M.charAt(L))
			nxt[i] = n;
		else
			nxt[i] = L;
	}

//	for (int i = 0; i < n; ++i) {
//		cout << nxt[i] << " ";
//	}
//	cout << endl;
	//clean
	for (;;) {
		bool done = true;
		for (int i = 0; i < nxt.size(); ++i) {
			if (nxt[i] == 0) {
				for (int j = 0; j < nxt.size(); ++j)
					if (j != i) {
						if (j < i && j + nxt[j] >= i)
							--nxt[j];
						else if (j > i && j + nxt[j] >= i + nxt.size())
							--nxt[j];
					}
				nxt.erase(nxt.begin() + i);
				done = false;
				break;
			}
		}
		if (done)
			break;
	}

//	for (int i = 0; i < nxt.size(); ++i) {
//		cout << nxt[i] << " ";
//	}
//	cout << endl;

	if (k > nxt.size())
		return false;

	for (int i = 0; i < nxt.size() * 2; ++i) {
		step[i] = i + nxt[i % nxt.size()];
	}

	for (int i = 0; i < nxt.size(); ++i) {
		int need = 0, at = i;
		while (at < i + nxt.size()) {
			at = step[at];
			++need;
		}
		if (need <= k)
			return true;
	}

	return false;
}

int main() {
	int T;
	scanf("%d",&T); 
	while (T--) {
		scanf("%d %d",&n,&k); 

		memset(S, 0, sizeof S);

		scanf("%s", S);

		for (int i = n; i < n + n; ++i) {
			S[i] = S[i - n];
		}

		for (int i = n + n - 1; i >= 0; --i) {
			for (int j = n + n - 1; j >= 0; --j) {
				if (S[i] == S[j])
					lcp[i][j] = lcp[i + 1][j + 1] + 1;
				else
					lcp[i][j] = 0;
			}
		}

		vector<Sub> subs;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < i + (i == 0 ? n : n - 1); ++j) {
				subs.push_back(Sub(i, j + 1));
			}
		}
		sort(subs.begin(), subs.end());

		int l = -1, r = subs.size() - 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(subs[m]))
				r = m;
			else
				l = m;
		}

		Sub ans = subs[r];
		for (int i = 0; i < ans.size(); ++i) {
			printf("%c", ans.charAt(i));
		}
		puts("");
//		check(ans);
	}
	return 0;
}
