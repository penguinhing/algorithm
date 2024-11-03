#include <bits/stdc++.h>

using namespace std;

int T, N, M, tree[200004], offset, tmp;
map<int, int> mp;

void update(int idx, int value) {
	while(idx < 200004) {
		tree[idx] += value;
		idx += (idx & -idx);
	}
}

int sum(int idx) {
	int ret = 0;
	while(offset <= idx) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	while(T--) {
		offset = 100001;
		cin >> N >> M;
		for(int i = 1; i <= N; ++i) {
			update(offset + i, 1);
			mp[i] = offset + i;
		}
		for(int i = 0; i < M; ++i) {
			cin >> tmp;
			cout << sum(mp[tmp] - 1) << " ";
			update(mp[tmp], -1);
			mp[tmp] = --offset;
			update(mp[tmp], 1);
		}
		mp.clear();
		memset(tree, 0, sizeof(tree));
		cout << "\n";
	}
}
