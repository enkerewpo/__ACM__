#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e7 + 5;

class carpet {
  public:
	int id, a, b, x, y;
	carpet(int _id, int _a, int _b, int _x, int _y) {
		id = _id;
		a = _a;
		b = _b;
		x = _x;
		y = _y;
	}
};

vector<carpet> c;

int n;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int a, b, x, y;
		read(a), read(b), read(x), read(y);
		c.push_back(carpet(i, a, b, x, y));
	}
	int X, Y;
	read(X), read(Y);
	vector<carpet>::reverse_iterator it;
	for (it = c.rbegin(); it != c.rend(); it++) {
		carpet o = *it;
		// printf("GET %d %d %d %d\n", o.a, o.b, o.x, o.y);
		if (X >= o.a && X <= o.a + o.x && Y >= o.b && Y <= o.b + o.y) {
			printf("%d\n", o.id);
			return 0;
		}
	}
	puts("-1");
	return 0;
}