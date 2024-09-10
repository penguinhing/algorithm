#include <bits/stdc++.h>

using namespace std;
int N, cnt, team, result = INT_MAX;
int field[22][22];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) cin >> field[i][j];
	}
	
	for(int i = 1; i < (1 << N); ++i) {
		int visited[22] = { 0 };
		cnt = 0;
		for(int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				visited[j] = 1; ++cnt;
			}
		}

		int t[2] = { 0 };
		if(cnt == N / 2) {
			for(int j = 0; j < N; ++j) {
				team = visited[j];
				for(int ii = 0; ii < N; ++ii) {
					if(j == ii || visited[ii] != team) continue;
					t[team] += field[j][ii];
				}
			}
			result = min(result, abs(t[0] - t[1]));
		}
	}
	cout << result;
}
