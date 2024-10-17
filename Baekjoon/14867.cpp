#include <bits/stdc++.h>

using namespace std;
int A, B, _a, _b;
map<int, map<int, int>> visited;
struct Status { int a; int b; int depth; };

pair<int, int> to(int a, int b, int C) {
	return make_pair(max(a - (C - b), 0), min(C, b + a));
}

void bfs() {
	queue<Status> q;
	Status s{ 0, 0, 0 };
	visited[0][0] = 1;
	q.push(s);
	int tmpA, tmpB;
	while (!q.empty()) {
		Status value = q.front(); q.pop();
		if (value.a == _a && value.b == _b) {
			cout << value.depth;
			exit(0);
		}
		if (!visited[A][value.b]) {
			visited[A][value.b] = 1;
			Status v{ A, value.b, value.depth + 1 };
			q.push(v);
		}
		if (!visited[value.a][B]) {
			visited[value.a][B] = 1;
			Status v{ value.a, B, value.depth + 1 };
			q.push(v);
		}
		if (!visited[0][value.b]) {
			visited[0][value.b] = 1;
			Status v{ 0, value.b, value.depth + 1 };
			q.push(v);
		}
		if (!visited[value.a][0]) {
			visited[value.a][0] = 1;
			Status v{ value.a, 0, value.depth + 1 };
			q.push(v);
		}
		pair<int, int> r = to(value.a, value.b, B);
		if (!visited[r.first][r.second]) {
			visited[r.first][r.second] = 1;
			Status v{ r.first, r.second, value.depth + 1 };
			q.push(v);
		}
		r = to(value.b, value.a, A);
		if (!visited[r.second][r.first]) {
			visited[r.second][r.first] = 1;
			Status v{ r.second, r.first, value.depth + 1 };
			q.push(v);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> A >> B >> _a >> _b;
	bfs();
	cout << -1;
}
