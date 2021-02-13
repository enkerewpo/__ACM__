#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

// #define DEBUG
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

#define M 100 + 5
#define N 1000 + 5
#define inf 0x3f3f3f3f

int m, n;
int c[M][M] = { 0 };
int d[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int a[M][M];

bool good(int x, int y) {
	if (x >= 1 && x <= m && y >= 1 && y <= m) return 1;
	else return 0;
}

int ans = inf;

void dfs(int x, int y, int mg, int cnt) {
#ifdef DEBUG
	puts("---------------------------------");
	printf("at (%d, %d) m[%d], cnt[%d]\n", x, y, mg, cnt);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", vis[i][j]);
		}
		puts("");
	}
#endif
	if (cnt >= a[x][y]) return;
	a[x][y] = cnt;
	if (x == m && y == m) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		if (good(nx, ny)) {
			if (c[nx][ny]) {
				if (c[nx][ny] == (mg ? mg : c[x][y])) {
					dfs(nx, ny, 0, cnt);
				} else {
					dfs(nx, ny, 0, cnt + 1);
				}
			} else {
				if (mg) continue;
				int t1 = c[x][y] == 1 ? 2 : 3;
				int t2 = c[x][y] == 2 ? 2 : 3;
				dfs(nx, ny, 1, cnt + t1);
				dfs(nx, ny, 2, cnt + t2);
			}
		}
	}
}

// #define FILE

int main() {
#ifdef FILE
	freopen("P3956_10.in", "r", stdin);
#endif
	read(m), read(n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x, y, _c;
		read(x), read(y), read(_c);
		c[x][y] = _c == 0 ? 1 : 2;
	}

#ifdef DEBUG
	puts("-----------------");
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", c[i][j]);
		}
		puts("");
	}
	puts("-----------------");
#endif

	dfs(1, 1, 0, 0);
	printf("%d\n", ans == inf ? -1 : ans);
	return 0;
}

/*

5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

8
 */