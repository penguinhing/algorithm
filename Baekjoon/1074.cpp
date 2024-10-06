#include <bits/stdc++.h>

using namespace std;
int N, R, C;
int square = 0;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

void cut(int y, int x, int size) {
	if(C >= x + size || R >= y + size) {
		square += size * size;
		return;
	}
	if(size == 2) {
		for(int i = 0; i < 4; ++i) {
			if (R == y + dy[i] && C == x + dx[i]) {
				cout << square + i;
				exit(0);
			}
		}
		++square;
		return;
	}
	cut(y, x, size / 2);
	cut(y, (size / 2) + x, size / 2);
	cut((size / 2) + y, x, size / 2);
	cut((size / 2) + y, (size / 2) + x, size / 2);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> R >> C;
	cut(0, 0, pow(2, N));
}
