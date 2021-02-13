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

int main() {
	return 0;
}