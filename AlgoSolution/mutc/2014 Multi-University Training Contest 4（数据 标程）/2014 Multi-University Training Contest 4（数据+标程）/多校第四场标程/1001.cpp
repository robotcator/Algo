#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
int n;

vector<int> E[MAX_N];
int que[MAX_N], qh, qt, fa[MAX_N], size[MAX_N];
int pathIdx[MAX_N], pathFirst[MAX_N], dep[MAX_N];

struct Tree {
	int l, r;
	bool rev;
	int sum;

	Tree*pl, *pr;

	void applyRev() {
		rev ^= 1;
		sum = r - l - sum;
	}

	void relax() {
		if (rev) {
			pl->applyRev(), pr->applyRev();
			rev = false;
		}
	}

	void update() {
		sum = pl->sum + pr->sum;
	}

	Tree(int l, int r) :
			l(l), r(r), rev(false) {
		sum = 0;
		if (l + 1 == r) {
			pl = pr = 0;
			return;
		}
		pl = new Tree(l, l + r >> 1), pr = new Tree(l + r >> 1, r);
	}

	int querySum(int L, int R) {
		if (L >= R)
			return 0;
		if (L <= l && R >= r)
			return sum;
		if (L >= r || l >= R)
			return 0;
		relax();
		return pl->querySum(L, R) + pr->querySum(L, R);
	}

	void reverse(int L, int R) {
		if (L >= R)
			return;
		if (L <= l && R >= r) {
			applyRev();
			return;
		}
		if (L >= r || l >= R)
			return;
		relax();
		pl->reverse(L, R), pr->reverse(L, R);
		update();
	}
};

Tree*sumTree[MAX_N], *markTree[MAX_N];

void build(int vs) { //build path-composition
	qh = qt = 0;
	que[qt++] = vs, fa[vs] = -1, dep[vs] = 0;
	while (qh < qt) {
		int u = que[qh++];
		vector<int>::iterator v;  
		for(v=E[u].begin();v!=E[u].end();v++) 
			if (*v != fa[u]) {
				fa[*v] = u, que[qt++] = *v, dep[*v] = dep[u] + 1;
			}
	}
	for (int i = n - 1; i >= 0; --i) {
		int u = que[i];
		size[u] = 1;
		vector<int>::iterator v;  
		for(v=E[u].begin();v!=E[u].end();v++)
			if (fa[*v] == u)
				size[u] += size[*v];
	}

	memset(pathFirst, -1, sizeof pathFirst);
	for (int i = 0; i < n; ++i) {
		int u = que[i];
		if (pathFirst[u] != -1)
			continue;
		int top = u, cnt = 0;
		for (;;) {
			pathFirst[u] = top;
			pathIdx[u] = cnt++;

			int nxt = -1;
			vector<int>::iterator v;  
		    for(v=E[u].begin();v!=E[u].end();v++)
				if (fa[*v] == u)
					if (nxt == -1 || size[*v] > size[nxt]) {
						nxt = *v;
					}
			if (nxt == -1)
				break;
			u = nxt;
		}
		sumTree[top] = new Tree(0, cnt);
		markTree[top] = new Tree(0, cnt);
	}
}

int col[MAX_N]; //for light edge u and u's father

int getLightEdge(int u) {
	//u and fa[u] is a light edge, get its weight
	int v = fa[u];
	return col[u] ^ markTree[pathFirst[v]]->querySum(pathIdx[v], pathIdx[v] + 1);
}

int query(int x, int y) {
	int ret = 0;
	for (;;) {
		if (pathFirst[x] == pathFirst[y]) {
			int l = pathIdx[x], r = pathIdx[y];
			if (l > r)
				swap(l, r);
			ret += sumTree[pathFirst[x]]->querySum(l + 1, r + 1);
			break;
		}
		if (dep[pathFirst[x]] < dep[pathFirst[y]])
			swap(x, y);
		//x goest first
		ret += sumTree[pathFirst[x]]->querySum(1, pathIdx[x] + 1);
		x = pathFirst[x];
		ret += getLightEdge(x);
		x = fa[x];
	}
	return ret;
}

void reversePath(int x, int y) {
	for (;;) {
		if (pathFirst[x] == pathFirst[y]) {
			int l = pathIdx[x], r = pathIdx[y];
			if (l > r)
				swap(l, r);
			sumTree[pathFirst[x]]->reverse(l + 1, r + 1);
			break;
		}
		if (dep[pathFirst[x]] < dep[pathFirst[y]])
			swap(x, y);
		//x goest first
		sumTree[pathFirst[x]]->reverse(1, pathIdx[x] + 1);
		x = pathFirst[x];
		col[x] ^= 1;
		x = fa[x];
	}
}

void reverseAdj(int x, int y) {
	for (;;) {
		if (pathFirst[x] == pathFirst[y]) {
			int l = pathIdx[x], r = pathIdx[y];
			if (l > r)
				swap(l, r), swap(x, y);
			markTree[pathFirst[x]]->reverse(l, r + 1);
			if (pathFirst[x] == x)
				col[x] ^= 1;
			else
				sumTree[pathFirst[x]]->reverse(l, l + 1);

			sumTree[pathFirst[y]]->reverse(r + 1, r + 2);
			break;
		}
		if (dep[pathFirst[x]] < dep[pathFirst[y]])
			swap(x, y);
		//x goest first
		markTree[pathFirst[x]]->reverse(0, pathIdx[x] + 1);
		sumTree[pathFirst[x]]->reverse(pathIdx[x] + 1, pathIdx[x] + 2);
		x = pathFirst[x];
		col[x] ^= 1;
		x = fa[x];
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			E[i].clear();
		}
		memset(col, 0, sizeof col);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d %d",&a,&b);
			--a, --b;
			E[a].push_back(b), E[b].push_back(a);
		}

		build(0);

		int Q;
		scanf("%d",&Q);
		while (Q--) {
			int t, a, b;
			scanf("%d%d%d", &t, &a, &b), --a, --b;
			if (t == 1) {
				reversePath(a, b);
			} else if (t == 2) {
				reverseAdj(a, b);
			} else {
				printf("%d\n", query(a, b));
			}
		}
	}
}
