#include <bits/stdc++.h>
#define INF 20000000

using namespace std;

int N;
int W[20][20], dp[20][150000];

bool bitCount(int visited, int k) {
	int cnt = 0;
	for (int i = 1; i < N; ++i) {
		if (visited & (1 << i)) ++cnt;
	}
	return cnt == k;
}

bool isIn(int city, int visited) {
	for (int i = 1; i < N; ++i) {
		if ((visited & (1 << i)) && i == (city - 1)) return true;
	}
	return false;
}

int getMin(int city, int visited) {
	int result = INF;
	for (int i = 2; i <= N; ++i) {
		if (isIn(i, visited)) {
			if (W[city][i] == 0) continue;
			result = min(result, W[city][i] + dp[i][visited ^ (1 << i - 1)]);
		}
	}
	return result;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	fill(&dp[0][0], &dp[19][150000], INF);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> W[i][j];
	}
	for (int i = 2; i <= N; ++i) {
		if (W[i][1] == 0) dp[i][0] = INF;
		else dp[i][0] = W[i][1];
	}

	for (int k = 1; k <= N - 2; ++k) {
		for (int i = 2; i <= N; ++i) {
			for (int visited = 1; visited < (1 << N); ++visited) {
				if (visited & 1) continue;
				if (isIn(i, visited)) continue;
				if (!bitCount(visited, k)) continue;
				dp[i][visited] = getMin(i, visited);
			}
		}
	}
	cout << getMin(1, ((1 << N) - 1)  ^ 1);
}
