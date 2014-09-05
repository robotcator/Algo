// File Name: std.cpp
// Author: YangYue
// Created Time: Mon Jul  7 10:19:40 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

FILE* fin = NULL;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 10005;
const double eps = 1e-9;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;
const double pi = acos(- 1.0);

int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
}
struct Point {
	double x, y;
	Point (){}
	Point(double x, double y) : x(x), y(y) {}
	Point operator - (const Point &b) { return Point(x - b.x, y - b.y); }
	Point operator + (const Point &b) { return Point(x + b.x, y + b.y); }
	Point operator * (const double &b) { return Point(x * b, y * b); }
	Point operator / (const double &b) { return Point(x / b, y / b); }
	Point rot90(int t) { return Point(-y, x) * t; }
	Point rot(double ang) { return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); }
	double ang() { double res = atan2(y, x); if (dcmp(res) < 0) res += pi * 2; return res; }
	double operator * (const Point &b) { return x * b.y - y * b.x; }
	double operator % (const Point &b) { return x * b.x + y * b.y; }
	double len2() { return x * x + y * y; }
	double len() { return sqrt(x * x + y * y); }
	void init() { fscanf(fin,"%lf %lf", &x, &y); }
} hull[100005];
struct Cir {
	Point c;
	double r;
	Cir(){}
	Cir(Point c, double r) : 
		c(c), r(r) {}
} cir[10005];
Point calc_center(Point c, double r, double ang1, double ang2) {
	double ang = ang2 - ang1;
	if (dcmp(ang) == 0) return Point(0, 0);
	Point p1 = c + Point(r, 0).rot(ang1);
	Point p2 = c + Point(r, 0).rot(ang2);
	Point center = Point(sin(ang2)-sin(ang1), cos(ang1)-cos(ang2))*(r*r*r/3);
	double area = r * r * ang * 0.5;
	center = c*area + center;
	double area1 = (p1-c)*(p2-c) * 0.5;
	double area2 = (area - area1);
	center = (center - (p1+p2+c)*(area1/3));
	return (center + (p1+p2) * (p1*p2) / 6);
}
double calc_area(Point c, double r, double ang1, double ang2) {
	double ang = ang2 - ang1;
	if (dcmp(ang) == 0) return 0;
	Point p1 = c + Point(r, 0).rot(ang1);
	Point p2 = c + Point(r, 0).rot(ang2);
	return (r * r * (ang - sin(ang)) + p1 * p2) * 0.5;
}
bool rm[MaxN];
pair<double, int> keys[MaxN * 10];
vector<Point> getCC(Point c1, double r1, Point c2, double r2) { 
	vector<Point> res;
	double x = (c1 - c2).len2();
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if (d < -eps) return res;
	if (d < 0) d = 0;
	Point q1 = c1 + (c2 - c1) * y;
	Point q2 = ((c2 - c1) * sqrt(d)).rot90(1);
	res.push_back(q1 - q2);
	res.push_back(q1 + q2);
	return res;
}
bool cmp(const pair<double,int> &a, const pair<double,int> &b) {
	if (dcmp(a.fi - b.fi) != 0) return dcmp(a.fi - b.fi) < 0;
	return a.se > b.se;
}
pair<Point, double> solve(int cur, int n) {
	if (rm[cur]) return MP(Point(0, 0), 0);
	int m = 0;
	for (int i = 0; i < n; ++i) if (i != cur && !rm[i]) {
		// if (cir[cur] 被 cir[i] 包含或内切) { ++cover[cur]; continue; }
		vector<Point> root = getCC(cir[cur].c, cir[cur].r, cir[i].c, cir[i].r);
		if (root.size() == 0) continue;
		double ang1 = (root[0] - cir[cur].c).ang();
		double ang2 = (root[1] - cir[cur].c).ang();
		if (dcmp(ang1 - ang2) == 0) continue;
		if (dcmp(ang1 - ang2) >= 0) {
			keys[m++] = make_pair(0, 1);
			keys[m++] = make_pair(ang2, -1);
			keys[m++] = make_pair(ang1, 1);
			keys[m++] = make_pair(2*pi, -1);
		} else {
			keys[m++] = make_pair(ang1, 1);
			keys[m++] = make_pair(ang2, -1);
		}
	}
	keys[m++] = make_pair(0, 0);
	keys[m++] = make_pair(2 * pi, - 100000);
	sort(keys, keys + m, cmp);
	Point res = calc_center(cir[cur].c, cir[cur].r, 0, keys[0].first);
	double area = calc_area(cir[cur].c, cir[cur].r, 0, keys[0].first);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		cnt += keys[i].second;
		if (cnt == 0) {
			res = res + calc_center(cir[cur].c, cir[cur].r, keys[i].first, keys[i+1].first);
			area += calc_area(cir[cur].c, cir[cur].r, keys[i].first, keys[i+1].first);
		}
		// area[cover[cur] + cnt] -= tarea;
		// area[cover[cur] + cnt + 1] += tarea;
	}
	return MP(res, area);
}
int main(int argc,char* argv[])
{
	fin = fopen(argv[1],"rt");

	int n, m, tar;
	while (fscanf(fin,"%d %d %d", &n, &m, &tar) != EOF) {

		double area2 = 0;
		Point center2 = Point(0, 0);
		for (int i = 0; i < n; ++i) {
			hull[i].init();
		}
		Point target = hull[tar-1];
		hull[n] = hull[0];
		for (int i = 0; i < n; ++i) {
			center2 = center2 + (hull[i] + hull[i+1]) / 6 * (hull[i] * hull[i+1]);
			area2 += hull[i] * hull[i+1] / 2;
		}
		for (int i = 0; i < m; ++i) {
			Point c; double r;
			c.init(); fscanf(fin,"%lf", &r);
			cir[i] = Cir(c, r);
		}
		memset(rm, 0, sizeof rm);
		for (int i = 0; i < m; ++i) if (!rm[i])
			for (int j = 0; j < m; ++j) if (i != j && !rm[j]) {
				double d = (cir[i].c - cir[j].c).len();
				if (dcmp(d - (cir[i].r - cir[j].r)) <= 0) rm[j] = 1;
			}
		Point center1 = Point(0, 0);
		double area1 = 0;
		for (int i = 0; i < m; ++i) {
			pair<Point, double> tmp = solve(i, m);
			center1 = center1 + tmp.first;
			area1 += tmp.second;
		}
		Point center = (center2 - center1) / (area2 - area1);

		Point vect = Point(0, -1);
		Point tmp = center - target;
		double ang = atan2(-1, 0) - atan2(tmp.y, tmp.x);


		for (int i = 0; i < n; ++i) {
			Point ans = target + (hull[i] - target).rot(ang);
			double pax,pay;
			if(scanf("%lf %lf",&pax,&pay) != 2) return 0;
			if(fabs(pax-ans.x) < 1e-5 && fabs(pay-ans.y) < 1e-5) { printf("OK %d\n",i); }
			else
			{
				puts("WA, ZAN!");
				return 0;
			}
			//printf("%.6f %.6f\n", ans.x, ans.y);
		}
	}

	return 0;
}

// hehe ~


