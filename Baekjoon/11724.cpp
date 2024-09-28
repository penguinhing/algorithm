#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1004];
int visited[1004];
int N, M, a, b, depth = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= N; ++i) {
		if(visited[i] == 1) continue;
		++depth;
		if(adj[i].empty()) continue;
		queue<int> q;
		visited[i] = 1;
		q.push(i);
		while(!q.empty()) {
			for(int j = 0; j < adj[q.front()].size(); ++j) {
				if(visited[adj[q.front()][j]] == 1) continue;
				q.push(adj[q.front()][j]);
				visited[adj[q.front()][j]] = 1;
			}
			q.pop();
		}
	}
	cout << depth;
}
