// Accepted 1412K 125MS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

struct point{
	int x, y;
};

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
// 养成好习惯
int vis1[305][305];
int vis2[305][305];

void init()
{
	memset(vis1, -1, sizeof(vis1));
	memset(vis2, -1, sizeof(vis2));
}

bool is_in(point next, int l){
	if(next.x >= 0 && next.x < l && next.y >= 0 && next.y < l)
		return true;
	else return false;
}

void dbfs(point s, point e, int l){
	init();
	queue<point> p, q;
	p.push(s);
	vis1[s.x][s.y] = 0;

	q.push(e);
	vis2[e.x][e.y] = 0;
	while(!p.empty() && !q.empty()){
		point cur;
		point next;
		int size = p.size();
		//cout << size << "x" << endl;
		while(size --){
			cur = p.front();
			p.pop();
			if(is_in(cur, l) && vis2[cur.x][cur.y] != -1){
          // 这里下标也出错
				 printf("%d\n", vis1[cur.x][cur.y] + vis2[cur.x][cur.y]);
				 return ;
			}
			for(int i = 0; i < 8; i ++){
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				if(is_in(next, l) && vis2[next.x][next.y] != -1){
					printf("%d\n", vis1[cur.x][cur.y] + 1 + vis2[next.x][next.y]);
					return ;
				}

				if(is_in(next, l) && vis1[next.x][next.y] == -1){
         // cout << next.x << " " << next.y << endl;
					vis1[next.x][next.y] = vis1[cur.x][cur.y]+1;
					p.push(next);
				}
			}
		}
		size = q.size();
		//cout << size << "x" << endl;
		while(size --){
			cur = q.front();
			q.pop();
			if(is_in(cur, l) && vis1[cur.x][cur.y] != -1){
				 printf("%d\n", vis1[cur.x][cur.y] + vis2[cur.x][cur.y]);
				 return ;
			}
			for(int i = 0; i < 8; i ++){
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				if(is_in(next, l) && vis1[next.x][next.y] != -1){
            // 这里下标还敢写错吗
					printf("%d\n", vis2[cur.x][cur.y] + 1 + vis1[next.x][next.y]);
			//		cout << "y" << endl;
					return ;
				}

				if(is_in(next, l) && vis2[next.x][next.y] == -1){
        //  cout << next.x << " " << next.y << endl;
					vis2[next.x][next.y] = vis2[cur.x][cur.y]+1;
					q.push(next);
				}
			}

		}
	}
}

int main()
{
	int n, l;
	scanf("%d", &n);
	while(n --){
		scanf("%d", &l);
		point s, e;
		scanf("%d%d", &s.x, &s.y);
		scanf("%d%d", &e.x, &e.y);
		dbfs(s, e, l);
	}
	return 0;
}

