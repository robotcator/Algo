#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

const int MAX_N = int(1e5) + 10;
int a[MAX_N], n;

struct Tree {
	Tree*pl, *pr;
	int l, r;

	pair<int, int> mx; //value,position

	bool same;
	int samev;

	void update() {
		mx = max(pl->mx, pr->mx);
	}

	void apply(int v) {
		same = true;
		samev = v;
		mx = make_pair(v, l);
	}

	void relax() {
		if (same) {
			pl->apply(samev);
			pr->apply(samev);
			same = false;
		}
	}

	Tree(int l, int r) :
			l(l), r(r) {
		same = false;
		if (l + 1 == r) {
			mx = make_pair(a[l], l);
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	void change(int L, int R, int x) {
		if (L <= l && R >= r) {
			apply(x);
			return;
		}
		if (L >= r || l >= R)
			return;
		relax();
		pl->change(L, R, x);
		pr->change(L, R, x);
		update();
	}

	pair<int, int> query(int L, int R) {
		if (L <= l && R >= r) {
			return mx;
		}
		if (L >= r || l >= R)
			return make_pair(-1, 0);
		relax();
		return max(pl->query(L, R), pr->query(L, R));
	}

	void print(int a[]) {
		if (l + 1 == r) {
			a[l] = mx.first;
			return;
		}
		relax();
		pl->print(a), pr->print(a);
	}
}*rt;

struct Cover {
	map<int, int> mp;

	void init(int l, int r, int init) { //[l,r)
		mp[l] = mp[r] = init;
	}

	int get_value(int x) {
		map<int, int>::iterator it = --mp.upper_bound(x);
		int v = it->second;
		int l = it->first;
		int r = (++it)->first;
//		return make_tuple(v, l, r);
		return v;
	}

	pair<int, int> get_range(int x) {
		map<int, int>::iterator it = --mp.upper_bound(x);
		int v = it->second;
		int l = it->first;
		int r = (++it)->first;
//		return make_tuple(v, l, r);
//		return v;
		return make_pair(l, r);
	}

	void cover(int l, int r, int w) {
		//[l,r)
//		int old = ::get<0>(get(r));
		int old = get_value(r);
		mp.erase(mp.lower_bound(l), mp.upper_bound(r));
		mp[l] = w;
		mp[r] = old;
	}
};

int main() {
	int T;
	freopen("1006.in", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> n;
		Cover cv;
		cv.init(0, n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			cv.cover(i, i + 1, a[i]);
		}
		rt = new Tree(0, n);

		int Q;
		cin >> Q;
		while (Q--) {
			int t, l, r, x;
			cin >> t >> l >> r >> x;
			--l;
			if (t == 1) {
				rt->change(l, r, x);
				cv.cover(l, r, x);
			} else {
				for (;;) {
					pair<int, int> mx = rt->query(l, r);
					if (mx.first <= x)
						break;
					pair<int, int> t = cv.get_range(mx.second);
					int L = t.first, R = t.second; //[l,r)
					L = max(L, l);
					R = min(R, r);
					int v = __gcd(mx.first, x);
					rt->change(L, R, v);
					cv.cover(L, R, v);
				}
			}
		}
		rt->print(a);
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
