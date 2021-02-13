#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

#define PI 3.14159265358979f

long double a;

#ifdef NOT_PRECISE

int main() {
	cin >> a;
	long double x = sqrt((sqrt(4 * a * a * a * a) - 1) / (2 * a * a));
	long double y = sqrt(a * a - x * x);
	long double A = atan(y / x);
	long double B = PI / 2. - A;
	long double S1 = 0.5 * a * a * sin(B) + 0.5 * x * y;
	long double S2 = a * x * x * x / 3.;
	long double S = 2 * (S1 - S2);
	cout << S << endl;
	return 0;
}

#else

int main() {
	return 0;
}

#endif