/**
 * @contest	Codeforces Round #672(Div.2)
 * @problem A. Cubes Sorting
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

const int N = 5 * 1e4 + 5;

int T, n;
int a[N];

int main() {
	read(T);
	while (T--) {
		read(n);
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) read(a[i]);
		bool f = true;
		for (int i = 2; i <= n; i++)
			if (a[i] >= a[i - 1]) f = false;
		if (f) puts("NO");
		else puts("YES");
	}
	return 0;
}