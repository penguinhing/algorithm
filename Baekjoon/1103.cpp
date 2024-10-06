#include <bits/stdc++.h>

using namespace std;
int N, M;
char field[51][51];
int visited[51][51], dp[51][51];

int dfs(int y, int x) {
	if(visited[y][x] == 1) {
		cout << -1;
		exit(0);
	}
	if(dp[y][x] != -1) return dp[y][x];
	visited[y][x] = 1;
	int value = field[y][x] - '0';
	dp[y][x] = 1;
	if(x + value < M && field[y][x + value] != 'H') {
		dp[y][x] = max(dp[y][x], 1 + dfs(y, x + value));
	}
	if(x - value >= 0 && field[y][x - value] != 'H') {
		dp[y][x] = max(dp[y][x], 1 + dfs(y, x - value));
	}
	if(y + value < N && field[y + value][x] != 'H') {
		dp[y][x] = max(dp[y][x], 1 + dfs(y + value, x));
	}
	if(y - value >= 0 && field[y - value][x] != 'H') {
		dp[y][x] = max(dp[y][x], 1 + dfs(y - value, x));
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	fill(&dp[0][0], &dp[50][51], -1);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) cin >> field[i][j];
	}
	cout << dfs(0, 0);
}
