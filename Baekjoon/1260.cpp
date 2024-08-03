#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1004];
int visited[1004];
int N, M, V;

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	sort(adj[v].begin(), adj[v].end());
	for(int c : adj[v]) {
		if(visited[c] == 1) continue;
		dfs(c);
	}
}

void bfs() {
	queue<int> q;
	visited[V] = 1;
	q.push(V);
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		cout << c << " ";
		for(int a : adj[c]) {
			if(visited[a] == 1) continue;
			visited[a] = 1;
			q.push(a);
		}
	}
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> V;
	int a, b;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(V);
	for(int i = 1; i <= N; ++i) visited[i] = 0;
	cout << "\n";
	bfs();
} 
