#include <bits/stdc++.h>
#define INF 2100000000
using namespace std;

int N, M, v, a, b, startIdx = 1;
pair<int, int> tree[270000];

void init() {
	int idx = startIdx;
	int _size = N;
	while(idx > 0) {
		for(int i = idx; i < idx + _size; ++i) {
			tree[i / 2].first = min(tree[i].first, tree[i / 2].first);
			tree[i / 2].second = max(tree[i].second, tree[i / 2].second);
		}
		idx /= 2;
		_size = (_size / 2) + (_size % 2);
	}
}

int mx(int a, int b) {
	int ret = 0;
	while(a <= b) {
		if(a % 2 == 1) ret = max(ret, tree[a].second);
		if(b % 2 == 0) ret = max(ret, tree[b].second);
		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return ret;
}

int mn(int a, int b) {
	int ret = INF;
	while(a <= b) {
		if(a % 2 == 1) ret = min(ret, tree[a].first);
		if(b % 2 == 0) ret = min(ret, tree[b].first);
		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	while(startIdx < N) startIdx *= 2;
	for(int i = startIdx * 2; i > 0; --i) tree[i].first = INF;
	for(int i = startIdx; i < startIdx + N; ++i) {
		cin >> v;
		tree[i] = {v, v};
	}
	init();
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << mn(startIdx + a - 1, startIdx + b - 1) << " " << mx(startIdx + a - 1, startIdx + b - 1) << "\n";
	}
}
