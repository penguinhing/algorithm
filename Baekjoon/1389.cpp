#include <bits/stdc++.h>

using namespace std;
int N, M, a, b, result[2];
vector<int> v[101];

int bfs(int K) {
	int visited[104] = { 0 };
	visited[K] = 1;
	queue<pair<int, int>> q;
	q.push({K, 0});
	int ret = 0;
	while(!q.empty()) {
		pair<int, int> value = q.front();
		q.pop();
		ret += value.second;
		for(int i = 0; i < v[value.first].size(); ++i) {
			if(visited[v[value.first][i]]) continue;
			q.push({v[value.first][i], value.second + 1});
			visited[v[value.first][i]] = 1;
		}
	}
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	result[0] = INT_MAX;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= N; ++i) {
		int ret = bfs(i);
		if(ret < result[0]) {
			result[0] = ret;
			result[1] = i;
		}
	}
	cout << result[1];
}
