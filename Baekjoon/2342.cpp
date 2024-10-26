#include <bits/stdc++.h>
#define INF 1000000

using namespace std;
int N, dp[5][5][100004], result = INF;
vector<int> v;
pair<int, int> dis[5] = { {-1, -1}, {2, 4}, {1, 3}, {2, 4}, {1, 3} };

int move(int to, int from) {
	if(to == from) return 1;
	if (to == 0) return 2;
	if (dis[to].first == from || dis[to].second == from) return 3;
	return 4;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) fill(dp[i][j], dp[i][j] + 100004, INF);
    }
	while(true) {
		cin >> N;
		if(N == 0) break;
		v.push_back(N);
	}
	dp[v[0]][0][0] = 2;
	for(int k = 1; k < v.size(); ++k) {
		for(int i = 0; i <= 4; ++i) {
			for(int j = 0; j <= 4; ++j) {
				if(dp[i][j][k - 1] != INF) {
					dp[v[k]][j][k] = min(dp[v[k]][j][k], dp[i][j][k - 1] + move(i, v[k]));
					dp[i][v[k]][k] = min(dp[i][v[k]][k], dp[i][j][k - 1] + move(j, v[k]));
				}
			}
		}
	}
	for(int i = 0; i <= 4; ++i) {
		for(int j = 0; j <= 4; ++j) result = min(dp[i][j][v.size() - 1], result);
	}
	cout << result;
}
