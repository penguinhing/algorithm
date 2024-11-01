#include <bits/stdc++.h>

using namespace std;
int N, a, b, ny, nx, visited[104][104];
char field[104][104];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x, char k) {
	queue<pair<int, int>> q;
	q.push({y, x});
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i  < 4; ++i) {
			ny = dy[i] + p.first;
			nx = dx[i] + p.second;
			if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] || field[ny][nx] != k) continue;
			q.push({ny, nx});
			visited[ny][nx] = 1;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) cin >> field[i][j];
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(visited[i][j]) continue;
			bfs(i, j, field[i][j]);
			++a;
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			visited[i][j] = 0;
			if(field[i][j] == 'G') field[i][j] = 'R';
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(visited[i][j]) continue;
			bfs(i, j, field[i][j]);
			++b;
		}
	}
	cout << a << " " << b;
}
