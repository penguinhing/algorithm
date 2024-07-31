#include <bits/stdc++.h>

using namespace std;

char field[25][25];
int R, C;
int checkArr[26];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ny, nx;
int result = 0;
int visited[25][25];

void dfs(int startY, int startX, int depth) {
	int idx = field[startY][startX] - 'A';
	checkArr[idx] = 1;
	visited[startY][startX] = 1;
	for(int i = 0; i < 4; ++i) {
		ny = dy[i] + startY;
		nx = dx[i] + startX;
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if(visited[ny][nx] == 1) continue;
		if(checkArr[field[ny][nx] - 'A'] == 1) continue;
		dfs(ny, nx, depth + 1);
	}
	checkArr[idx] = 0;
	visited[startY][startX] = 0;
	result = max(result, depth);
}

int main() {
	cin >> R >> C;
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cin >> field[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << result;
}
