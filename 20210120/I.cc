#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void r(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

class date {
  public:
	int y, m, d;
	date(string s) {
		int _y = atoi(s.substr(0, 4).c_str());
		int _m = atoi(s.substr(4, 2).c_str());
		int _d = atoi(s.substr(6, 2).c_str());
		y = _y, m = _m, d = _d;
	}
	bool operator == (const date A) const {
		return A.y == y && A.m == m && A.d == d;
	}
	void print() {
		printf("YEAR=%d MONTH=%d DAY=%d\n", y, m, d);
	}
	string sprint() {
		char s[10];
		sprintf(s, "%d%02d%02d\n", y, m, d);
		string str = s;
		return str;
	}
	void update() {
		if (m == 1 ||
		        m == 3 ||
		        m == 5 ||
		        m == 7 ||
		        m == 8 ||
		        m == 10
		   ) {
			if (d == 31) {
				d = 1;
				m++;
			} else {
				d++;
			}
		} else if (m == 12) {
			if (d == 31) {
				d  = 1;
				m = 1;
				y++;
			} else {
				d++;
			}
		} else if (m == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
				if (d == 29) {
					d = 1;
					m++;
				} else {
					d++;
				}
			} else {
				if (d == 28) {
					d = 1;
					m++;
				} else {
					d++;
				}
			}
		} else {
			if (d == 30) {
				d = 1;
				m++;
			} else {
				d++;
			}
		}
	}
};

string A, B;

bool good(string str) {
	// printf("\t---COMPARING");
	int len = 8;
	for (int i = 0; i < len / 2 + 1; i++) {
		int j = len - i - 1;
		// printf(" j = %d   %c <-> %c  \n", j, str[i], str[j]);
		if (str[i] != str[j]) return false;
	}
	return true;
}

int main() {
	cin >> A >> B;
	date a(A), b(B);
	b.update();
	int cnt = 0;
	for (date t = a; !(t == b); t.update()) {
		// printf("NOW AT DATE -> ");
		// cout << t.sprint();
		if (good(t.sprint())) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}