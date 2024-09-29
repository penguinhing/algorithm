#include <bits/stdc++.h>

using namespace std;
int N;
unsigned long long dp[1004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= N; ++i) {
		dp[i] = (dp[i-1] % 10007) + (dp[i-2] % 10007);
	}
	cout << (dp[N] % 10007);
}
