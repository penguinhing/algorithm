#include <bits/stdc++.h>

using namespace std;
int T, a, b;
bool visited[10000];

string bfs(int a, int b) {
	queue<pair<int, string>> q;
	visited[a] = true;
	pair<int, string> v;
	int value;
	q.push({ a, "" });
	while (!q.empty()) {
		v = q.front();
		q.pop();
		if (v.first == b) return v.second;
		value = (v.first * 2) % 10000;
		if (!visited[value]) {
			visited[value] = true;
			q.push({ value, v.second + "D" });
		}

		value = (v.first - 1 < 0 ? 9999 : v.first - 1);
		if (!visited[value]) {
			visited[value] = true;
			q.push({ value, v.second + "S" });
		}

		value = (v.first % 1000) * 10 + (v.first / 1000);
		if (!visited[value]) {
			visited[value] = true;
			q.push({ value, v.second + "L" });
		}

		value = (v.first % 10) * 1000 + (v.first / 10);
		if (!visited[value]) {
			visited[value] = true;
			q.push({ value, v.second + "R" });
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> a >> b;
		cout << bfs(a, b) << "\n";
		memset(visited, false, sizeof(visited));
	}
}
