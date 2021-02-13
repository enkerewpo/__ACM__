#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <queue>

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const ll N = 1e5 + 5;
const ll M = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f;

ll nxt[M], to[M], hd[N], wt[M], tot;
ll dis[N];
ll n, m, s;

void add(ll u, ll v, ll w) {
	nxt[++tot] = hd[u], to[hd[u] = tot] = v, wt[tot] = w;
}

class node {
  public:
	int p, d;
	node(int _p, int _d) { p = _p, d = _d; }
	bool operator < (const node &x) const {	return d > x.d;	}
};

bool vis[N];

inline void dijkstra() {
	priority_queue<node> q;
	q.push(node(s, 0));
	while (!q.empty()) {
		node x = q.top(); q.pop();
		int u = x.p;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int e = hd[x.p]; e; e = nxt[e]) {
			ll _w = wt[e], v = to[e];
			if (dis[u] + _w < dis[v]) {
				dis[v] = dis[u] + _w;
				if (!vis[v]) q.push(node(v, dis[v]));
			}
		}
	}
}

int main() {
	read(n), read(m), read(s);
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		read(u), read(v), read(w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) dis[i] = inf;
	dis[s] = 0;
	dijkstra();
	for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
	puts("");
	return 0;
}