#include <bits/stdc++.h>

using namespace std;

int N, len = 0;
int arr[1004];
int cnt[1004];
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	for(int i = N -1; i >= 0; --i) {
		auto it = lower_bound(cnt, cnt + len, arr[i]);
		if(*it == 0) ++len;
		*it = arr[i];
	}
	cout << len;
}
