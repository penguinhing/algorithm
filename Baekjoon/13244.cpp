#include <bits/stdc++.h>

using namespace std;
int N, node, E, visited[1004], a, b;
vector<int> adj[1004];

bool bfs(int startNode) {
	int count = 0;
	visited[startNode] = 1;
	queue<int> q;
	q.push(startNode);
	while (!q.empty()) {
		++count;
		for (int i : adj[q.front()]) {
			if (visited[i] == 1) continue;
			visited[i] = 1;
			q.push(i);
		}
		q.pop();
	}
	return (count == node);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> node >> E;
		for (int j = 0; j < E; ++j) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout << ((bfs(a) && E == node-1) ? "tree" : "graph") << "\n";
		for (int j = 1; j <= node; ++j) adj[j].clear();
		fill(&visited[0], &visited[1004], 0);
	}
}
