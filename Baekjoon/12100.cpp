#include <bits/stdc++.h>

using namespace std;
int N, result = 0;
int field[22][22];

int mdx[2] = { 0, 0 };
int inc[4] = { 1, -1, -1, 1 };
int boundary[4] = { 0, -1, -1, 0 };

void moveX(int arrow, int field[22][22]) {
	for (int i = 0; i < N; ++i) {
		for (int j = mdx[arrow]; j != boundary[arrow]; j += inc[arrow]) {
			if (field[i][j] == 0) continue;
			for (int jj = j + inc[arrow]; jj != boundary[arrow]; jj += inc[arrow]) {
				if (field[i][jj] == 0) continue;
				if (field[i][j] != field[i][jj]) break;
				field[i][j] = field[i][j] + field[i][j];
				field[i][jj] = 0;
				break;
			}
			for (int jj = j + inc[2 + arrow]; jj != boundary[2 + arrow]; jj += inc[2 + arrow]) {
				if (field[i][jj] != 0) break;
				if (jj + inc[2 + arrow] == boundary[2 + arrow]) {
					field[i][jj] = field[i][j];
					field[i][j] = 0; break;
				}

				if (field[i][jj + inc[2 + arrow]] != 0) {
					field[i][jj] = field[i][j];
					field[i][j] = 0; break;
				}
			}
		}
	}
}

void moveY(int arrow, int field[22][22]) {
	for (int i = 0; i < N; ++i) {
		for (int j = mdx[arrow]; j != boundary[arrow]; j += inc[arrow]) {
			if (field[j][i] == 0) continue;
			for (int jj = j + inc[arrow]; jj != boundary[arrow]; jj += inc[arrow]) {
				if (field[jj][i] == 0) continue;
				if (field[j][i] != field[jj][i]) break;
				field[j][i] = field[j][i] + field[j][i];
				field[jj][i] = 0;
				break;
			}
			for (int jj = j + inc[2 + arrow]; jj != boundary[2 + arrow]; jj += inc[2 + arrow]) {
				if (field[jj][i] != 0) break;
				if (jj + inc[2 + arrow] == boundary[2 + arrow]) {
					field[jj][i] = field[j][i];
					field[j][i] = 0;
					break;
				}
				if (field[jj + inc[2 + arrow]][i] != 0) {
					field[jj][i] = field[j][i];
					field[j][i] = 0; break;
				}
			}
		}
	}
}

void dfs(int depth, int field[22][22]) {
	if (depth > 5) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) result = max(result, field[i][j]);
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int tmp[22][22] = { 0 };
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) tmp[i][j] = field[i][j];
		}
		if (i <= 1) moveX(i, tmp);
		else moveY(i - 2, tmp);
		dfs(depth + 1, tmp);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> field[i][j];
	}
	mdx[1] = N-1; boundary[0] = N; boundary[3] = N;
	dfs(1, field);
	cout << result;
}
