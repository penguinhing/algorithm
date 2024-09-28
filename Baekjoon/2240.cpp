#include <bits/stdc++.h>

using namespace std;
int T, W;
int result = 0;
int ti[1004];
int dp[1004][35] = { 0 };

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T >> W;
	for (int i = 1; i <= T; ++i) cin >> ti[i];
	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (j > i || j > W) break;
			if (dp[i][j] != 0) continue;
			dp[i][j] = dp[i - 1][j];
			if (((j == 0 || j % 2 == 0) && ti[i] == 1) || (j % 2 != 0 && ti[i] == 2)) {
				dp[i][j] = dp[i - 1][j] + 1;
				result = max(result, dp[i][j]);
			}
			else if (j + 1 > W || j + 1 > i) continue;
			else {
				dp[i][j + 1] = max(dp[i - 1][j + 1] + 1, dp[i - 1][j] + 1);
				result = max(result, dp[i][j+1]);
			}
		}
	}
	cout << result;
}
