#include <bits/stdc++.h>

using namespace std;

int K, N;
vector<int> result[11];
int nodes[1025];
int rootIdx;

void tree(int start, int depth) {
	if(depth > K) return;
	int idx = rootIdx;
	for(int i = 1; i < depth; ++i) {
		idx = idx / 2;
	}
	idx = start + idx;
	result[depth].push_back(nodes[idx]);
	tree(start, depth+1);
	tree(idx, depth+1);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> K;
	N = pow(2, K) - 1;
	for(int i = 1; i <= N; ++i) {
		cin >> nodes[i];
	}
	rootIdx = round(N / 2.0f);
	tree(0, 2);
	tree(rootIdx, 2);
	cout << nodes[rootIdx] << "\n";
	for(int i = 2; i <= K; ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
				cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}
