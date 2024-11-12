#include <bits/stdc++.h>

using namespace std;
int N, idx = 0;
vector<int> result;
void dfs(int k, int len, int depth) {
	result.push_back(k);
	if(len == depth) {
		++idx;
		if(idx == N) {
			for(auto i : result) cout << i;
			exit(0);
		}
		result.pop_back();
		return;
	}
	for(int i = 0; i < k; ++i) dfs(i, len, depth + 1);
	result.pop_back();
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	if(N == 0) {
		cout << 0; return 0;
	}
	for(int i = 1; i <= 10; ++i) {
		for(int j = 1; j <= 9; ++j) dfs(j, i, 1);	
	}
	cout << -1;
}
