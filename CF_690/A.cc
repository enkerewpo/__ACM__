#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

typedef long long ll;

int T, n;
int a[305];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int p1 = 1, p2 = n;
		while(p1 <= p2) {
			printf("%d ", a[p1]);
			if(p2 > p1) printf("%d ", a[p2]);
			p1++, p2--;
		}
		puts("");
	}
	return 0;
}