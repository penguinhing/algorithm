#include <bits/stdc++.h>

using namespace std;
int N, M;
int x1, yy1, x2, y2;
char field[304][304];
int visited[304][304];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> tmp;
	q.push({yy1, x1});
	visited[yy1][x1] = 1;
	int ny, nx;
	while(!q.empty()) {
		pair<int, int> pos = q.front(); q.pop();
		
		for(int i = 0; i < 4; ++i) {
			ny = dy[i] + pos.first;
			nx = dx[i] + pos.second;
			if(ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
			if(visited[ny][nx]) continue;
			if(ny == y2 && nx == x2) return visited[pos.first][pos.second];
			if(field[ny][nx] == '0') {
				tmp.push({ny, nx});
				visited[ny][nx] = visited[pos.first][pos.second];
			}
			else {
				q.push({ny, nx});
				visited[ny][nx] = visited[pos.first][pos.second] + 1;
			}
		}
		
		while(!tmp.empty()) {
			pair<int, int> _pos = tmp.front(); tmp.pop();
			for(int i = 0; i < 4; ++i) {
				ny = dy[i] + _pos.first;
				nx = dx[i] + _pos.second;
				if(ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
				if(visited[ny][nx]) continue;
				if(ny == y2 && nx == x2) return visited[_pos.first][_pos.second];
				if(field[ny][nx] == '0') {
					tmp.push({ny, nx});
					visited[ny][nx] = visited[_pos.first][_pos.second];
				}
				else {
					q.push({ny, nx});
					visited[ny][nx] = visited[pos.first][pos.second] + 1;
				}
			}	
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	cin >> yy1 >> x1 >> y2 >> x2;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin >> field[i][j];
		}
	}
	cout << bfs();
}
