#include <bits/stdc++.h>

using namespace std;
int N, M, hap = 0, lo, hi, mid, result = INT_MAX;
int arr[100004];

int check(int mid) {
	int money = 0;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (arr[i] > mid) return 0;
		if (money - arr[i] < 0) {
			money = mid; ++cnt;
		}
		money -= arr[i];
	}
	return cnt <= M;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i]; hap += arr[i];
	}
	lo = 1; hi = hap;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			result = min(result, mid);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << result;
}
