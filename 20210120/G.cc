#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

class segment {
  public:
	int l, r;
	segment(int _l = 0, int _r = 0) {
		l = _l, r = _r;
	}
	bool operator < (const segment o) const {
		return l < o.l;
	}
};

int n;
segment a[105];

void init() {
	memset(a, 0, sizeof a);
}

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		init();
		for (int i = 1; i <= n; i++) {
			int l, r;
			read(l), read(r);
			a[i] = segment(l, r);
		}
		sort(a + 1, a + n + 1);
#ifdef DEBUG
		for (int i = 1; i <= n; i++) {
			printf("[%d, %d]\n", a[i].l, a[i].r);
		}
#endif
		int ans = 1;
		segment x = a[n];
		for (int i = n - 1; i >= 1; i--) {
			if (a[i].r <= x.l) {
				ans++;
				x = a[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}