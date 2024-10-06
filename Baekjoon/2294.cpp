#include <bits/stdc++.h>
#define INF 100004
using namespace std;
int N, K, arr[104], dp[10004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for(int i = 1; i <= K; ++i) {
		int ret = INF;
		for(int j = 0; j < N; ++j) {
			if (i - arr[j] < 0 || dp[i - arr[j]] == -1) continue;
			ret = min(ret, 1 + dp[i - arr[j]]);
		}
		if(ret == INF) dp[i] = -1;
		else dp[i] = ret;
	}
	cout << dp[K];
}
