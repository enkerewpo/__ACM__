#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, h;
int c[15], tot;

bool vis[15];
bool ok = 0;
int minhp = -1;

void find(int mp, int hp, int fz, int bo) {
	if (mp < 0) return;
	// printf("find(mp=%d, hp=%d, fz=%d, bo=%d)\n", mp, hp, fz, bo);
	if (hp <= 0) {
		ok = 1;
		return;
	}
	minhp = min(minhp, hp);
	for (int i = 1; i <= tot; i++) {
		if (!vis[i]) {
			// printf("\t USING MAGIC %d -> [%d]\n", i, c[i]);
			vis[i] = 1;
			if (c[i] == 1) {
				find(mp - 2, hp - 3 - bo, 1, bo);
			}
			if (c[i] == 2) {
				if (fz) {
					find(mp - 1, hp - 4 - bo, 1, bo);
				} else {
					find(mp - 1, hp, 1, bo);
				}
			}
			if (c[i] == 3) {
				find(mp - 4, hp - 6 - bo, fz, bo);
			}
			if (c[i] == 4) {
				find(mp - 2, hp, fz, bo + 1);
			}
			if (c[i] == 5) {
				find(mp - 4, hp, fz, bo + 2);
			}
			if (c[i] == 6) {
				find(mp - 9, 15, fz, bo);
			}
			if (c[i] == 7) {
				find(mp - 2, hp - 1 - bo, fz, bo);
			}
			vis[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) {
		string card;
		cin >> card;
		if (card == "Frostbolt") c[++tot] = 1;
		if (card == "IceLance") c[++tot] = 2;
		if (card == "Fireball") c[++tot] = 3;
		if (card == "BloodmageThalnos") c[++tot] = 4;
		if (card == "CosmicAnomaly") c[++tot] = 5;
		if (card == "Alexstrasza") c[++tot] = 6;
	}
	c[++tot] = 7;
	minhp = h;
	find(m, h, 0, 0);
	if (ok) puts("Win");
	else {
		printf("Lose\n%d\n", h - minhp);
	}
	return 0;
}