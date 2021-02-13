#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

typedef long long ll;
// #define DEBUG

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e5 + 5;

int T, n, a[N], b[N];

void init() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
}

void update(int &p) {
	if (p == n) p = 1;
	else p++;
}

int next(int p) {
	if (p == n) return 1;
	else return p + 1;
}

int pre(int p) {
	if (p == 1) return n;
	else return p - 1;
}

class data {
  public:
	int x, y;
	data(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
} c[N * 10];

int main() {
#ifdef DEBUG
	freopen("O.in", "r", stdin);
#endif
	read(T);
	while (T--) {
		init();
		read(n);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int mean = sum / n;
		if (sum % n != 0) {
			puts("NO");
			continue;
		}
		bool f0 = 0;
		for (int i = 1; i <= n; i++) {
			a[i] -= mean;
			if (abs(a[i]) > 2 || (n == 2 && abs(a[i]) >= 2)) {
				f0 = 1;
				break;
			}
		}
		if (f0) {
			puts("NO");
			continue;
		}
		int m = 0;
		for (int i = 1; i <= n; i++) b[i] = a[i];
		int idx = 1;
		for (int i = 1; i <= n; i++) {
			if (b[i] > 0) {
				idx = i;
				break;
			}
		}
		for (int i = idx; ; i = next(i)) {
			int j = next(i);
			if (b[i] > 0) {
				c[++m] = data(i, j);
				b[i]--;
				b[j]++;
			}
			if (b[i] < 0) {
				c[++m] = data(j, i);
				b[i]++;
				b[j]--;
			}
			if (j == idx) break;
		}
		bool f1 = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] != 0) {
				f1 = 1;
				break;
			}
		}
		if (f1) {
			m = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i];
			for (int i = idx; ; i = pre(i)) {
				int j = pre(i);
				if (b[i] > 0) {
					c[++m] = data(i, j);
					b[i]--;
					b[j]++;
				}
				if (b[i] < 0) {
					c[++m] = data(j, i);
					b[i]++;
					b[j]--;
				}
				if (j == idx) break;
			}
			bool f2 = 0;
			for (int i = 1; i <= n; i++) {
				if (b[i] != 0) {
					f2 = 1;
					break;
				}
			}
			if (f2) {
				puts("NO");
				continue;
			}
		}
		puts("YES");
		printf("%d\n", m);
		for (int i = 1; i <= m; i++) {
			printf("%d %d\n", c[i].x, c[i].y);
		}
	}
	return 0;
}