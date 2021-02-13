#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 4e4 + 5;

char a[N], b[N], c[N];
int tot, tot2, m[N], p[N], id, mx, _n, mxl;
int A, lA = -1;

__inline void manacher(char s[]) {
	c[0] = '$', c[1] = '#';
	int t = 2;
	for (int i = 0; i < tot2; i++) { c[t++] = s[i]; c[t++] = '#'; }
	c[t] = '\0', mxl = -1;
	for (int i = 1; i < t; i++) {
		if (i < mx) { p[i] = min(p[2 * id - i], mx - i); } else p[i] = 1;
		while (c[i - p[i]] == c[i + p[i]]) p[i]++;
		if (mx < i + p[i]) { id = i; mx = i + p[i]; }
		mxl = max(mxl, p[i] - 1);
	}
	for (int i = 0; i < t; i++)	if (p[i] - 1 > lA) { A = i; lA = p[i] - 1; }
	printf("%d\n", lA);
	if (A % 2 == 0) {
		lA = (lA - 1) / 2;
		int x = A / 2, L = x - lA, R = x + lA;
		for (int i = m[L]; i <= m[R]; i++) { printf("%c", a[i]); } puts("");
	} else {
		lA = lA / 2;
		int y = (A - 1) / 2, L = y - lA + 1, R = y + lA;
		for (int i = m[L]; i <= m[R]; i++) { printf("%c", a[i]); } puts("");
	}
}

int main() {
	char tmp;
	while ((tmp = getchar()) != EOF) {
		a[++tot] = tmp;
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) {
			b[++tot2] = tmp;
			m[tot2] = tot;
		}
	}
	for (int i = 1; i <= tot2; i++) b[i] = tolower(b[i]);
	b[tot2 + 1] = '\0';
	manacher(b + 1);
	return 0;
}