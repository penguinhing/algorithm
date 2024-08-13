#include <bits/stdc++.h>

using namespace std;

int R, C, ny, nx;
int field[100][100];
int visited[100][100];
int area[2600] = { 0 };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int mxArea = INT_MIN;
int result = INT_MIN;

void bfs(int y, int x, int areaNumber) {
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = areaNumber;
	int tmp = 0;
	while(!q.empty()) {
		++area[areaNumber];
		++tmp;
		pair<int, int> pos = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			if( ((1 << i) & field[pos.first][pos.second]) == 0) {
				ny = pos.first + dy[i];
				nx = pos.second + dx[i];
				if(visited[ny][nx] != 0) continue;
				q.push({ny, nx});
				visited[ny][nx] = areaNumber;
			}
		}
	}
	mxArea = max(mxArea, tmp);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> C >> R;
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cin >> field[i][j];
		}
	}
	int areaNumber = 1;
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			if(visited[i][j] != 0) continue;
			bfs(i, j, areaNumber++);
		}
	}
	
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			
			for(int d = 0; d < 4; ++d) {
				ny = dy[d] + i;
				nx = dx[d] + j;
				if(ny < 0 || nx < 0 || ny >= R || C <= nx) continue;
				if(visited[i][j] == visited[ny][nx]) continue;
				result = max(result, area[visited[i][j]] + area[visited[ny][nx]]);
			}
		}
	}
	cout << areaNumber - 1 << "\n";
	cout << mxArea << "\n";
	cout << result;
}
