#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e6 + 5;
const int logN = 30;
int a[N], lst[N], f[N][logN];
int T, n;

map<int, int> c;

void init() {
	c.clear();
	memset(a, 0, sizeof a);
	memset(lst, 0, sizeof a);
	memset(f, 0, sizeof f);
}

int ask(int L, int R) {
	int k = log2(R - L + 1);
	return max(f[L][k], f[R - (1 << k) + 1][k]);
}

int main() {
	read(T);
	while (T--) {
		init();
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			if (!c[a[i]]) {
				c[a[i]] = i;
			} else {
				lst[i] = c[a[i]];
				c[a[i]] = i;
			}
			f[i][0] = lst[i];
		}
		for (int j = 1; j <= 21; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i++) {
				f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			int L = i, R = n, mid;
			while (L <= R) {
				mid = (L + R) / 2;
				int mx = ask(i, mid);
				if (mx < i) L = mid + 1;
				else R = mid - 1;
			}
			int tmp = L - i;
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}