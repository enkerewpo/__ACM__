#include <bits/stdc++.h>
using namespace std;

#define N 100009
int tmp[N];

void change(int arr[], int begin, int end) {
	if (begin >= end)
		return;
	int mid = (begin + end) / 2, size = 0;
	for (int i = mid + 1; i <= end; ++i)
		tmp[++size] = arr[i];
	for (int i = begin; i <= mid; ++i)
		tmp[++size] = arr[i];
	for (int i = 0; i < size; ++i)
		arr[i + begin] = tmp[i + 1];
}

void sort(int arr[], int begin, int end) {
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	sort(arr, begin, mid);
	sort(arr, mid + 1, end);
	if (arr[begin] > arr[mid + 1])
		change(arr, begin, end);
}

int n;
int a[5005];

const int X = 1000000;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 0) {
			a[i] = X;
		} else {
			a[i] = i;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}