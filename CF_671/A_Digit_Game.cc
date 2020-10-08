/**
 * @contest	Codeforces Round #671(Div.2)
 * @problem	Digit Game
 * @Author	Kvar_isp17
 * @Date	2020.9.24
 *
 */

#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define MAXN ((unsigned int)1e5)
using namespace std;

int T, n, a[MAXN], b[MAXN], ta, tb;
int a1, a2, b1, b2; string s;

int main() {
	scanf("%d", &T);
	while (T) {
		memset(a, 0x00, sizeof(a));
		memset(b, 0x00, sizeof(b));
		ta = tb = a1 = a2 = b1 = b2 = 0;
		scanf("%d", &n);
		s.resize(n);
		scanf("%s", &s[0]);
		for (int i = 0, tot = 0; i < n; i++) {
			tot++;
			int x = s[i] - '0';
			if ((tot % 2) != 0) a[++ta] = x, (x % 2) == 0 ? a2++ : a1++;
			else b[++tb] = x, (x % 2) == 0 ? b2++ : b1++;
		}
		int w = 0;
		if ((n % 2) == 0) b2 == 0 ? w = 1 : w = 2;
		else a1 == 0 ? w = 2 : w = 1;
		printf("%d\n", w);
		T--;
	}
	return 0;
}