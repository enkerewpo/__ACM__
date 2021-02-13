/**
 * @contest	Codeforces Round #675(Div.2)
 * @problem B. Nice Martix
 * @Author	Kvar_ispw17
 * @Date	2020.10.8
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

int T, n, m;
const int N = 105;
ll a[N][N];

int o(int x) {
	return x & 1;
}

ll procedure(int op) {
	ll r = 0;
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= m / 2; j++) {
			ll A[4] = {0, 0, 0, 0};
			A[0] = a[i][j];
			A[1] = a[i][m - j + 1];
			A[2] = a[n - i + 1][j];
			A[3] = a[n - i + 1][m - j + 1];
			sort(A, A + 4);
			ll p = A[1];
			for (int i = 0; i < 4; i++) r += abs(A[i] - p);
		}
	}
	if (op == 1) {
		int q = m / 2 + 1;
		for (int i = 1; i <= n / 2; i++) {
			ll A[2] = {0, 0};
			A[0] = a[i][q];
			A[1] = a[n - i + 1][q];
			sort(A, A + 2);
			ll p = (A[0] + A[1]) / 2;
			r += abs(A[0] - p) + abs(A[1] - p);
		}
	}
	if (op == 2) {
		int q = n / 2 + 1;
		for (int j = 1; j <= m / 2; j++) {
			ll A[2] = {0, 0};
			A[0] = a[q][j];
			A[1] = a[q][m - j + 1];
			sort(A, A + 2);
			ll p = (A[0] + A[1]) / 2;
			r += abs(A[0] - p) + abs(A[1] - p);
		}
	}
	if (op == 3) {
		int q = m / 2 + 1;
		for (int i = 1; i <= n / 2; i++) {
			ll A[2] = {0, 0};
			A[0] = a[i][q];
			A[1] = a[n - i + 1][q];
			sort(A, A + 2);
			ll p = (A[0] + A[1]) / 2;
			r += abs(A[0] - p) + abs(A[1] - p);
		}
		q = n / 2 + 1;
		for (int j = 1; j <= m / 2; j++) {
			ll A[2] = {0, 0};
			A[0] = a[q][j];
			A[1] = a[q][m - j + 1];
			sort(A, A + 2);
			ll p = (A[0] + A[1]) / 2;
			r += abs(A[0] - p) + abs(A[1] - p);
		}
	}
	return r;
}


int main() {
#ifdef DEBUG
	freopen("B.in", "r", stdin);
#endif
	read(T);
	while (T -- > 0) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				read(a[i][j]);
			}
		}
		int op = (o(n) << 1) | o(m);
		ll ans = procedure(op);
		cout << ans << endl;
	}
	return 0;
}