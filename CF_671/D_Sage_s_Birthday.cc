/**
 * @contest	Codeforces Round #671(Div.2)
 * @problem	D. Sage's Birthday
 * @Author	Kvar_ispw17
 * @Date	2020.10.6
 *
 */

#include <bits/stdc++.h>
const int N = 1e5 + 10;

using namespace std;

int n, a[N], b[N], c[N];
int _n;

vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if(n % 2 == 0) v.push_back(a[n / 2]);
	for(int i = 1; i <= (n - 1) / 2; i++) {
		v.push_back(a[n / 2 + i]);
		v.push_back(a[i]);
	}
	int ans = 0;
	v.push_back(a[n]);
	for(int i = 1; i < v.size() - 1; i++) {
		if(v[i - 1] > v[i] && v[i] < v[i + 1]) ans++;
	}
	printf("%d\n", ans);
	for(auto x : v) printf("%d ", x);
	return 0;
}