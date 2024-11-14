#include <bits/stdc++.h>

using namespace std;
int N, M, a, visited[1004];
vector<int> v, result;

void dfs(int depth) {
	if(depth == M) {
		for(auto it : result) {
			cout << it << " ";
		}
		cout << "\n";
		return;
	}
	int last = -1;
	for(int i = 0; i < v.size(); ++i) {
		if(visited[i] || last == v[i]) continue;
		result.push_back(v[i]);
		visited[i] = 1;
		dfs(depth + 1);
		visited[i] = 0;
		result.pop_back();
		last = v[i];
	}
	return;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0);
}
