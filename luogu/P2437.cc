#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

typedef long long ll;

#define int ll

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e5 + 5;

int m, n;
int dp[N];

signed main() {
	read(m), read(n);
	dp[m] = 1;
	for (int i = m + 1; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[n]);
	return 0;
}