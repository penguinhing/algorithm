#include <bits/stdc++.h>

using namespace std;
string S;
bool dp[2504][2504];
int dp2[2504];

int go(int here) {
	if(here == S.length()) return 0;
	if(dp2[here] != -1) return dp2[here];
	int ret = INT_MAX;
	for(int i = 1; i <= S.length() - here; ++i) {
		if(dp[here][i]) {
			ret = min(ret, go(here + i) + 1);
		}
	}
	dp2[here] = ret;
	return dp2[here];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> S;
	for(int i = 0; i < S.length(); ++i) dp[i][1] = true;
	for(int i = 0; i < S.length() - 1; ++i) {
		if(S[i] == S[i + 1]) dp[i][2] = true;
	}
	for(int size = 3; size <= S.length(); ++size) {
		for(int i = 0; i <= S.length() - size; ++i) {
			if(S[i] == S[i + size - 1] && dp[i + 1][size - 2]) dp[i][size] = true;
		}
	}
	memset(dp2, -1, sizeof(dp2));
	cout << go(0);
}
