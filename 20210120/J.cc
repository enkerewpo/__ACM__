#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

ll a, b, c, d;
int T;

void print(ll x) {
	for (int i = 63; i >= 0; i--) {
		int p = x >> i & 1;
		printf("%d", p);
	}
}

int main() {
	read(T);
	while (T--) {
		read(a), read(b), read(c), read(d);
		ll ans = 0;
		ll ta, tb, tc, td;
		ta = a;
		tb = b;
		tc = c;
		td = d;
		for (int i = 62; i >= 0; i--) {
			ll t = 1LL << (i + 1);
			ll _t = 1LL << i;
			// printf("i = %d \t_t =\n", i); print(_t); puts(""), puts("---");
			int x0, x1, y0, y1;
			x0 = x1 = y0 = y1 = 0;
			if (ta <= _t - 1) x0 = 1;
			if (tb >= _t) x1 = 1;
			if (tc <= _t - 1) y0 = 1;
			if (td >= _t) y1 = 1;
			// printf("x0=%d  x1=%d  y0=%d  y1=%d\n", x0, x1, y0, y1);
			if (x0 && x1 && y0 && y1) {
				ans += t - 1;
				break;
			}
			if (x0 && y1) {
				ans += _t;
				tc -= _t;
				td -= _t;
				continue;
			}
			if (x1 && y0) {
				ans += _t;
				ta -= _t;
				tb -= _t;
				continue;
			}
			if ((!x0) && (!y0)) {
				ta -= _t;
				tb -= _t;
				tc -= _t;
				td -= _t;
			}
			// print(td), puts("");
			// print(tc), puts("");
			// print(tb), puts("");
			// print(ta), puts("");
			// puts("------------");
		}
		printf("%lld\n", ans);
	}
	return 0;
}