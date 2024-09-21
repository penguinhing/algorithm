#include <bits/stdc++.h>

using namespace std;
int N, M, hap = 0, lo, hi, mid, result = INT_MAX;
int arr[100004];

bool check(int mid) {
	int tmp = 0;
	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if(arr[i] > mid) return false;
		if(tmp + arr[i] > mid) tmp = 0;
		if(tmp == 0) ++cnt;
		tmp += arr[i];
	}
	return M >= cnt;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
		hap += arr[i];
	}
	lo = 1; hi = hap;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			result = min(result, mid);
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << result;
}
