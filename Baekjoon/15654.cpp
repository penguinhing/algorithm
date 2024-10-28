#include <bits/stdc++.h>

using namespace std;
int N, M, a, visited[10004];
vector<int> v, p;
void next(int depth) {
	if(depth == M) {
		for(int i = 0; i < p.size(); ++i) cout << p[i] << " ";
		cout << "\n";
	}
	for(int i = 0; i < v.size(); ++i) {
		if(visited[v[i]]) continue;
		p.push_back(v[i]);
		visited[v[i]] = 1;
		next(depth + 1);
		visited[v[i]] = 0;
		p.pop_back();
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	next(0);
}
