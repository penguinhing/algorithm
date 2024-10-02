#include <bits/stdc++.h>

using namespace std;
int N;
int field[200][200];
int result[2] = { 0 };

void cut(int offsetY, int offsetX, int size) {
	for(int i = offsetY; i < offsetY + size; ++i) {
		for(int j = offsetX; j < offsetX + size; ++j) {
			if(field[offsetY][offsetX] != field[i][j]) {
				cut(offsetY, offsetX, size / 2);
				cut(offsetY, offsetX + size / 2, size / 2);
				cut(offsetY + size / 2, offsetX, size / 2);
				cut(offsetY + size / 2, offsetX + size / 2, size / 2);				
				return;
			}
		}
	}
	++result[field[offsetY][offsetX]];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) cin >> field[i][j];
	}
	cut(0, 0, N);
	cout << result[0] << "\n" << result[1];
}
