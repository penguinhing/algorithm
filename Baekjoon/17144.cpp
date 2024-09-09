#include <bits/stdc++.h>

using namespace std;
int R, C, T, ny, nx, y, x, result = 0;
int field[55][55];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<pair<int, int>> pos;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> R >> C >> T;
	
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cin >> field[i][j];
			if(field[i][j] == -1) pos.push_back({i, j});
		}
	}
	int boundary[] = {0, R-1}; 
	int offset[] = {-1, 1, 1, -1};
	int inc[] = {-1, 1, 1, -1};
	for(int _ = 0; _ < T; ++_) {
		int visited[55][55] = { 0 };
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(field[i][j] <= 4) continue;
				int value = 0;
				for(int d = 0; d < 4; ++d) {
					ny = i + dy[d];
					nx = j + dx[d];
					if(ny >= R || nx >= C || ny < 0 || nx < 0 || field[ny][nx] == -1) continue;
					visited[ny][nx] += field[i][j] / 5; ++value;
				}
				field[i][j] = field[i][j] - (field[i][j] / 5) * value;
			}
		}
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				field[i][j] += visited[i][j];
			}
		}
		
		for(int i = 0; i < pos.size(); ++i) {
			int visited[55][55] = { 0 };
			y = pos[i].first; x = pos[i].second;
			
			for(int j = x+1; j < C; ++j) {
				if(j + 1 >= C) {
					visited[y + offset[i]][j] = field[y][j];
				}
				else visited[y][j+1] = field[y][j];
				field[y][j] = 0;
			}
			
			for(int j = y + inc[i]; j != boundary[i] + inc[i]; j += inc[i]) {
				if(j + inc[i] == boundary[i] + inc[i]) visited[j][C-2] = field[j][C-1];
				else visited[j + inc[i]][C-1] = field[j][C-1];
				field[j][C-1] = 0;
			}
			
			y = boundary[i];
			for(int j = C-2; j >= 0; --j) {
				if(j - 1 < 0) visited[y + offset[2 + i]][j] = field[y][j];
				else visited[y][j-1] = field[y][j];
				field[y][j] = 0;
			}
			
			for(int j = boundary[i] + inc[2 + i]; j != pos[i].first + inc[2 + i]; j += inc[2 + i]) {
				if(field[j][0] == -1) continue;
				visited[j + inc[2 + i]][0] = field[j][0];
				field[j][0] = 0;
			}
			
			for(int i = 0; i < R; ++i) {
				for(int j = 0; j < C; ++j) {
					if(visited[i][j] && field[i][j] != -1) field[i][j] = visited[i][j];
				}
			}
		}
	}
	
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			if (field[i][j] != -1) result += field[i][j];
		}
	}
	cout << result;
}
