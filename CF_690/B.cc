#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		string s;
		cin >> s;
		bool f[5] = {0, 0, 0, 0, 0};
		string a = s.substr(0, 2);
		string b = s.substr(s.length() - 2, 2);
		if (a == "20" && b == "20") f[0] = 1;
		a = s.substr(0, 1);
		b = s.substr(s.length() - 3, 3);
		if (a == "2" && b == "020") f[1] = 1;
		b = s.substr(s.length() - 4, 4);
		if (b == "2020") f[2] = 1;
		a = s.substr(0, 3);
		b = s.substr(s.length() - 1, 1);
		if (a == "202" && b == "0") f[3] = 1;
		a = s.substr(0, 4);
		if (a == "2020") f[4] = 1;
		bool x = f[0] | f[1] | f[2] | f[3] | f[4];
		if (x) puts("YES");
		else puts("NO");
	}
	return 0;
}