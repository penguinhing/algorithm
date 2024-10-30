#include <bits/stdc++.h>

using namespace std;
int N, dp[1004][3], color[1004][3];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> color[i][0] >> color[i][1] >> color[i][2];
	for(int i = 0; i < 3; ++i) dp[1][i] = color[1][i];
	for(int i = 2; i <= N; ++i) {
		for(int j = 0; j < 3; ++j) {
			dp[i][j] = INT_MAX;
			for(int x = 0; x < 3; ++x) {
				if(x == j) continue;
				dp[i][j] = min(dp[i][j],  dp[i - 1][x] + color[i][j]);
			}
		}
	}
	cout << min(dp[N][2], min(dp[N][0], dp[N][1]));
}
