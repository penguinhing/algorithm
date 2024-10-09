#include <bits/stdc++.h>

using namespace std;

int N;
int adj[101][101];
int bfs(int start, int end) {
	int visited[101] = { 0 };
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		for (int i = 0; i < N; ++i) {
			if (adj[q.front()][i]) {
				if (i == end) return 1;
				if (visited[i]) continue;
				q.push(i);
				visited[i] = 1;
			}
		}
		q.pop();
	}
	return 0;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> adj[i][j];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << bfs(i, j) << " ";
		cout << "\n";
	}

}
