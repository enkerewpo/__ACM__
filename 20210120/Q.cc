

#if 0

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int _N = 2e5 + 5;

int T;
int n, m, k, a[_N];

void init() {
	memset(a, 0, sizeof a);
}

int main() {
	read(T);
	for (int t = 1; t <= T; t++) {
		init();
		read(n), read(m), read(k);
		for (int i = 1; i <= n; i++) {
			int _p;
			read(_p);
			a[i] = _p;
		}
		sort(a + 1, a + n + 1, greater<int>());
		int p = 0;
		int ans = 0;
		while (p < m) {
			int f = p + k;
			if (f >= m) {
				ans++;
				break;
			}
			int g, x;
			if (n == 0) {
				g = -1;
			} else {
				x = lower_bound(a + 1, a + n + 1, f, greater<int>()) - a;
				// printf("p = %d   f = %d  got x = %d and a[%d] = %d\n", p, f, x, x, a[x]);
				g = a[x];
			}
			if (g <= p) {
				p = f;
				ans++;
			} else {
				p = g;
				ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

/*
1
4 10 2
1 3 7 9

 */

#endif