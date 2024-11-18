#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
int N, M, tree[300000], startIdx = 1, a, b;

void init(int s, int e) {
	while(s >= 1) {
		for(int i = s; i < e; ++i) {
			tree[i / 2] = min(tree[i], tree[i / 2]);
		}
		e = (s / 2) + ((e - s) / 2) + ((e - s) % 2);
		s /= 2;
	}	
}

int go(int s, int e) {
	int ret = INF;
	while(s <= e) {
		if(s % 2 == 1) ret = min(ret, tree[s]);
		if(e % 2 == 0) ret = min(ret, tree[e]);
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	fill(tree, tree + 300000, INF);
	while(startIdx < N) startIdx *= 2;
	for(int i = startIdx; i < startIdx + N; ++i) cin >> tree[i];
	init(startIdx, startIdx + N);
	while(M--) {
		cin >> a >> b;
		cout << go(startIdx - 1 + a, startIdx - 1 + b) << "\n";
	}
}
