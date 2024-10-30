#include <bits/stdc++.h>

using namespace std;
long long N, dp[1000004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	dp[1] = 1; dp[2] = 2;
	for(int i = 3; i <= N; ++i) dp[i] = (dp[i - 1] % 15746) + (dp[i - 2] % 15746);
	cout << dp[N] % 15746;
}
