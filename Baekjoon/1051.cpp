#include <bits/stdc++.h>

using namespace std;
int N, M, ny, nx, _size, result = 1;
char field[52][52];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) cin >> field[i][j];
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			ny = i, nx = j, _size = 1;
			while(true) {
				++_size;
				ny += 1;
				nx += 1;
				if(ny >= N || nx >= M) break;
				if(field[ny][nx] == field[i][j] && field[i][nx] == field[i][j] && field[ny][j] == field[i][j]) result = max(_size, result);
			}
		}
	}
	cout << result * result;
}
