#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void r(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

int a[5][5];
int G1, G2, st[100000];

void print(int x[][5]) {
	puts("------\nPRINT\n------");
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			printf("%d", x[i][j]);
		}
		puts("");
	}
	puts("------\nEND PRINT\n------");
}

int trans(int x[][5]) {
	int ret = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			ret = (ret << 1) | x[i][j];
		}
	}
	return ret;
}

int g1[5][5], g2[5][5];
bool vis[5][5];

void dfs(int x[][5], int cnt) {
	int sta = trans(x);
	if (st[sta] <= cnt) {
		return;
	}
	st[sta] = cnt;
	// printf("CURRENTLY AT -> cnt = %d\n", cnt);
	// print(x);
	if (sta == G1 || sta == G2) {
		return;
	}
	int t[5][5];
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			t[i][j] = x[i][j];
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (!vis[i][j]) {
				t[i][j] ^= 1;
				if (i - 1 >= 1) t[i - 1][j] ^= 1;
				if (i + 1 <= 4) t[i + 1][j] ^= 1;
				if (j - 1 >= 1) t[i][j - 1] ^= 1;
				if (j + 1 <= 4) t[i][j + 1] ^= 1;

				vis[i][j] = true;
				dfs(t, cnt + 1);
				vis[i][j] = false;

				t[i][j] ^= 1;
				if (i - 1 >= 1) t[i - 1][j] ^= 1;
				if (i + 1 <= 4) t[i + 1][j] ^= 1;
				if (j - 1 >= 1) t[i][j - 1] ^= 1;
				if (j + 1 <= 4) t[i][j + 1] ^= 1;
			}
		}
	}
}

int main() {
	memset(st, 0x7f7f7f7f, sizeof st);
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			g1[i][j] = 0;
			g2[i][j] = 1;
		}
	}
	G1 = trans(g1);
	G2 = trans(g2);
	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 4; j++) {
			if (str[j] == 'b') {
				a[i][j + 1] = 1;
			} else {
				a[i][j + 1] = 0;
			}
		}
	}
	// print(a);
	// printf("G1 = %d, G2 = %d\n", G1, G2);
	dfs(a, 0);
	int ans  = min(st[G1], st[G2]);
	if (ans >= 0x7f7f7f7f) puts("Impossible");
	else printf("%d\n", ans);
	return 0;
}