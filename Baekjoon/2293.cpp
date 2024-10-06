#include <bits/stdc++.h>

using namespace std;

int N, K, arr[104], dp[10004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	dp[0] = 1;
	for(int i = 0; i < N; ++i) {
		for(int j = 1; j <= K; ++j) {
			if (j - arr[i] < 0) continue;
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[K];	
}
