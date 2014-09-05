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

struct Matrix {
	int r,c;
	int a[33][33];
	Matrix() {}
	void Init(int _r, int _c) {
		r = _r; c = _c;
		memset(a,0,sizeof(a));
	}
	void tr() {
		For(i,1,c) For(j,i + 1,r) swap(a[i][j], a[j][i]); 
		swap(r,c);
	}
	int *operator [](int x) { return a[x]; }
	int findMin() {
		int ret = INF;
		For(i,1,r) For(j,1,c) ret = min(ret, a[i][j]);
		return ret;
	}
	Matrix subrec(int x1, int y1, int x2, int y2) {
		Matrix ret;
		ret.Init(x2 - x1 + 1, y2 - y1 + 1);
		For(i,x1,x2) For(j,y1,y2) {
			ret[i - x1 + 1][j - y1 + 1] = a[i][j];
		}
		return ret;
	}
	Matrix rot() {
		Matrix ret;
		ret.Init(r,c);
		if (r == c) {
			For(i,1,r) For(j,1,c) ret[i][j] = a[c - j + 1][i]; // rot 90 if square
		} else {
			For(i,1,r) For(j,1,c) ret[i][j] = a[r - i + 1][c - j + 1];	// rot 180 only
		}
		return ret;
	}
}A, B[5], tmp[5];

Matrix operator + (Matrix a, Matrix b) {
	Matrix c;
	c.Init(a.r,a.c);
	For(i,1,a.r) For(j,1,a.c) c[i][j] = a[i][j] + b[i][j];
	return c;
}

int solve(Matrix *B) {
	int ret = 0;
	For(I,2,4) if (B[1].r != B[I].r) {
		//1 2 3
		//4 5 6
		//to
		//4 1
		//5 2
		//6 3
		Matrix tmp;
		tmp.r = B[I].c;
		tmp.c = B[I].r;
		memset(tmp.a, 0, sizeof(tmp.a));
		For(i,1,B[I].c) For(j,1,B[I].r) {
			tmp[i][j] = B[I][B[I].r - j + 1][i];
		}
		B[I] = tmp;
	}
	For(T2,1,4) {
		For(T3,1,4) {
			For(T4,1,4) {
				ret = max(ret, (B[1] + B[2] + B[3] + B[4]).findMin());
				B[4] = B[4].rot();
			}
			B[3] = B[3].rot();
		}
		B[2] = B[2].rot();
	}
	return ret;
}
	
int main() {
	//freopen("input.txt","r",stdin); // freopen("output.txt","w",stdout);
	
	int n,m;

	while (cin >> n >> m) {
		A.Init(n,m);
		For(i,1,n) For(j,1,m) scanf("%d",&A[i][j]);

		int ans = 0;

		if (n % 4 == 0) {
			//1111
			//2222
			//3333
			//4444
			int tr = n / 4;
			For(i,1,4) B[i] = A.subrec((i - 1) * tr + 1, 1, i * tr, m);
			ans = max(ans, solve(B));
		}
		
		if (m % 4 == 0) {
			//1234
			//1234
			//1234
			int tr = m / 4;
			For(i,1,4) B[i] = A.subrec(1, (i - 1) * tr + 1, n, i * tr);
			ans = max(ans, solve(B));
		}

		if (n % 2 == 0 && m % 2 == 0) {
			//1122
			//1122
			//3344
			//3344
			int tr = n / 2, tc = m / 2;
			For(i,1,2) For(j,1,2) B[(i - 1) * 2 + j] = A.subrec((i - 1) * tr + 1, (j - 1) * tc + 1, i * tr, j * tc);
			ans = max(ans, solve(B)); // take care of n == m
		}
		
		if (n > m) {
			A.tr();
			swap(n,m);
		}
		
		if (n * 4 == m * 3) {
			//1222
			//1333
			//1444
			B[1] = A.subrec(1, 1, n, m / 4);
			B[2] = A.subrec(1, m / 4 + 1, n / 3, m);
			B[3] = A.subrec(n / 3 + 1, m / 4 + 1, n / 3 * 2, m);
			B[4] = A.subrec(n / 3 * 2 + 1, m / 4 + 1, n, m);
			ans = max(ans, solve(B));
			//2221
			//3331
			//4441
			B[2] = A.subrec(1, 1, n / 3, m / 4 * 3);
			B[3] = A.subrec(n / 3 + 1, 1, n / 3 * 2, m / 4 * 3);
			B[4] = A.subrec(n / 3 * 2 + 1, 1, n, m / 4 * 3);
			B[1] = A.subrec(1, m / 4 * 3 + 1, n, m);
			ans = max(ans, solve(B));
		}
		
		if (2 * n == m) {
			// n, m must be multple of 2
			//1134
			//2234
			// maybe not necessary
			B[1] = A.subrec(1, 1, n / 2, m / 2);
			B[2] = A.subrec(n / 2 + 1, 1, n, m / 2);
			B[3] = A.subrec(1,m / 2 + 1, n, m / 4 * 3);
			B[4] = A.subrec(1, m / 4 * 3 + 1, n, m);
			ans = max(ans, solve(B));
			//1224
			//1334
			B[1] = A.subrec(1, 1, n, m / 4);
			B[2] = A.subrec(1, m / 4 + 1, n / 2, m / 4 * 3);
			B[3] = A.subrec(n / 2 + 1, m / 4 + 1, n, m / 4 * 3);
			B[4] = A.subrec(1,m / 4 * 3 + 1, n, m);
			ans = max(ans,solve(B));
			//1233
			//1244
			// maybe not necessary
			B[1] = A.subrec(1, 1, n, m / 4);
			B[2] = A.subrec(1, m / 4 + 1, n, m / 2);
			B[3] = A.subrec(1, m / 2 + 1, n / 2, m);
			B[4] = A.subrec(n / 2 + 1, m / 2 + 1, n, m);
			ans = max(ans, solve(B));
		}
		
		cout << ans << endl;
	
	}
	return 0;
}

