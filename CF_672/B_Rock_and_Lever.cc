/**
 * @contest	Codeforces Round #672(Div.2)
 * @problem B. Rock and Lever
 * @Author	Kvar_ispw17
 * @Date	2020.10.8
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;
typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e5 + 10;

int T, n;
int a[N];


int main() {
	read(T);
	while (T--) {
		memset(a, 0, sizeof a);
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		ll ans = 0;
		for (int j = 31; j >= 0; j--) {
			ll cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] >= (1 << j) && a[i] < (1 << (j + 1))) cnt++;
			}
			ans += cnt * (cnt - 1) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}