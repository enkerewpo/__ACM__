#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;
ll e[100];

void init() {
	e[0] = 1;
	for (int i = 1; i <= 62; i++) {
		e[i] = e[i - 1] * 2;
	}
	e[63] = LLONG_MAX;
}


int main() {
	init();
	// for(int i = 0; i <= 63; i++) {
	// printf("%lld\n", e[i]);
	// }
	cin >> T;
	while (T--) {
		int fa = 0;
		cin >> n;
		n++;
		if (n == 1) {
			puts("0");
		} else if (n == 2) {
			puts("1");
		} else {
			// printf("!!!fa = %d\n", fa + 2);
			while (n > 2) {
				int k;
				for (int i = 0; i <= 62; i++) {
					if (n > e[i] && n <= e[i + 1]) {
						k = i;
					}
				}
				n -= e[k];
				fa ^= 1;
				// printf("k = %d  n => %d\n", k, n);
				// printf("fa = %d\n", fa);
			}
			int ans;
			if (n == 1) {
				ans = 0;
			} else {
				ans = 1;
			}
			ans ^= fa;
			printf("%d\n", ans);
		}
	}
	return 0;
}