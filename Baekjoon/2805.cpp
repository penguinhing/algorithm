#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;
ll arr[1000004], mid, lo = 1, hi = 1000000000, result = 0;

bool check(ll mid) {
	ll hap = 0;
	for(int i = 1; i <= N; ++i) {
		hap += max((ll)0, (ll)arr[i] - mid);
	}
	return hap >= M;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			lo = mid + 1;
			result = mid;
		} else hi = mid - 1;
	}
	cout << result;
}
