#include <bits/stdc++.h>

using namespace std;

class Tree {
public:
	int start;
	int end;
	int size;
	int deadline;
	int age[100000] = { 0 };
	bool isDead;

	Tree() {
		start = -1;
		end = 0;
		deadline = 0;
		size = 0;
		isDead = false;
	}

	void add(int a) {
		age[++start] = a;
		++size;
	}

	bool isEmpty() {
		return end > start;
	}
};

Tree tree[14][14];
int field[14][14], A[14][14], N, M, K, ny, nx, result = 0;
int check[14][14] = { 0 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (tree[i][j].isEmpty()) continue;
			for (int s = tree[i][j].start; s >= tree[i][j].end; --s) {
				if (field[i][j] < tree[i][j].age[s]) {
					tree[i][j].end = s + 1;
					tree[i][j].isDead = true;
					break;
				}
				field[i][j] -= tree[i][j].age[s];
				++tree[i][j].age[s];
				if (tree[i][j].age[s] % 5 == 0) ++check[i][j];
			}
		}
	}
}

void summer() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!tree[i][j].isDead) continue;
			for (int s = tree[i][j].end - 1; s >= tree[i][j].deadline; --s) {
				field[i][j] += tree[i][j].age[s] * 0.5;
				--tree[i][j].size;
			}
			tree[i][j].deadline = tree[i][j].end;
			tree[i][j].isDead = false;
		}
	}
}

void fall() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (check[i][j] == 0) continue;
			for (int d = 0; d < 8; ++d) {
				ny = i + dy[d];
				nx = j + dx[d];
				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				for (int x = 0; x < check[i][j]; ++x) tree[ny][nx].add(1);
			}
			check[i][j] = 0;
		}
	}
}

void winter() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) field[i][j] += A[i][j];
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> K;
	fill(&field[0][0], &field[13][14], 5);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> A[i][j];
	}
	int y, x, ag;
	for (int i = 0; i < M; ++i) {
		cin >> y >> x >> ag;
		tree[y][x].add(ag);
		sort(tree[y][x].age, tree[y][x].age + 14, greater<int>());
	}
	for (int i = 1; i <= K; ++i) {
		spring();
		summer();
		fall();
		winter();
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			result += tree[i][j].size;
		}
	}
	cout << result;
}
