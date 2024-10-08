#include <bits/stdc++.h>

using namespace std;
int N, K, a, b, result = 0;
int dp[100004];
set<int> visited[100004];
vector<pair<int, int>> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	for(int i = 1; i <= K; ++i) {
		int mx = 103;
		set<int> before;
		for(int j = 0; j < v.size(); ++j) {
			if(i - v[j].first < 0) continue;
			if(visited[i - v[j].first].find(j) != visited[i - v[j].first].end()) continue;
			if(dp[i] < dp[i - v[j].first] + v[j].second) {
				mx = j;
				before = visited[i - v[j].first];
				dp[i] = dp[i - v[j].first] + v[j].second;
				result = max(dp[i], result);
			}
		}
		before.insert(mx);
		visited[i] = before;
	}
	cout << result;
}
