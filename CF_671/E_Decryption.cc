/**
 * @contest	Codeforces Round #671(Div.2)
 * @problem E. Decryption
 * @Author	Kvar_ispw17
 * @Date	2020.10.8
 *
 */


#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>

using namespace std;
typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

#ifdef __A

#define DEBUG

int P[N], tot;
bool iP[N];

void __sieve(int n) {
	memset(iP, 1, sizeof iP);
	for (int i = 2; i <= n; i++) {
		if (iP[i]) P[++tot] = i;
		for (int j = 1; j <= tot && P[j] * i <= n; j++) {
			int k = P[j] * i;
			iP[k] = 0;
			if (i % P[j] == 0) break;
		}
	}
}

int T, n, a[N], b[N], sT = 0;

int main() {
	__sieve(1e5 + 10);
	read(T);
	while (T--) {
		read(n);
		int _n = n;
		for (int i = 1; i <= tot; i++) {
			if (_n % P[i] == 0) {
				b[++sT] = i;
				while (_n % P[i] == 0) {
					a[sT]++;
					_n /= P[i];
				}
			}
		}
#ifdef DEBUG
		for (int i = 1; i <= sT; i++) {
			printf("DEBUG: %d : %d\n", P[b[i]], a[i]);
		}
#endif
	}
	return 0;
}

#endif

bool _p(int x) {
	if (x == 2 || x == 3) return true;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int T;
	read(T);
	while (T -- > 0) {
		int n;
		read(n);
		vector<int> d;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				d.emplace_back(i);
				d.emplace_back(n / i);
			}
		}
		d.emplace_back(n);
		sort(d.begin(), d.end());
		d.resize(unique(d.begin(), d.end()) - d.begin());
		if (d.size() == 3 && _p(d[0]) && _p(d[1])) {
			for (auto x : d) cout << x << ' ';
			cout << endl << 1 << endl;
			continue;
		}
		unordered_map<int, bool> used;
		vector<int> p;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				p.emplace_back(i);
				while (n % i == 0) n /= i;
			}
		}
		if (n > 1) p.emplace_back(n);
		vector<int> connect(p.size());
		for (int i = 0; i < (int)p.size(); i++) {
			int __p = p[i], q = p[(i + 1) % p.size()];
			for (int j = 0; j < (int)d.size(); j++) {
				if (!used[d[j]] && d[j] % __p == 0 && d[j] % q == 0) {
					used[d[j]] = true;
					connect[i] = d[j];
					break;
				}
			}
		}
		for (int i = 0; i < (int)p.size(); i++) {
			int __p = p[i];
			used[__p] = true;
			cout << __p << ' ';
			for (int j = 0; j < (int)d.size(); j++) {
				if (!used[d[j]] && d[j] % __p == 0) {
					used[d[j]] = true;
					cout << d[j] << ' ';
				}
			}
			if (p.size() > 1) cout << connect[i] << ' ';
		}
		cout << endl << 0 << endl;
	}
	return 0;
}