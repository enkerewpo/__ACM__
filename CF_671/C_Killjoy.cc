/**
 * @contest	Codeforces Round #671(Div.2)
 * @problem	C. Killjoy
 * @Author	Kvar_ispw17
 * @Date	2020.10.6
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define inf 5000

int T, n, x, a[MAXN];
bool f1 = true;
bool f2 = false;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &x);
		memset(a, -inf, sizeof(a));
		int sum = 0;
		f1 = true;
		f2 = false;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] != x) f1 = false;
			if (a[i] == x) f2 = true;
			sum += a[i];
		}
		int ans = -1;
		if (f1) ans = 0;
		else if (sum == n * x) ans = 1;
		else if (f2) ans = 1;
		else ans = 2;
		printf("%d\n", ans);
	}
	return 0;
}