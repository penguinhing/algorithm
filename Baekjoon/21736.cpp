#include <bits/stdc++.h>

using namespace std;
int N, M, visited[604][604], dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 }, ny, nx, result = 0;
char field[604][604];
queue<pair<int, int>> q;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> field[i][j];
			if (field[i][j] == 'I') {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> pos = q.front(); q.pop();
		if (field[pos.first][pos.second] == 'P') {
			++result;
		}
		for (int i = 0; i < 4; ++i) {
			ny = pos.first + dy[i];
			nx = pos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1 || field[ny][nx] == 'X') continue;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}
	if(result != 0) cout << result;
	else cout << "TT";
}
