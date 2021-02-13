#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

#define INF 0x3f3f3f3f

class hero {
  public:
	int HP, DPS;
	hero(int _HP = -1, int _DPS = -1) {
		HP = _HP, DPS = _DPS;
	}
	bool operator < (const hero o) const {
		return HP * o.DPS < DPS * o.HP;
	}
};

hero a[25];
int n;
int sum_HP, sum_DPS;
bool vis[25];

void init() {
	sum_DPS = sum_HP = 0;
	memset(a, -1, sizeof a);
	memset(vis, 0, sizeof vis);
}


int main() {
	while (~scanf("%d", &n)) {
		init();
		int dps, hp;
		for (int i = 1; i <= n; i++) {
			read(dps), read(hp);
			a[i] = hero(hp, dps);
			sum_HP += hp;
			sum_DPS += dps;
		}
		int ans = 0;

#if 1
		sort(a + 1, a + n + 1);
		int ts = 0;
		for (int i = 1; i <= n; i++) {
			ans += a[i].HP * (sum_DPS - ts);
			ts += a[i].DPS;
		}
		printf("%d\n", ans);

#endif

#if 0

		for (int j = 1; j <= n; j++) {
			int good = -1, td = -INF;
			int tmp_s = 0;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) {
					tmp_s += a[i].DPS;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) {
					int st = a[i].HP * (tmp_s - a[i].DPS);
					if (st > td) {
						td = st;
						good = i;
					}
				}
			}
			// printf("j = %d  good = %d  td = %d\n", j, good, td);
			vis[good] = true;
			ans += td;
		}
		int oth = sum_HP * sum_DPS;
		ans = oth - ans;
		printf("%d\n", ans);

#endif

	}
	return 0;
}