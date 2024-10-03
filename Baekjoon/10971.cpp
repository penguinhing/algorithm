#include <bits/stdc++.h>

using namespace std;
int N, result = INT_MAX;
int W[20][20];

void go(int start, int last, int visited, int hap) {
	if ((1 << N) - 1 == visited) {
		if (W[last][start] == 0) return;
		result = min(result, hap + W[last][start]);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (((1 << i) & visited) == 0 && W[last][i] != 0) {
			go(start, i, (1 << i) | visited, hap + W[last][i]);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> W[i][j];
	}
	go(0, 0, 1, 0);
	cout << result;
}
