#include <bits/stdc++.h>

using namespace std;
int N;
int dp[1000004];
int history[1000004];

int go(int x) {
	if(x == 1) return 0;
	if(dp[x] != 0) return dp[x];
	int value = go(x - 1) + 1;
	if(x % 3 == 0) value = min(value, go(x / 3) + 1);
	if (x % 2 == 0) value = min(value , go(x / 2) + 1);
	dp[x] = value;
	
	if (dp[x - 1] == dp[x] - 1) history[x] = x - 1;
	else if (x % 3 == 0 && dp[x / 3] == dp[x] - 1) history[x] = x / 3;
	else history[x] = x / 2;
	
	return dp[x];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	dp[2] = 1; dp[3] = 1;
	cin >> N;
	if(N == 1) {
		cout << "0\n1"; return 0;
	}
	for(int i = 1; i <= N; ++i) go(i);
	cout << dp[N] << "\n";
	int x = N;
	while(true) {
		cout << x << " ";
		x = history[x];
		if(x == 0) break;
	}
	cout << "1";
}
