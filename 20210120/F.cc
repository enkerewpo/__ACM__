#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

string s[2500];
int n;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i < n; i++) {
		string a = s[i];
		string b = s[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i];
	}
	puts("");
	return 0;
}