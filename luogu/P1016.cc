#if 0

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;


typedef long long ll;
template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const double inf = 1e10;

class Station {
  public:
	double d, p;
	Station() {
		d = p = 0;
	}
	Station(double _d, double _p) {
		d = _d;
		p = _p;
	}
} s[15];

double d1, c, d2, p0;
int n;

int main() {
	freopen("P1016.in", "r", stdin);
	scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &p0, &n);
	s[0] = Station(0, p0);
	for (int i = 1; i <= n; i++) {
		double _d, _p;
		scanf("%lf%lf", &_d, &_p);
		s[i] = Station(_d, _p);
	}
	int id = n + 1;
	double dc = c * d2;
	printf("dc = %.2lf\n", dc);
	double co = d1;
	double ans = 0;
	while (1) {
		double L = co - dc;
		printf("co: %.2lf L -> %.2lf   ans = %.2lf\n", co, L, ans);
		int bn = -1;
		double bv = inf;
		for (int i = 1; i <= n; i++) {
			if (s[i].d >= L && s[i].d < co) {
				printf("i = %d in!\n", i);
				if (s[i].p * ((co - s[i].d) / d2) < bv) {
					bv = s[i].p * ((co - s[i].d) / d2);
					bn = i;
				}
			}
		}
		printf("%d\n", bn);
		if (bn == -1) {
			if (L < 0) {
				ans += s[0].p * (co / d2);
				break;
			} else {
				puts("No Solution");
				return 0;
			}
		} else {
			id = bn;
			co = s[id].d;
			ans += bv;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}

/*
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2

26.95
 */

#endif

int main() {
	return 0;
}