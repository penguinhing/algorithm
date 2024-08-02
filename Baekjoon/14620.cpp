#include <bits/stdc++.h>

using namespace std;

int N, ny, nx;
int field[12][12];
int visited[12][12];
int result = INT_MAX;

int dy[] = {1, -1, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0};

void dfs(int hap, int depth) {
	if(depth > 3) {
		result = min(hap, result);
		return;
	}
	int h = 0;
	for(int i = 1; i < N-1; ++i) {
		for(int j = 1; j < N-1; ++j) {
			if(visited[i][j] == 1 || visited[i][j+1] == 1 || visited[i][j-1] == 1 ||
			visited[i+1][j] == 1 || visited[i-1][j] == 1) continue;
			for(int c = 0; c < 5; ++c) {
				ny = dy[c] + i;
				nx = dx[c] + j;
				visited[ny][nx] = 1;
				h += field[ny][nx];
			}
			dfs(hap + h, depth+1);
			h = 0;
			for(int c = 0; c < 5; ++c) {
				ny = dy[c] + i;
				nx = dx[c] + j;
				visited[ny][nx] = 0;
			}
			
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin >> field[i][j];
		}
	}
	dfs(0, 1);
	cout << result;
	
}
