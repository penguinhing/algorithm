#include <bits/stdc++.h>

using namespace std;
int N, M, B, result[2];
int field[502][502];

int check(int H) {
	int removedBlock = 0, needsBlock = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(field[i][j] < H) needsBlock += H - field[i][j];
			else if(field[i][j] > H) removedBlock += field[i][j] - H;
		}
	}
	if(removedBlock + B < needsBlock) return INT_MAX;
	return removedBlock * 2 + needsBlock;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> B;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) cin >> field[i][j];
	}
	result[0] = INT_MAX;
	for(int i = 0; i <= 256; ++i) {
		int v = check(i);
		if(result[0] >= v) {
			result[0] = v;
			result[1] = i;
		}
	}
	cout << result[0] << " " << result[1];
}
