#include <bits/stdc++.h>

using namespace std;
int N, M, ny, nx, mx, result = 0;
int field[504][504];

int dx[5][4] = {
{0, 1, 2, 3},
{0, 0, 0, 1},
{0, 0, 1, 1},
{0, 1, 1, 2},
{0, 1, 0, 1}
};
int dy[5][4] = {
{ 0, 0, 0, 0 },
{ 0, 1, 2, 2},
{ 0, 1, 1, 2},
{ 0, 0, 1, 0},
{ 0, 0, 1, 1}
};

int put(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 5; ++i) {
		mx = 0;
		for (int j = 0; j < 4; ++j) {
			ny = y + dy[i][j];
			nx = x + dx[i][j];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				mx = 0;
				break;
			}
			mx += field[ny][nx];
		}
		ret = max(ret, mx);
	}
	return ret;
}

void copy_field(int tmp[504][504]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) field[i][j] = tmp[i][j];
	}
}

void rotate() {
	int tmp[504][504] = { 0 };
	for (int i = N - 1; i >= 0; --i) {
		int col = N - 1 - i;
		int row = 0;
		for (int j = 0; j < M; ++j) tmp[row++][col] = field[i][j];
	}
	swap(N, M);
	copy_field(tmp);
}

void reversal() {
	int tmp[504][504] = { 0 };
	for (int i = 0; i < N; ++i) {
		int col = M - 1;
		for (int j = 0; j < M; ++j) tmp[i][col--] = field[i][j];
	}
	copy_field(tmp);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cin >> field[i][j];
	}
	for (int x = 0; x < 2; ++x) {
		for (int d = 0; d < 4; ++d) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					result = max(result, put(i, j));
				}
			}
			rotate();
		}
		reversal();
	}
	cout << result;
}
