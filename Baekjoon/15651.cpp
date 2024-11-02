#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> v;

void dfs(int depth) {
	if(depth == M) {
		for(int i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= N; ++i) {
		v.push_back(i);
		dfs(depth + 1);
		v.pop_back();
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	dfs(0);
}
