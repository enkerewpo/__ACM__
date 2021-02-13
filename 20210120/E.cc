#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 100 + 5;

int n, a[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	sort(a + 1, a + n + 1);
	int m = unique(a + 1, a + n + 1) - (a + 1);
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) {
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}