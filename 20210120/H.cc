#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename _Tp>
void r(_Tp &a, char c = 0) {
	for (c = getchar(); !isdigit(c); c = getchar());
	for (a = 0; isdigit(c); a = a * 10 + c - '0', c = getchar());
}

const int _N_ = 1000 + 5;
const int _D_ = 2000 + 5;

int a[_N_], b[_N_];
int M, N, K, L, D;

class data {
  public:
	int id, cnt;
	data() {
		id = cnt = -1;
	}
	data(int _id, int _cnt) {
		id = _id, cnt = _cnt;
	}
	bool operator < (const data o) const {
		return cnt > o.cnt;
	}
};

data A[_N_], B[_N_];

int main() {
	r(M), r(N), r(K), r(L), r(D);
	for (int i = 1; i <= D; i++) {
		int x1, y1, x2, y2;
		r(x1), r(y1), r(x2), r(y2);
		if (y1 == y2) {
			int x = min(x1, x2);
			a[x]++;
		}
		if (x1 == x2) {
			int y = min(y1, y2);
			b[y]++;
		}
	}
	int tot_A = 0, tot_B = 0;
	for (int i = 1; i < M; i++) {
		if (a[i]) {
			A[++tot_A] = data(i, a[i]);
		}
	}
	for (int i = 1; i < N; i++) {
		if (b[i]) {
			B[++tot_B] = data(i, b[i]);
		}
	}
	sort(A + 1, A + tot_A + 1);
	sort(B + 1, B + tot_B + 1);
	vector<int> v, _v;
	vector<int>::iterator it;
	for (int i = 1; i <= K; i++) {
		v.push_back(A[i].id);
	}
	sort(v.begin(), v.end());
	for (it = v.begin(); it != v.end(); it++) {
		int x = *it;
		printf("%d ", x);
	}
	puts("");
	for (int i = 1; i <= L; i++) {
		_v.push_back(B[i].id);
	}
	sort(_v.begin(), _v.end());
	for (it = _v.begin(); it != _v.end(); it++) {
		int x = *it;
		printf("%d ", x);
	}
	puts("");
	return 0;
}