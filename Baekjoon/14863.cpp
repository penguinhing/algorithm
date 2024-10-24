#include <bits/stdc++.h>

using namespace std;
int N, K, dp[101][100001];
pair<int, int> w[101], b[101];

int go(int here, int t) {
	if(here == N) return 0;
	if(dp[here][t]) return dp[here][t];
	int ret = INT_MIN;
	if(t - w[here].first >= 0) ret = max(ret, go(here + 1, t - w[here].first) + w[here].second);
	if(t - b[here].first >= 0) ret = max(ret, go(here + 1, t - b[here].first) + b[here].second);
	dp[here][t] = ret;
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) cin >> w[i].first >> w[i].second >> b[i].first >> b[i].second;
	cout << go(0, K);
}
