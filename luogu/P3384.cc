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

#define  N 300000 + 5
#define INF 0x7f7f7f7f

int n, m, R, P;
int hd[N], nxt[N], to[N], w[N], edge, tot;
int siz[N], dep[N], u_son[N], fa[N], top[N], tr[N], dtr[N];

namespace segtree {

int TR[4 * N], FL[4 * N];

void up(int p) {
	TR[p] = TR[p << 1] + TR[p << 1 | 1];
}

void down(int l, int r, int p) {
	if (FL[p]) {
		int mid = (l + r) / 2;
		TR[p << 1] += (mid - l + 1) * FL[p];
		TR[p << 1 | 1] += (r - mid) * FL[p];
		FL[p << 1] += FL[p];
		FL[p << 1 | 1] += FL[p];
		FL[p] = 0;
	}
}

void build(int l, int r, int p) {
	if (l == r) {
		TR[p] = w[dtr[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid , p << 1);
	build(mid + 1, r, p << 1 | 1);
	up(p);
}

void add(int l, int r, int L, int R, int val, int p) {
	if (l > R || r < L) return;
	if (L <= l && r <= R) {
		TR[p] += (l - r + 1) * val;
		FL[p] = val;
		return;
	}
	int mid = (l + r) / 2;
	add(l, mid, L, R, val, p << 1);
	add(mid + 1, r, L, R, val, p << 1 | 1);
	up(p);
}

int ask_sum(int l, int r, int L, int R, int p) {
	if (l > R || r < L) return 0;
	if (L <= l && r <= R) {
		return TR[p];
	}
	int mid = (l + r) / 2;
	down(l, r, p);
	int ret = ask_sum(l, mid, L, R, p << 1) + \
	          ask_sum(mid + 1, r, L, R, p << 1 | 1);
	return ret;
}

}

namespace HLD {

void add(int a, int b) {
	nxt[++edge] = hd[a], to[hd[a] = edge] = b;
	nxt[++edge] = hd[b], to[hd[b] = edge] = a;
}

void dfs1(int u, int __fa, int __dep) {
	fa[u] = __fa;
	dep[u] = __dep;
	siz[u] = 1;
	for (int c = hd[u]; c; c = nxt[c]) {
		int v = to[c];
		if (v != __fa) {
			dfs1(v, u, __dep + 1);
			siz[u] += siz[v];
			if (!u_son[u] || siz[v] > siz[u_son[u]]) u_son[u] = v;
		}
	}
}

void dfs2(int u, int id) {
	top[u] = id;
	tr[u] = ++tot;
	dtr[tot] = u;
	if (!u_son[u]) return;
	dfs2(u_son[u], id);
	for (int c = hd[u]; c; c = nxt[c]) {
		int v = to[c];
		if (v != u_son[u] && v != fa[u]) dfs2(v, v);
	}
}

}

int main() {
	return 0;
}