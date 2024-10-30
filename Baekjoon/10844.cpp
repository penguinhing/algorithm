#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
long long N, dp[104][10], result = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 1; i <= 9; ++i) dp[1][i] = 1;
	for(int i = 2; i <= N; ++i) {
		for(int j = 0; j <= 9; ++j) {
			if(dp[i - 1][j] == 0) continue;
			if(j + 1 < 10) dp[i][j + 1] += dp[i - 1][j] % MOD;
			if(j - 1 >= 0) dp[i][j - 1] += dp[i - 1][j] % MOD;
		}
	}
	for(int i = 0; i <= 9; ++i) result += dp[N][i] % MOD;
	cout << result % MOD;
}
