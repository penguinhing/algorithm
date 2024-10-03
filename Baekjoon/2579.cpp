#include <bits/stdc++.h>

using namespace std;
int N, a;
int arr[303], dp[303][2];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> arr[i];
	dp[1][0] = arr[1];
	for(int i = 2; i <= N; ++i) {
		dp[i][0] = max(dp[i-2][0] + arr[i], dp[i-2][1] + arr[i]);
		dp[i][1] = dp[i-1][0] + arr[i];
	}
	cout << max(dp[N][0], dp[N][1]);
}
