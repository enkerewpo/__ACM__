#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
typedef long double ld;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const ld INF = 2000.;
const ld eps = 1e-9;

class Point {
  public:
	ld x, y;
	Point(ld _x = -INF, ld _y = -INF) {
		x = _x, y = _y;
	}
	bool operator == (const Point o) const {
		return (abs(o.x - x) < eps) && (abs(o.y - y) < eps);
	}
};

ld dis(Point A, Point B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

class trangle {
  public:
	Point A, B, C;
	ld a, b, c;
	trangle() {	}
	trangle(Point _A, Point _B, Point _C) {
		A = _A, B = _B, C = _C;
	}
	bool operator = (const trangle o) const {
		return (o.A == A) && (o.B == B) && (o.C == C);
	}

};

bool similar(trangle M, trangle N) {
	ld t1[3], t2[3];
	t1[0] = M.a, t1[1] = M.b, t1[2] = M.c;
	t2[0] = N.a, t2[1] = N.b, t2[2] = N.c;
	sort(t1, t1 + 3);
	sort(t2, t2 + 3);
	// for (int i = 0; i < 3; i++) {
	//	printf("[%lf] ", t1[i]);
	// }
	ld k0 = t1[0] / t2[0];
	ld k1 = t1[1] / t2[1];
	ld k2 = t1[2] / t2[2];
	// printf("\t k0=%.4lf  k1=%.4lf  k2=%.4lf\n", k0, k1, k2);
	if (abs(k0 - k1) < eps &&
	        abs(k0 - k2) < eps &&
	        abs(k1 - k2) < eps) {
		return true;
	} else return false;
}

int n;

trangle a[1000];
int c[1000];
Point P[20];

bool vis[300][300];

void init() {
	memset(a, 0, sizeof a);
	memset(P, 0, sizeof P);
	memset(c, 0, sizeof c);
	memset(vis, 0, sizeof vis);
}

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		init();
		int _n = n;
		n = 0;
		for (int i = 1; i <= _n; i++) {
			int _x, _y;
			scanf("%d%d", &_x, &_y);
			if (vis[_x][_y]) continue;
			vis[_x][_y] = 1;
			P[++n] = Point(ld(_x), ld(_y));
		}
		int tot = 0;
		for (int i = 1; i <= n - 2; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				for (int k = j + 1; k <= n; k++) {
					Point A = P[i], B = P[j], C = P[k];
					trangle t;
					tot++;
					a[tot] = trangle(A, B, C);
					a[tot].c = dis(A, B);
					a[tot].b = dis(A, C);
					a[tot].a = dis(B, C);
					if (abs(a[tot].a) < eps ||
					        abs(a[tot].b) < eps ||
					        abs(a[tot].c) < eps) {
						tot--;
						continue;
					}
					ld T[3];
					T[0] = a[tot].a, T[1] = a[tot].b, T[2] = a[tot].c;
					sort(T, T + 3);
					if (abs(T[0] + T[1] - T[2]) < eps) {
						tot--;
						continue;
					}
					if (T[0] + T[1] < T[2]) {
						tot--;
						continue;
					}
				}
			}
		}
		// printf("\t ->>>> tot =  %d\n", tot);
		int ans = 0;
		for (int i = 1; i <= tot; i++) {
			c[i] = 1;
		}
		for (int i = 1; i <= tot - 1; i++) {
			for (int j = i + 1; j <= tot; j++) {
				if (similar(a[i], a[j])) {
					c[i]++;
					c[j]++;
				}
			}
		}
		for (int i = 1; i <= tot; i++) {
			ans = max(ans, c[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}