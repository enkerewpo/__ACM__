#include <bits/stdc++.h>
using namespace std;

#if 0

typedef long long ll;
#define int ll

int n, m;
#define N 100
#define M 1000001

// #define DEBUG


int a[N][M], b[M];
int A[N];
const int MOD = 1e9 + 7;

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i][n + 1];
		A[i] = a[i][n + 1];
	}
	for (int i = 0; i <= m; i++) {
		cin >> b[i];
	}
	for (int j = n; j >= 1; j--) {
		for (int i = 0; i < n; i++) {
			if (i + j == n) a[i][j] = 1;
		}
	}
	for (int k = n + 2; k <= n + m; k++) {
		for (int i = 0; i < n; i++) {
			a[i][k] = ((A[i] * a[0][k - 1]) % MOD + a[i + 1][k - 1]) % MOD;
		}
	}

#ifdef DEBUG
	puts("--------------------------");
	for (int j = n + m; j >= 1; j--) {
		for (int i = 0; i < n; i++) printf("%lld ", a[i][j]);
		puts("");
	}
	puts("--------------------------");
#endif

	for (int j = n; j >= 1; j--) {
		for (int i = 0; i < n; i++) {
			ll x = 0;
			for (int _k = 0; _k <= m; _k++) {
				x = (x + ((b[_k] % MOD) * (a[i][j + _k] % MOD)) % MOD ) % MOD;
			}
			printf("%lld ", x);
		}
		puts("");
	}
	return 0;
}

/*

3 2
1 2 3
1 2 3

4 3
1 2 3 4
1 2 3 4

 *
 */

#endif

#if 1

typedef long long ll;
#define int ll

int n, m;
#define N 105
#define M 1000001

#define DEBUG


int a[N][N], b[M];
int A[N];
const int MOD = 1e9 + 7;

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][n + 1];
		A[i] = a[i][n + 1];
	}
	for (int i = 0; i <= m; i++) {
		cin >> b[i];
	}
	for (int j = n; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			if (i + j == n + 1) a[i][j] = 1;
		}
	}
#ifdef DEBUG
	puts("--------------------------");
	for (int j = n + m; j >= 1; j--) {
		for (int i = 1; i <= n; i++) printf("%lld ", a[i][j]);
		puts("");
	}
	puts("--------------------------");
#endif

	for (int j = n; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			ll x = 0;
			
			for (int _k = 0; _k <= m; _k++) {
				// x = (x + ((b[_k] % MOD) * (a[i][j + _k] % MOD)) % MOD ) % MOD;
				
			}
			printf("%lld ", x);
		}
		puts("");
	}
	return 0;
}

#endif