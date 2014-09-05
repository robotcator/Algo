#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 10;
int n, k;
int lab[MAX_N];
int dist[MAX_N][MAX_N], ans[MAX_N][MAX_N];

vector<int> E[MAX_N];

int cnt[MAX_N];

void dfs(int u, int p, int d, int w, int dst[], int am[]) {

    if (++cnt[lab[u]] == 1)
        ++w;

    dst[u] = d;
    am[u] = w;
    vector<int>::iterator x;  
    for(x=E[u].begin();x!=E[u].end();x++)
        if (*x != p)
            dfs(*x, u, d + 1, w, dst, am);

    --cnt[lab[u]];
}

typedef int T;
struct Index: public vector<T> {
    void doit() {
        sort(begin(), end());
        erase(unique(begin(), end()), end());
    }
    int get(T x) {
        return lower_bound(begin(), end(), x) - begin();
    }
};

double comb[MAX_N][MAX_N];

int main() {
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j <= i; ++j) {
            comb[i][j] =
                    (i == 0 || j == 0) ?
                            1 : (comb[i - 1][j] + comb[i - 1][j - 1]);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            E[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b, --a, --b;
            E[a].push_back(b);
            E[b].push_back(a);
        }

        Index idx;

        for (int i = 0; i < n; ++i) {
            cin >> lab[i];
            idx.push_back(lab[i]);
        }

        idx.doit();

        for (int i = 0; i < n; ++i) {
            lab[i] = idx.get(lab[i]);
        }

        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; ++i) {
            dfs(i, -1, 0, 0, dist[i], ans[i]);
        }

        if (k == 1) {
            printf("%0.10lf\n", 0.);
            continue;
        }

        double ans = 0;

        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                int cnt = 0;
                for (int c = 0; c < n; ++c)
                    if (a != c && b != c) {
                        int L = dist[a][b];
                        if (dist[a][c] > L || (dist[a][c] == L && c < b))
                            continue;
                        if (dist[b][c] > L || (dist[b][c] == L && c < a))
                            continue;
                        ++cnt;
                    }
                double pb = comb[cnt][k - 2] / comb[n][k];
                ans += pb * ::ans[a][b];
            }
        }

        printf("%0.10lf\n", ans);
    }
}
