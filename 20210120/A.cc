#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e4 + 5;
int co[N];
int L, M;

int main() {
	read(L);
	read(M);
	while (M--) {
		int l, r;
		read(l);
		read(r);
		for (int i = l; i <= r; i++) {
			co[i]++;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= L; i++) {
		if (!co[i]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}