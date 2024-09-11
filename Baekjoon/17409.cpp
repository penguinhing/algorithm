#include <bits/stdc++.h>

using namespace std;

struct rcs {
	int ay;
	int ax;
	int by;
	int bx;
};

int N, M, K, result = INT_MAX;
int field[52][52];
vector<rcs> pos;
int nums[6] = {0, 1, 2, 3, 4, 5};

void rotate(int ay, int ax, int by, int bx, int field[52][52]) {
	if(ay == by && ax == bx) return;
	int tmp[52][52] = { 0 };
	for (int i = ax; i < bx; ++i) tmp[ay][i + 1] = field[ay][i];
	for (int i = ay; i < by; ++i) tmp[i + 1][bx] = field[i][bx];
	for (int i = bx; i > ax; --i) tmp[by][i - 1] = field[by][i];
	for (int i = by; i > ay; --i) tmp[i - 1][ax] = field[i][ax];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if(tmp[i][j] == 0) continue;
			field[i][j] = tmp[i][j];
		}
	}
	rotate(ay+1, ax+1, by-1, bx-1, field);
}

void combi(int depth) {
	if(K == depth) {
		int tmp[52][52];
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) tmp[i][j] = field[i][j];
		}
		
		for(int i = 0; i < K; ++i) {
			rcs v = pos[nums[i]];
			rotate(v.ay, v.ax, v.by, v.bx, tmp);
		}
		
		for(int i = 1; i <= N; ++i) {
			int total = 0;
			for(int j = 1; j <= M; ++j) total += tmp[i][j];
			result = min(total, result);
		}
		return;
	}
	for(int i = depth; i < K; ++i) {
		swap(nums[i], nums[depth]);
		combi(depth+1);
		swap(nums[i], nums[depth]);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) cin >> field[i][j];
	}
	int r, c, s;
	for(int i = 0; i < K; ++i) {
		rcs v;
		cin >> r >> c >> s;
		v.ax = c - s; v.ay = r - s;
		v.bx = c + s; v.by = r + s; 
		pos.push_back(v);
	}
	combi(0);
	cout << result;
}
