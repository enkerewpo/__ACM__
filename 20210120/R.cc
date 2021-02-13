#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 35;

class Point {
  public:
	int x, y;
	Point(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
} a[N];

class Rectangle {
  public:
	Point A, B;
	Rectangle() {}
	Rectangle(Point _A , Point _B) {
		A = _A, B = _B;
	}
	int S() {
		return abs(A.x - B.x) * abs(A.y - B.y);
	}
} R[1500];

int n, tot;
bool v[205][205];

void init() {
	memset(a, 0, sizeof a);
	memset(R, 0, sizeof R);
	memset(v, 0, sizeof v);
	tot = 0;
}

bool Intersect(Rectangle R1, Rectangle R2) {
	Point p[4], q[4];
	p[0] = R1.A;
	p[1] = R1.B;
	p[2] = Point(R1.A.x, R1.B.y);
	p[3] = Point(R1.A.y, R1.B.x);

	q[0] = R2.A;
	q[1] = R2.B;
	q[2] = Point(R2.A.x, R2.B.y);
	q[3] = Point(R2.A.y, R2.B.x);

	for (int i = 0; i < 4; i++) {
		Point o = q[i];
		int x = o.x;
		int y = o.y;
		if (x >= p[0].x && x <= p[1].x && y >= p[0].y && y <= p[1].y) {
			return 1;
		}
	}
	return 0;
}

int Inside(Rectangle R1, Rectangle R2) {
	Point A1 = R1.A;
	Point B1 = R1.B;
	Point A2 = R2.A;
	Point B2 = R2.B;
	if (A1.x >= A2.x && A1.x <= B2.x && A1.y >= A2.y && A1.y <= B2.y &&
	        B1.x >= A2.x && B1.x <= B2.x && B1.y >= A2.y && B1.y <= B2.y) {
		return R2.S();
	}
	return 0;
}

int main() {
	while (scanf("%d", &n)) {
		if (!n) break;
		init();
		for (int i = 1; i <= n; i++) {
			int _x, _y;
			scanf("%d%d", &_x, &_y);
			a[i] = Point(_x, _y);
			// printf("a[%d] = %d, %d\n", i, a[i].x, a[i].y);
			v[_x][_y] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				Point X = a[i];
				Point Y = a[j];
				Point _X = Point(a[i].x, a[j].y);
				Point _Y = Point(a[i].y, a[j].x);
				if (v[_X.x][_X.y] && v[_Y.x][_Y.y]) {
					R[++tot] = Rectangle(X, Y);
					if (R[tot].S() == 0) tot--;
				}
			}
		}
		if (tot == 0) {
			puts("imp");
			continue;
		}
		int ans = 0;
		for (int i = 1; i < tot; i++) {
			for (int j = i + 1; j <= tot; j++) {
				if (!Intersect(R[i], R[j])) {
					int op1 = Inside(R[i], R[j]);
					int op2 = Inside(R[j], R[i]);
					int op = max(op1, op2);
					if (op) {
						ans = max(ans, op);
					} else {
						ans = max(ans, R[i].S() + R[j].S());
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}