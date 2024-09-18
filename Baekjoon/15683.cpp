#include <bits/stdc++.h>

using namespace std;

int N, M, ny, nx, result = INT_MAX;
int field[10][10];
int visited[10][10] = { 0 };
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void rotate(int y, int x, int arrow, int depth) {
	while(true) {
		ny = dy[arrow] + y;
		nx = dx[arrow] + x;
		if(ny < 0 || nx < 0 || ny >= N || nx >= M || field[ny][nx] == 6) break;
		if(visited[ny][nx] == 0) visited[ny][nx] = depth;
		y = ny;
		x = nx;
	}
}

void rollback(int depth) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(visited[i][j] == depth) visited[i][j] = 0;
		}
	}
}

void dfs(int depth) {
	if(depth == v.size()) {
		int cnt = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				if(visited[i][j] == 0) ++cnt;
			}
		}
		result = min(cnt, result);
		return;
	}
	int y = v[depth].first;
	int x = v[depth].second;
	int type = field[y][x];
	int repeat[6] = {-1, 4, 2, 4, 4, 1};
	
	for(int i = 0; i < repeat[type]; ++i) {
		if(type == 1) rotate(y, x, i, depth + 10);
		else if(type == 2) {
			rotate(y, x, i, depth + 10);
			rotate(y, x, (i + 2) % 4, depth + 10);
		}
		else if(type == 3) {
			rotate(y, x, i, depth + 10);
			rotate(y, x, (i + 1) % 4, depth + 10);
		}
		else if(type == 4) {
			rotate(y, x, i, depth + 10);
			rotate(y, x, (i + 1) % 4, depth + 10);
			rotate(y, x, (i + 3) % 4, depth + 10);
		}
		else if(type == 5) {
			rotate(y, x, 0, depth + 10);
			rotate(y, x, 1, depth + 10);
			rotate(y, x, 2, depth + 10);
			rotate(y, x, 3, depth + 10);
		}
		dfs(depth + 1);
		rollback(depth + 10);
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> field[i][j];	
			if(field[i][j] != 0 && field[i][j] != 6) {
				v.push_back({i, j});
			}
			if(field[i][j] != 0) visited[i][j] = -1;
		}
	}
	dfs(0);
	cout << result;
}
