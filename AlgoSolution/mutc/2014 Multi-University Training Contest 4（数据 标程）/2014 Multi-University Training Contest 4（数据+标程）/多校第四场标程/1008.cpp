#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 1e-8;
inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

struct Point {
	double x, y;
	Point() {
	}
	Point(double _x, double _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(double d) const {
		return Point(x * d, y * d);
	}
	Point operator/(double d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		int c = sign(x - p.x);
		if (c)
			return c == -1;
		return sign(y - p.y) == -1;
	}
	double dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	double det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	double alpha() const {
		return atan2(y, x);
	}
	double distTo(const Point&p) const {
		double dx = x - p.x, dy = y - p.y;
		return hypot(dx, dy);
	}
	double alphaTo(const Point&p) const {
		double dx = x - p.x, dy = y - p.y;
		return atan2(dy, dx);
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double abs() {
		return hypot(x, y);
	}
	double abs2() {
		return x * x + y * y;
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	Point rot90() {
		return Point(-y, x);
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) {
	vector<Point> qs;
	int n = ps.size();
	for (int i = 0; i < n; ++i) {
		Point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	return qs;
}

double calcArea(const vector<Point>&ps) {
	int n = ps.size();
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += ps[i].det(ps[(i + 1) % n]);
	}
	return ret / 2;
}

vector<Point> convexHull(vector<Point> ps) {
	int n = ps.size();
	if (n <= 1)
		return ps;
	sort(ps.begin(), ps.end());
	vector<Point> qs;
	for (int i = 0; i < n; qs.push_back(ps[i++])) {
		while (qs.size() > 1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) {
		while (qs.size() > t && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	qs.pop_back();
	return qs;
}

typedef vector<Point> Poly;

Poly background(double X, double Y) { //[0,X] * [0,Y]
	Poly ret;
	ret.push_back(Point(0, 0));
	ret.push_back(Point(X, 0));
	ret.push_back(Point(X, Y));
	ret.push_back(Point(0, Y));
	return ret;
}

const int MAX_N = 100 + 1;

Poly BIG;
int n, X, Y;
Point ps[MAX_N];

Poly getNear(Poly ps, Point a, Point b) { //get the part near a
	Point p1 = (a + b) / 2, p2 = p1 + (b - a).rot90();
	return convexCut(ps, p1, p2);
}

double cut(Poly ps, double x) {
	double ly = 1e100, ry = -1e100;
	for (int i = 0; i < ps.size(); ++i) {
		Point p1 = ps[i], p2 = ps[(i + 1) % ps.size()];
		if (p1.x > p2.x)
			swap(p1, p2);
		if (sign(x - p1.x) >= 0 && sign(p2.x - x) >= 0) {
			double a = x - p1.x, b = p2.x - x;
			double y = (b * p1.y + a * p2.y) / (a + b);
			ly = min(ly, y);
			ry = max(ry, y);
		}
	}
	return ry - ly;
}

double sqr(double x) {
	return x * x;
}

double calc(Poly ps, double x) {
	vector<double> ix;
	for (int i = 0; i < ps.size(); ++i) {
		ix.push_back(ps[i].x);
	}
	sort(ix.begin(), ix.end());
	double ret = 0;
	for (int i = 0; i + 1 < ix.size(); ++i) {
		double l = ix[i], r = ix[i + 1];
		double m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
		double v = sqr(l - x) * cut(ps, l) + sqr(m1 - x) * cut(ps, m1) * 3
				+ sqr(m2 - x) * cut(ps, m2) * 3 + sqr(r - x) * cut(ps, r);
		v /= 8;
		v *= r - l;
		ret += v;
	}
	return ret;
}

double integrate(Poly ps, Point p) {
	double ret = calc(ps, p.x);
	for (int i = 0; i < ps.size(); ++i) {
		swap(ps[i].x, ps[i].y);
	}
	ret += calc(ps, p.y);
	return ret;
}

int main() {
	int T;
    scanf("%d",&T); 
	while (T--) {
		scanf("%d %d %d",&n,&X,&Y);
		BIG = background(X, Y);
		for (int i = 0; i < n; ++i) {
			ps[i].read();
		}

		double sum = 0;

		for (int second = 0; second < n; ++second) {
			for (int first = 0; first < n; ++first)
				if (first != second) {
					Poly py = BIG;
					py = getNear(py, ps[first], ps[second]);
					for (int i = 0; i < n; ++i)
						if (i != first && i != second) {
							py = getNear(py, ps[second], ps[i]);
							if (calcArea(py) <= 1e-8)
								break;
						}
					sum += integrate(py, ps[second]);
				}
		}

		printf("%0.10lf\n", sum / X / Y);
	}
}
