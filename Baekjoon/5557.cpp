#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N, dp[104][24], arr[104];

ll dfs(ll here, ll value) {
	if(value < 0 || value > 20) return 0;
	if(dp[here][value] != -1) return dp[here][value];
	ll ret = 0;
	if(here == 1) {
		if(arr[here - 1] + arr[here] == value) ++ret;
		if (arr[here - 1] - arr[here] == value) ++ret;
		return ret;
	}
	ret += dfs(here - 1, value - arr[here]);
	ret += dfs(here - 1, value + arr[here]);
	dp[here][value] = ret;
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	cout << dfs(N - 2, arr[N - 1]);
}
