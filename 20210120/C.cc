#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 200000 + 5;
int a[N], n;

priority_queue<int, vector<int>, greater<int>> p;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	p.push(a[1]);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		int x = a[i];
		if (x < p.top()) {
			p.push(x);
		} else {
			ans += x - p.top();
			p.pop();
			p.push(x);
			p.push(x);
		}
	}
	printf("%d\n", ans);
	return 0;
}