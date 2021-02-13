#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m;
int IN[N];
int hd[N], nxt[M], to[M], tot;

void add(int a, int b) {
	nxt[++tot] = hd[a];
	to[hd[a] = tot] = b;
	IN[b]++;
}

int q[N], HD = 0, TL = -1;
int dp[N];

void toposort() {
	for (int i = 1; i <= n; i++) {
		if (IN[i] == 0) {
			q[++TL] = i;
			dp[i] = 1;
		}
	}
	while (HD <= TL) {
		int u = q[HD++];
		for (int e = hd[u]; e; e = nxt[e]) {
			int v = to[e];
			if (--IN[v] == 0) {
				q[++TL] = v;
				dp[v] = max(dp[v], dp[u] + 1);
			}
		}
	}
}

// #define FILE
int main() {
#ifdef FILE
	freopen("P1137.in", "r", stdin);
#endif
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		read(a), read(b);
		add(a, b);
	}
	toposort();
	// for(int i = 0; i <= TL; i++) printf("%d ", q[i]);
	for(int i = 1; i <= n; i++) {
		printf("%d\n", dp[i]);
	}
	return 0;
}

/*

5 6
1 2
1 3
2 3
2 4
3 4
2 5

 */