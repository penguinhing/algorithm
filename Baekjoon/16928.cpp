#include <bits/stdc++.h>

using namespace std;
int N, M, warp[104], va, vb, visited[104];

int bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == 100) return visited[100];
		for (int i = 1; i <= 6; ++i) {
			if (v + i > 100 || visited[v + i] != -1) continue;
			if (warp[v + i]) {
				if (visited[warp[v + i]] != -1) continue;
				q.push(warp[v + i]);
				visited[warp[v + i]] = visited[v] + 1;
			}
			else {
				q.push(v + i);
				visited[v + i] = visited[v] + 1;
			}
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	memset(visited, -1, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < N + M; ++i) {
		cin >> va >> vb;
		warp[va] = vb;
	}
	cout << bfs();
}
