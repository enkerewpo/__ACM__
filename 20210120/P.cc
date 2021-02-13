#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// #define DEBUG

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1000 + 5;
int T, n, m;

class data {
  public:
	int a, b;
	data(int _a = 0, int _b = 0) {
		a = _a, b = _b;
	}
	bool operator < (const data o) const {
		return b < o.b;
	}
};

int A[N], B[N];
queue<int> color[N];
data C[N];

void init() {
	for (int i = 0; i < N - 1; i++) {
		while (!color[i].empty()) {
			color[i].pop();
		}
	}
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	memset(C, 0, sizeof C);
}

int main() {
	read(T);
	while (T--) {
		init();
		read(n), read(m);
		for (int i = 1; i <= n; i++) read(A[i]);
		for (int i = 1; i <= n; i++) {
			read(B[i]);
			color[B[i]].push(i);
#ifdef DEBUG
			printf("color[%d] <- %d\n", B[i], i);
#endif
		}
		int f0 = 1;
		for (int i = 1; i <= n; i++) {
			data t;
			t.a = A[i];
			if (color[A[i]].empty()) {
				f0 = 0;
				break;
			}
			int pos = color[A[i]].front();
			color[A[i]].pop();
			t.b = pos;
			C[i] = t;
		}
#ifdef DEBUG
		if (!f0) {
			puts("NOT EQUAL!");
			goto ed;
		}
		for (int i = 1; i <= n; i++) {
			printf("C[%d] { %d, %d }\n", i, C[i].a, C[i].b);
		}
ed:;
#endif
		for (int i = 1; i <= m; i++) {
			int L, R;
			read(L), read(R);
			sort(C + L, C + R + 1);
		}
		if (!f0) {
			puts("No");
			continue;
		}
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			if (C[i].a != B[i]) {
				f = 0;
				break;
			}
		}
		if (f) puts("Yes");
		else puts("No");
	}
	return 0;
}