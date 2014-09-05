#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

const double eps = 1e-8;
int dcmp(double c) {
	return c < -eps ? -1 : c > eps;
}

struct Point {
	double x,y;
	Point () {}
	Point (double _x, double _y) : x(_x), y(_y) {}
	double len() { return sqrt(x * x + y * y); }
	double len2() { return x * x + y * y; }
	void read() {
		scanf("%lf%lf", &x, &y);
	}
}A[555],B[55];

Point operator - (Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator + (Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator * (Point a, double b) { return Point(a.x * b, a.y * b); }
Point operator / (Point a, double b) { return Point(a.x / b, a.y / b); }
double operator % (Point a, Point b) { return (a.x * b.x + a.y * b.y); }
double operator * (Point a, Point b) { return a.x * b.y - a.y * b.x; }

double xmul(Point a, Point b, Point c) {
	return (b - a) * (c - a);
}

struct Triangle {
	Point a,b,c;
	Triangle() {}
	Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {}
	double get_C() {
		return (b - a).len() + (c - b).len() + (a - c).len();
	}
	double get_S() {
		return fabs(xmul(a,b,c)) / 2.;
	}
	bool check_inside(Point x) {
		return dcmp(Triangle(a,b,x).get_S() + Triangle(b,c,x).get_S() + Triangle(c,a,x).get_S() - get_S()) == 0;
	}
}T[MaxN];

int v[MaxN * 2], next[MaxN * 2], h[MaxN], tot = 0; double w[MaxN * 2];
void add(int b, int e, double wei) {
	//cerr << b << ' ' << e << ' ' << wei << endl;
	v[++tot] = e; next[tot] = h[b]; h[b] = tot; w[tot] = wei;
}

int q[MaxN];
double d[66][22222];
bool vis[MaxN];
void spfa(double *d, int n) {
	int hd = 0, tl = 0;
	For(i,1,n) vis[q[++tl] = i] = true;
	int MOD = n + 10;
	while (hd != tl) {
		int vex = q[hd = hd % MOD + 1]; vis[vex] = false ;
		for (int z = h[vex]; z; z = next[z]) if (dcmp(d[v[z]] - (d[vex] + w[z])) > 0) {
			d[v[z]] = d[vex] + w[z];
			if (!vis[v[z]]) {
				vis[q[tl = tl % MOD + 1] = v[z]] = true;
			}
		}
	}
}

int n,m,k;
int numTri;
int Mask[22222];
int kind[555];
double solve(int *kind) {
	For(i,1,numTri) Mask[i] = 0;
	For(i,1,numTri) For(j,1,n) if (!(Mask[i] >> kind[j] - 1 & 1) && T[i].check_inside(A[j])) Mask[i] |= (1 << kind[j] - 1);
	Fill(vis,0);
	For(i,1,numTri) For(j,0,(1 << k) - 1) d[j][i] = 1e10;
	For(i,1,numTri) d[Mask[i]][i] = T[i].get_C();
	For(S, 0, (1 << k) - 1) {
		spfa(d[S], numTri);
		For(i,1,numTri) {
			for (int z = h[i]; z; z = next[z]) {
				d[S | Mask[v[z]]][v[z]] = min(d[S | Mask[v[z]]][v[z]], d[S][i] + w[z]);
			}
		}
	}
	double ans = 1e10;
	For(i,1,numTri) ans = min(ans, d[(1 << k) - 1][i]);
	return ans;
}

int belong[55][55][55];
int ask(int a, int b, int c) {
	if (a > b) swap(a,b);
	if (a > c) swap(a,c);
	if (b > c) swap(b,c);
	return belong[a][b][c];
}

int main() {
	//freopen("garden_input.txt","r",stdin); //
	int TT = 0;
	while (scanf("%d%d%d",&n, &m, &k) != EOF) { 
		{
			fprintf(stderr, "%d\n", ++TT);
		}
		For(i,1,n) A[i].read();
		For(i,1,n) scanf("%d",&kind[i]);
		For(i,1,m) B[i].read();

		For(i,1,n) {
			For(j,1,m) For(k,j + 1,m) if (dcmp(xmul(A[i],B[j],B[k])) == 0) {
				while (1);
			}
		}
		
		numTri = 0;
		For(i,0,(m * (m - 1) * (m - 2)) / 6 + 10) h[i] = 0;
		tot = 0;
		For(i,1,m) For(j,i + 1,m) {
			int st = numTri - j;
			For(k,j + 1,m) {
				T[++numTri] = Triangle(B[i],B[j],B[k]);
				belong[i][j][k] = numTri;
			}
		}
		For(i,1,m) For(j,i + 1,m) {
			For(k,1,m) For(l,k + 1,m) if (dcmp(xmul(B[i],B[j],B[k])) * dcmp(xmul(B[i],B[j],B[l])) == -1) {
				double len = (B[i] - B[j]).len();
				add(ask(i,j,k), ask(i,j,l), (B[l]-B[i]).len() + (B[l]-B[j]).len() - len);;
				add(ask(i,j,l), ask(i,j,k), (B[k]-B[i]).len() + (B[k]-B[j]).len() - len);
			}
		}
		double ans = solve(kind);
		if (dcmp(ans - 1e9) > 0) puts("Impossible");
		else {
			printf("%.12lf\n", ans);
		}
	}
	return 0;
}

