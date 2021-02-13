#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[100], t;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> t;
	int L = 1, R = n;
	while (L < R) {
		int mid = (L + R) / 2;
		printf("L %d R %d mid %d\n", L, R, mid);
		if (a[mid] < t) L = mid + 1;
		else R = mid;
	}
	printf("%d\n", R);
	return 0;
}