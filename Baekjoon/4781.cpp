#include <bits/stdc++.h>

using namespace std;
int N, P, a;
double M, b;
int dp[10004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	while(true) {
		cin >> N >> M;
		if(N == 0 && M == 0.00) break;
		vector<pair<int, int>> v;
		P = (int) (M * 100.0 + 0.5);
		for(int i = 0; i < N; ++i) {
			cin >> a >> b;
			v.push_back({(int) (b * 100.0 + 0.5), a});
		}
		for(int i = 1; i <= P; ++i) {
			for(pair<int, int> value : v) {
				if(i - value.first < 0) continue;
				dp[i] = max(dp[i], dp[i - value.first] + value.second);
			}
		}
		cout << dp[P] << "\n";
		memset(dp, 0, sizeof(dp));
	}
}
