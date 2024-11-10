#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N, W, dis;
pair<int, int> w_pos[1004];
int dp[1004][1004];

int getDis(int y, int x, int finY, int finX) {
	return abs(y - finY) + abs(x - finX);
}

int go(int p1, int p2) {
	if(p1 == W + 1 || p2 == W + 1) return 0;
	if(dp[p1][p2] != -1) return dp[p1][p2];
	int next = max(p1, p2) + 1;
	int d1 = getDis(w_pos[p1].first, w_pos[p1].second, w_pos[next].first, w_pos[next].second);
	int d2 = getDis(w_pos[p2].first, w_pos[p2].second, w_pos[next].first, w_pos[next].second);
	return dp[p1][p2] = min(go(next, p2) + d1, go(p1, next) + d2);
}

void history(int p1, int p2) {
	if(p1 == W + 1 || p2 == W + 1) return;
	int next = max(p1, p2) + 1;
	int d1 = getDis(w_pos[p1].first, w_pos[p1].second, w_pos[next].first, w_pos[next].second);
	int d2 = getDis(w_pos[p2].first, w_pos[p2].second, w_pos[next].first, w_pos[next].second);
	if(dp[next][p2] + d1 < dp[p1][next] + d2) {
		cout << "1\n";
		history(next, p2);
	}
	else {
		cout << "2\n";
		history(p1, next);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> W;
	w_pos[0] = {1, 1}; w_pos[1] = {N, N};
	for(int i = 2; i <= W + 1; ++i) cin >> w_pos[i].first >> w_pos[i].second;
	cout << go(0, 1) << "\n";
	history(0, 1);
}
