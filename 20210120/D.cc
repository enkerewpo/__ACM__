#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

int main() {
	char c = 0;
	int a = 0;
	while (c != '-') {
		c = getchar();
		if (c == '.') {
			// printf("PRINT a = %d\n", a);
			for (int i = 7; i >= 0; i--) {
				int b = (a >> i) & 1;
				printf("%d", b);
			}
			a = 0;
			continue;
		}
		if (c == '\n') {
			for (int i = 7; i >= 0; i--) {
				int b = (a >> i) & 1;
				printf("%d", b);
			}
			a = 0;
			printf("\n");
			continue;
		}
		a = a * 10 + c - '0';
	}
	return 0;
}