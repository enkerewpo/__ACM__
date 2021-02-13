#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

int T, x;
int b[10] = {0, 9, 17, 24, 30, 35, 39, 42, 44, 45};
int c[50], tot;

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(c, 0, sizeof c);
		tot = 0;
		scanf("%d", &x);
		if (x >= 46) puts("-1");
		else {
			string s = "";
			for (int i = 1; i <= 9; i++) {
				if (x > b[i]) {
					c[++tot] = 10 - i;
					continue;
				}
				int r = x - b[i - 1];
				c[++tot] = r;
				break;
			}
			for(int i = tot; i >= 1; i--) {
				printf("%d", c[i]);
			}
			printf("\n");
		}
	}
	return 0;
}