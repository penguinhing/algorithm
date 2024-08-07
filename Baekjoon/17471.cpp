#include <bits/stdc++.h>

using namespace std;

int N, hap = 0, v;
vector<int> area[14];
int values[14];
int visited[14];
int result = INT_MAX;

bool check(int v) {
	visited[v] = 2;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (int i : area[v]) {
			if (visited[i] == 1) {
				visited[i] = 2;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == 1) return false;
	}
	return true;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> values[i];
		hap += values[i];
	}
	int c, d;
	for (int i = 1; i <= N; ++i) {
		cin >> c;
		for (int j = 1; j <= c; ++j) {
			cin >> d;
			area[i].push_back(d);
		}
	}
	for (int i = 1; i < (1 << N); ++i) {
		vector<int> t1;
		for (int j = 1; j <= N; ++j) visited[j] = 0;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				t1.push_back(j + 1);
				visited[j + 1] = 1;
			}
		}
		if (t1.size() == N) continue;
		if (check(t1[0])) {
			vector<int> t2;
			for (int j = 1; j <= N; ++j) {
				if (visited[j] == 0) {
					t2.push_back(j);
					visited[j] = 1;
				}
			}
			if (check(t2[0])) {
				int a = 0;
				for (int d = 0; d < t1.size(); ++d) {
					a += values[t1[d]];
				}
				result = min(abs(a - (hap - a)), result);
			}
		}
	}
	cout << (result == INT_MAX ? -1 : result);
}
