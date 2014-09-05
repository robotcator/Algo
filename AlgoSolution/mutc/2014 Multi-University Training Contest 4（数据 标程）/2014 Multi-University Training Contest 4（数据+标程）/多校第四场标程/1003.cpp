#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int MOD = int(1e9) + 7;
string S;
int m;
const string ACGT = "ACGT";

vector<int> getNext(vector<int> cur, char c) {
	for (int i = S.size(); i >= 1; --i) {
		if (S[i - 1] == c)
			cur[i] = max(cur[i - 1] + 1, cur[i]);
	}
	for (int i = 1; i <= S.size(); ++i) {
		cur[i] = max(cur[i], cur[i - 1]);
	}
	return cur;
}

map<vector<int>, int> idmp;
vector<vector<int> > states;

void dfs(vector<int> cur) {
	if (idmp.count(cur))
		return;

	int me = idmp.size();
	idmp[cur] = me;
	states.push_back(cur);

	for (int i = 0; i < ACGT.size(); ++i) {
		dfs(getNext(cur, ACGT[i]));
	}
}

vector<vector<int> > trans;

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int calcStates(string S) {
	::S = S;
	idmp.clear(), states.clear();
	vector<int> init(S.size() + 1, 0);
	dfs(init);
	return states.size();
}

int maxState;
string who;

void dfs(string cur, int rem, int nused) {
	if (rem == 0) {
		int tmp = calcStates(cur);
//		maxState = max(maxState, calcStates(cur));
		if (tmp > maxState) {
			maxState = tmp;
			who = cur;
		}
		return;
	}
	for (int i = 0; i < 4 && i <= nused; ++i) {
		dfs(cur + ACGT[i], rem - 1, max(nused, i + 1));
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> S;
		cin >> m;

		idmp.clear(), states.clear();

		vector<int> init(S.size() + 1, 0);
		dfs(init);
		trans.assign(idmp.size(), vector<int>(4, 0));

		for (int i = 0; i < states.size(); ++i) {
			for (int j = 0; j < 4; ++j) {
				trans[i][j] = idmp[getNext(states[i], ACGT[j])];
			}
		}

		vector<int> am(states.size(), 0);
		vector<int> nam = am;

		am[idmp[init]] = 1;

		for (int i = 0; i < m; ++i) {
			fill(nam.begin(), nam.end(), 0);
			for (int a = 0; a < states.size(); ++a) {
				for (int b = 0; b < 4; ++b) {
					addIt(nam[trans[a][b]], am[a]);
				}
			}
			am = nam;
		}

		vector<int> ans(S.size() + 1, 0);
		for (int i = 0; i < states.size(); ++i) {
			addIt(ans[states[i].back()], am[i]);
		}

		for (int i = 0; i <= S.size(); ++i) {
			cout << ans[i] << endl;
		}
	}
}
