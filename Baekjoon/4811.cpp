#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N, dp[31][31];

ll go(ll one, ll half) {
	if(dp[one][half] != -1) return dp[one][half];
	if(one == 0 && half == 0) return 1;
	ll hap = 0;
	if(one > 0) hap += go(one - 1, half + 1);
	if(half > 0) hap += go(one, half - 1);
	dp[one][half] = hap;
	return hap;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	fill(&dp[0][0], &dp[30][31], -1);
	while(true) {
		cin >> N;
		if(N == 0) break;
		cout << go(N, 0) << "\n";
	}	
}
