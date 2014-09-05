
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

const int N = 32;

struct matrix_t {
	unsigned x[N + 1];
	int n;
	void set(int i, int j, unsigned v) {
		x[i] |= (v << (j - 1));
	}
	matrix_t() { }
	matrix_t(int _n, int v) {
		n = _n;
		memset(x, 0, sizeof(x));
		for (int i = 1; i <= n; ++i) set(i, i, v);
	}
	void multiply(const matrix_t &r, matrix_t &p) {
		assert(n == r.n);
		static int tmp[N + 1];
		for (int i = 1; i <= n; ++i) tmp[i] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k <= n; ++k) {
				if ((x[i] >> (k - 1)) & 1) tmp[i] ^= r.x[k];
			}
		}
		p.n = n;
		for (int i = 1; i <= n; ++i) p.x[i] = tmp[i];
	}
	matrix_t power(unsigned p) {
		matrix_t r = matrix_t(n, 1), a = *this;
		for (; p; p >>= 1) {
			if (p & 1) r.multiply(a, r);
			a.multiply(a, a);
		}
		return r;
	}
	unsigned value() {
		unsigned v = 0;
		for (int i = 1; i < n; ++i) {
			v <<= 1;
			v |= (x[i] & 1);
		}
		return v;
	}
};
matrix_t mat, matInv, flip;
int n, S1, S2, a[64], b[64];
map<unsigned, int> mp;

matrix_t read() {
	matrix_t ret = matrix_t(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		int v; scanf("%d", &v);
		ret.set(i, 1, v);
	}
	ret.set(n + 1, 1, 1);
	return ret;
}

int main() {
	while (scanf("%d%d%d", &n, &S1, &S2) != EOF) {
		if (n == 0) break;
		mat = matrix_t(n + 1, 0); mat.set(n + 1, n + 1, 1);
		matInv = matrix_t(n + 1, 0); matInv.set(n + 1, n + 1, 1);
		flip = matrix_t(n + 1, 1);
		mp.clear();
		for (int i = 1; i <= S1; ++i) scanf("%d", a + i);
		for (int i = 1; i <= S2; ++i) scanf("%d", b + i);
		for (int i = 1; i <= S1; ++i) {
			mat.set(n, a[i], 1);
			if (a[i] != 1) matInv.set(1, a[i] - 1, 1);
		}
		matInv.set(1, n, 1);
		for (int i = 1; i < n; ++i) {
			mat.set(i, i + 1, 1);
			matInv.set(i + 1, i, 1);
		}
		for (int i = 1; i <= S2; ++i) {
			flip.set(b[i], n + 1, 1);
		}
		flip.multiply(mat, mat);
		matInv.multiply(flip, matInv);
		matrix_t from, to;
		from = read(); to = read();
		unsigned GO = 1 << ((n + 1) / 2);
		for (unsigned i = 0; i < GO; ++i) {
			unsigned value = to.value();
			if (mp.find(value) == mp.end()) {
				mp[value] = i;
			}
			matInv.multiply(to, to);
		}
		mat = mat.power(GO);
		unsigned ret;
		bool found = false;
		for (unsigned i = 0; i < GO; ++i) {
			unsigned value = from.value(), step = i * GO;
			if (mp.find(value) != mp.end()) {
				ret = step + mp[value];
				found = true;
				break;
			}
			mat.multiply(from, from);
		}
		if (found) printf("%u\n", ret);
		else puts("poor sisyphus");
	}
	return 0;
}

