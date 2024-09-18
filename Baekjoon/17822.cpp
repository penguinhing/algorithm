#include <bits/stdc++.h>

using namespace std;

int N, M, T, x, d, k, ny, nx, result = 0;
vector<int> field[52];

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j)
		{
			cin >> x;
			field[i].push_back(x);
		}
	}
	for (int a = 0; a < T; ++a) {
		cin >> x >> d >> k;

		for (int i = x; i <= N; i += x) {
			if (d == 0) rotate(field[i].rbegin(), field[i].rbegin() + k, field[i].rend());
			else rotate(field[i].begin(), field[i].begin() + k, field[i].end());
		}
		
		queue<pair<int, int>> q;
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				if (field[i][j] == 0) continue;
				for (int l = 0; l < 4; ++l) {
					ny = dy[l] + i;
					nx = dx[l] + j;

					if (ny > N || ny <= 0) continue;
					if (nx >= M) nx = 0;
					else if (nx < 0) nx = M - 1;
					if (field[i][j] == field[ny][nx]) {
						q.push({ i, j });
						q.push({ ny, nx });
					}
				}
			}
		}
		if(q.empty()) {
			int hap = 0, cnt = 0;
			for (int i = 1; i <= N; ++i) {
				for (int j = 0; j < field[i].size(); ++j) {
					if (field[i][j] == 0) continue;
					hap += field[i][j]; ++cnt;
				}
			}
			double avg = hap / (double)cnt;
			for (int i = 1; i <= N; ++i) {
				for (int j = 0; j < field[i].size(); ++j) {
					if (field[i][j] == 0 || field[i][j] == avg) continue;
					field[i][j] += (field[i][j] > avg) ? -1 : 1;
				}
			}		
		}
		while (!q.empty()) {
			field[q.front().first][q.front().second] = 0;
			q.pop();
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < field[i].size(); ++j) result += field[i][j];
	}
	cout << result;
}
