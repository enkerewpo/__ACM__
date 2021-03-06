/**
 * @contest	Codeforces Round #675(Div.2)
 * @problem A. Fence
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

int T, a, b, c;

int main() {
	read(T);
	while (T--)	read(a), read(b), read(c), printf("%d\n", abs(abs(a - b) + 1 - c) + 1);
	return 0;
}