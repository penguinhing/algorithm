#include <bits/stdc++.h>

using namespace std;
int N, dp[504][504];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j < i; ++j) cin >> dp[i][j];
	}
	for(int i = N - 1; i >= 1; --i) {
		for(int j = 0; j < i; ++j) dp[i][j] = max(dp[i][j] + dp[i + 1][j], dp[i][j] + dp[i + 1][j + 1]);
	}
	cout << dp[1][0];
}
