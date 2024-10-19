#include <bits/stdc++.h>

using namespace std;
int a, b, N, M, arr[2004], dp[2004][2004];

int check(int s, int e) {
	if (dp[s][e] >= 0) return dp[s][e];
	if (s == e) return 1;
	for (int i = 0; i < (e - s + 1) / 2; ++i) {
		if (dp[s + i][e - i] == 1) break;
		if (dp[s + i][e - i] == 0 || arr[s + i] != arr[e - i]) {
			dp[s][e] = 0;
			break;
		}
	}
	if (dp[s][e] == -1) dp[s][e] = 1;
	return dp[s][e];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << check(a, b) << "\n";
	}
}
