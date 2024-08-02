#include <bits/stdc++.h>

using namespace std;

int R, C, K, ny, nx;
char field[10][10];
int visited[10][10];
int result = 0;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void dfs(int startY, int startX, int depth) {
	if(depth == K) {
		if(startY == 0 && startX == C-1) ++result;
		return;
	}
	
	visited[startY][startX] = 1;
	for(int i = 0; i < 4; ++i) {
		ny = startY + dy[i];
		nx = startX + dx[i];
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if(visited[ny][nx] == 1 || field[ny][nx] == 'T') continue;
		dfs(ny, nx, depth+1);
	}
	visited[startY][startX] = 0;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> R >> C >> K;
	
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cin >> field[i][j];
		}
	}
	dfs(R-1, 0, 1);
	cout << result;
}
