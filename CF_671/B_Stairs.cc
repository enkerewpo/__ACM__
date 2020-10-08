/**
 * @contest	Codeforces Round #671(Div.2)
 * @problem	B. Stairs
 * @Author	Kvar_ispw17
 * @Date	2020.9.25
 *
 */
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int T; ll x;

int main() {
	scanf("%d", &T);
	while (T) {
		scanf("%lld", &x);
		int cnt = 0;
		for (ll i = 1; ; i =  i * 2 + 1) {
			ll c = (1 + i) * i / 2;
			x >= c ? cnt++, x -= c : break;
		}
		printf("%d\n", cnt), T--;
	}
	return 0;

}