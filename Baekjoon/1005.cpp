#include <bits/stdc++.h>

using namespace std;

int T, N, K, a, b, F, cost[1004], ret, dp[1004], visited[1004];
vector<int> v[1004];

int dfs(int here) {
	visited[here] = 1;
	if(v[here].empty()) return dp[here] = cost[here];
	for(int i = 0; i < v[here].size(); ++i) {
		if(visited[v[here][i]] == 0) dfs(v[here][i]);
		dp[here] = max(dp[here], dp[v[here][i]]);
	}
	return dp[here] += cost[here];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	while(T--) {
		ret = 0;
		cin >> N >> K;
		for(int i = 1; i <= N; ++i) cin >> cost[i];
		for(int i = 0; i < K; ++i) {
			cin >> a >> b;
			v[b].push_back(a);
		}
		cin >> F;
		cout << dfs(F) << "\n";
		memset(visited, 0, (N + 1) * 4);
		memset(cost, 0, (N + 1) * 4);
		memset(dp, 0, (N + 1) * 4);
		for(int i = 1; i <= N; ++i) v[i].clear();
	}
}
