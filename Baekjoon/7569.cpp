#include <bits/stdc++.h>

using namespace std;

struct Pos {
	int h;
	int y;
	int x;
};


int N, M, H, ny, nx, nh, result = 0;
int field[104][104][104], visited[104][104][104];
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
queue<Pos> q;

void bfs() {
	while(!q.empty()) {
		Pos p = q.front(); q.pop();
		for(int i = 0; i < 6; ++i) {
			ny = dy[i] + p.y;
			nx = dx[i] + p.x;
			nh = dh[i] + p.h;
			if(ny < 0 || nx < 0 || ny >= N || nx >= M || nh < 0 || nh >= H || 
			visited[nh][ny][nx] == 1 || field[nh][ny][nx] != 0) continue;
			field[nh][ny][nx] = 1;
			visited[nh][ny][nx] = visited[p.h][p.y][p.x] + 1;
			result = max(visited[nh][ny][nx], result);
			Pos tp = {nh, ny, nx};
			q.push(tp);
		}
		
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> M >> N >> H;
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < M; ++k) {
				cin >> field[i][j][k];
				if(field[i][j][k] == 1) {
					Pos p = {i, j, k};
					visited[i][j][k] = 1;
					q.push(p);
				}
			}
		}
	}
	bfs();
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < M; ++k) {
				if(field[i][j][k] == 0) {
					cout << -1; return 0;
				}
			}
		}
	}
	if(result == 0) cout << 0;
	else cout << result - 1;
}
