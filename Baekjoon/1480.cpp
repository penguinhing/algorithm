#include <bits/stdc++.h>

using namespace std;
int N, M, C, item[15], result = 0;
int dp[15][10000];
set<int> st[15];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> C;
	for(int i = 0; i < N; ++i) cin >> item[i];
	st[0].insert(0);
	for(int k = 1; k <= M; ++k) {
		for(auto it : st[k - 1]) {
			for(int i = it + 1; i < (1 << N); ++i) {	 
				if ((it & i) != it) continue;
				int got = 0, cnt = 0;
				for(int j = 0; j < N; ++j) {
					if(it & (1 << j)) continue;
					if(i & (1 << j)) {
						got += item[j];
						++cnt;
					}
				}
				if(got > C) continue;
				dp[k][i] = dp[k - 1][it] + cnt;
				st[k].insert(i);
				result = max(result, dp[k][i]);		
			}	
		}
	}
	cout << result;
}
