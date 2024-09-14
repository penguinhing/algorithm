#include <bits/stdc++.h>

using namespace std;

vector<int> field[5];
int number[10], result = 0;
pair<int, int> pos[4];
int visited[6][41];

void createField(int* arr, int size, int cos) {
	for (int i = 0; i < size; ++i) field[cos].push_back(arr[i]);
}

void dfs(int hap, int depth) {
	if (depth == 10) {
		result = max(result, hap);
		return;
	}

	pair<int, int> before;
	int now_area, next, value, idx;
	for (int i = 0; i < 4; ++i) {
		if (field[pos[i].first][pos[i].second] == 0) continue;
		before.first = pos[i].first;
		before.second = pos[i].second;
		now_area = pos[i].first;
		next = pos[i].second + number[depth];
		if (now_area == 4 && field[4].size() <= next) next = field[4].size() - 1;
		else if (next >= field[now_area].size()) {
			idx = next - field[now_area].size();
			if (now_area == 0) {
				if (idx == 0) next = field[4].size() - 2;
				else next = field[4].size() - 1;
			}
			else next = min((int)field[4].size() - 1, idx);
			now_area = 4;
		}
		if (now_area == 0 &&
			(field[0][next] == 10 || field[0][next] == 20 || field[0][next] == 30)) {
			now_area = field[0][next] / 10;
			next = 0;
		}
		value = field[now_area][next];
		if (visited[now_area][next] == 1) continue;
		visited[before.first][before.second] = 0;
		if (value != 0) visited[now_area][next] = 1;

		pos[i].first = now_area;
		pos[i].second = next;

		dfs(hap + value, depth + 1);

		visited[now_area][next] = 0;
		visited[before.first][before.second] = 1;

		pos[i].first = before.first;
		pos[i].second = before.second;
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int a[] = { -1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38 };
	int b[] = { 10, 13, 16, 19 };
	int c[] = { 20, 22, 24 };
	int d[] = { 30, 28, 27, 26 };
	int e[] = { 25, 30, 35, 40, 0 };
	createField(a, 20, 0); createField(b, 4, 1); createField(c, 3, 2); createField(d, 4, 3); createField(e, 5, 4);
	for (int i = 0; i < 10; ++i) cin >> number[i];
	dfs(0, 0);
	cout << result;
}
