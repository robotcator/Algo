/*
    ID: problem6
    PROG : Equivalent Sets
    LANG : C++
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 20000+10;
vector<int> G[maxn];
int n, m;

int pre[maxn], lowlink[maxn], sccno[maxn];
int dfs_clock, scc_cnt;
stack<int> s;

void dfs(int u){
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u);
    for(int i = 0; i < G[u].size(); i ++){
        int v = G[u][i];
        if(!pre[v]){
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }else if(!sccno[v]){
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }

    if(lowlink[u] == pre[u]){
        scc_cnt ++;
        /*
        while(!s.empty() && pre[s.top()] >= pre[u]){
           sccno[s.top()] = sccnum;
           s.pop();
        }
        */
        for(; ;){
            int x = s.top(); s.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

void find_scc(){
    dfs_clock = scc_cnt = 0;
    memset(pre, 0, sizeof(pre));
    memset(sccno, 0, sizeof(sccno));
    memset(lowlink, 0, sizeof(lowlink));
    for(int i = 0; i < n; i ++){
        if(!pre[i]) dfs(i);
    }
}

void solve(){
    int in[maxn], out[maxn];
    //cout << scc_cnt << endl;
    for(int i = 0; i <= scc_cnt; i ++)
        in[i] = out[i] = 1;
    //for(int i = 0; i <= scc_cnt; i ++)
    //    printf("%d\n", sccno[i]);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < G[i].size(); j ++){
            int v = G[i][j];
            if(sccno[i] != sccno[v])
                in[sccno[v]] = out[sccno[i]] = 0;
        }
    }
    int a, b;
    a = b = 0;
    for(int i = 1; i <= scc_cnt; i ++){
        if(in[i]) a ++;
        if(out[i]) b ++;
    }
    //cout << a << b << endl;
    int ans = max(a, b);
    if(scc_cnt == 1) ans = 0;
    printf("%d\n", ans);
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        int x, y;
        for(int i = 0; i < maxn; i ++) G[i].clear();
        while(!s.empty()) s.pop();
        for(int i = 0; i < m; i ++){
            scanf("%d%d", &x, &y);
            G[x-1].push_back(y-1);
        }
        find_scc();
        solve();
    }
    return 0;
}
/*
conclusion:
11137719	2014-07-22 17:30:25	Accepted
3836	218MS	2164K	2348 B	C++	robotcator

*/
