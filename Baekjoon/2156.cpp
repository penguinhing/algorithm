#include <bits/stdc++.h>

using namespace std;
int dp[10004][3], result, N, mx;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> dp[i][1];
	result = dp[0][1];
	for(int i = 1; i < N; ++i) {
		dp[i][0] = max(dp[i - 1][2], max(dp[i - 1][0], dp[i - 1][1]));
		dp[i][2] = dp[i][1] + dp[i - 1][1];
		mx = 0;
		for(int j = 0; j < 3; ++j) mx = max(mx, dp[i][1] + dp[i - 2][j]);
		dp[i][1] = mx;
		for(int j = 0; j < 3; ++j) result = max(result, dp[i][j]);
	}
	cout << result;
}
