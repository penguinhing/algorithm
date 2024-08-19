#include <bits/stdc++.h>

using namespace std;
int N, M, v, field[101][101];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> field[i][j];
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> v;
			cout << field[i][j] + v << " ";
		}
		cout << "\n";
	}
}
