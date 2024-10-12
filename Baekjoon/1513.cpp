#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;
int N, M, C, a, b;
int dp[53][53][53][53] = { 0 };
int visited[53][53] = { 0 };

void move(int i, int j, int k, int game) {
	for (int ii = i; ii <= N; ++ii) {
		for (int jj = j; jj <= M; ++jj) {
			if (visited[ii][jj]) continue;
			dp[ii][jj][k][game] += (dp[ii - 1][jj][k][game] % MOD) + (dp[ii][jj - 1][k][game] % MOD);
		}
	}
}

void go(int k) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (visited[i][j] < k) continue;
			int game = visited[i][j];
			dp[i][j][k][game] = 0;
			if(k == 1) dp[i][j][k][game] += (dp[i - 1][j][k - 1][0] % MOD) + (dp[i][j - 1][k - 1][0] % MOD);
			else {
				for (int g = 1; g <= game - 1; ++g) dp[i][j][k][game] += dp[i - 1][j][k - 1][g] % MOD;
				for (int g = 1; g <= game - 1; ++g) dp[i][j][k][game] += dp[i][j - 1][k - 1][g] % MOD;				
			}
			move(i, j, k, game);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> C;
	for (int i = 1; i <= C; ++i) {
		cin >> a >> b;
		visited[a][b] = i;
	}
	dp[1][0][0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (visited[i][j]) continue;
			dp[i][j][0][0] += (dp[i - 1][j][0][0] % MOD) + (dp[i][j - 1][0][0] % MOD);
		}
	}
	for (int i = 1; i <= C; ++i) go(i);
	cout << dp[N][M][0][0] % MOD << " ";
	for (int i = 1; i <= C; ++i) {
		int ret = 0;
		for (int j = 1; j <= C; ++j) {
			ret += dp[N][M][i][j] % MOD;
		}
		cout << ret % MOD << " ";
	}
}
