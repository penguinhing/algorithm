#include <bits/stdc++.h>

using namespace std;
int field[11][11], result = INT_MAX;
int remain[6] = {-1, 5, 5, 5, 5, 5};

bool check(int y, int x, int k) {
	for (int i = y; i < y + k; ++i) {
		for (int j = x; j < x + k; ++j) {
			if (field[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int k, int value) {
	for (int i = y; i < y + k; ++i) {
		for (int j = x; j < x + k; ++j) {
			field[i][j] = value;
		}
	}	
}

void dfs(int y, int x, int cnt) {
	if(cnt >= result) return;
	if(x > 10) {
		dfs(y + 1, 0, cnt);return;
	}
	if(y > 10) {
		result = cnt;return;
	}
	if(field[y][x] == 0) {
		dfs(y, x + 1, cnt); return;
	}
	for(int i = 5; i > 0; --i) {
		if (remain[i] > 0 && check(y, x, i)) {
			--remain[i];
			draw(y, x, i, 0);
			dfs(y, x + 1, cnt + 1);
			draw(y, x, i, 1);
			++remain[i];
		}
	}	
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> field[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << (result == INT_MAX ? -1 : result);
}
