#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N, dp[50002];

ll go(int value) {
	if(dp[value]) return dp[value];
	ll ret = LLONG_MAX;
	for(ll i = 1; i * i <= value; ++i) {
		if(i * i == value) {
			dp[value] = 1;
			return 1;
		}
		ret = min(ret, go(value - i * i) + 1);
	}
	dp[value] = ret;
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 1; i <= N; ++i) go(i);
	cout << dp[N];
}
