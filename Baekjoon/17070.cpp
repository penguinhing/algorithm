#include <bits/stdc++.h>

using namespace std;
int N, ny, nx, result = 0;
int field[20][20];
int dp[20][20][4];
int visited[20][20];
int dy[] = { 0, -1, -1 };
int dx[] = { -1, 0, -1 };

void go(int size) {
	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			if (field[i][j] == 1 || visited[i][j] == 1) continue;
			visited[i][j] = 1;
			for (int d = 0; d < 3; ++d) {
				ny = dy[d] + i;
				nx = dx[d] + j;
				if (ny <= 0 || nx <= 0 || ny > size || nx > size || field[ny][nx] == 1) continue;
				if (d == 2 && (field[ny][nx + 1] == 1 || field[ny + 1][nx] == 1)) continue;
				if (d == 0) dp[i][j][d] += dp[ny][nx][2];
				if (d == 1) dp[i][j][d] += dp[ny][nx][2];
				if (d == 2) {
					dp[i][j][d] += dp[ny][nx][0];
					dp[i][j][d] += dp[ny][nx][1];
				}
				dp[i][j][d] += dp[ny][nx][d];
			}
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	dp[1][2][0] = 1;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> field[i][j];
	}
	for (int i = 3; i <= N; ++i) go(i);
	for (int i = 0; i < 3; ++i) result += dp[N][N][i];
	cout << result;
}
