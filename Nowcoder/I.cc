#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld a, b, k;

int main() {
	cin >> a >> b >> k;
	if (k == 1) printf("%.9Lf\n", a);
	else if (k == 2)  printf("%.9Lf\n", b);
	else {
		k -= 2;
		ld xn, xn1 = b, xn2 = a;
		for (int i = 1; i <= k; i++) {
			xn = (1 + xn1) / (xn2);
			xn2 = xn1;
			xn1 = xn;
		}
		printf("%.9Lf\n", xn);
	}
	return 0;
}