#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool judge(int C) {
	int n,m;
	
	if(scanf("%d %d",&n,&m) != 2) return false;
	if(!(1 <= n && n <= 100)) return false;
	if(!(0 <= m && m <= n*(n-1))) return false;

	vector<pair<int,int> > edges[111];
	for(int i = 0;i < m;i++) {
		int x,y,w;
		// cin >> x >> y >> w;
		if(scanf("%d %d %d", &x, &y, &w) != 3) return false;
		if(!(1 <= x && x <= n)) return false;
		if(!(1 <= y && y <= n)) return false;
		if(w == 0x80000000) return false;
		edges[x].push_back(make_pair(y,w));
	}

	vector<long long> dist(n+1, ~0ULL>>1);
	dist[1] = 0;
	// do a Bellman-Ford, check negative-cost loops
	for(int iter = 0;iter <= n+2;iter++) {
		for(int x = 1;x <= n;x++) {
			for(vector<pair<int,int> >::iterator it = edges[x].begin();it != edges[x].end();++it) {
				int y = it->first;
				int w = it->second;
				if(dist[y] > dist[x] + w) {
					dist[y] = dist[x] + w;
					if(iter == n+2) return false; // lol i won't eat your tasty nega-loop
				}
			}
		}
	}

	deque<int> q;
	fill(dist.begin(),dist.end(),~0ULL>>1);
	vector<bool> inQueue(n+1, false);
	dist[1] = 0; q.push_back(1); inQueue[1] = true;

	int doge = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop_front();
		if(doge++ > C) {
			puts("doge");
			return true;
		}
		for(vector<pair<int,int> >::iterator it = edges[x].begin();it != edges[x].end();++it) {
			int y = it->first;
			int w = it->second;
			if(dist[y] > dist[x] + w) {
				dist[y] = dist[x] + w;
				if(!inQueue[y]) {
					inQueue[y] = true;
					if(!q.empty() && dist[y] > dist[q.front()])
						q.push_back(y);
					else
						q.push_front(y);
				}
			}
		}
		inQueue[x] = false;
	}
	cout << dist[n] << endl;
	return 0;
}

int main(int argc,char* argv[])
{
	FILE* fin = fopen(argv[1],"rt");
	int c = 0;
	bool okay = true;
	while(fscanf(fin,"%d",&c) != EOF)
	{
		okay &= judge(c);
	}
	fclose(fin);
	if(scanf("%*s") != EOF) okay = false;
	if(!okay) puts("minke");
	return 0;
}
