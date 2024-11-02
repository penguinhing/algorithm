#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M, K, start = 1, last;
ll tree[2200000], a, b, c;

void init(int s, int e) {
	while (s > 0) {
		for (int i = s; i < e; ++i) tree[i / 2] += tree[i];
		e = (s / 2) + ((e - s) / 2) + ((e - s) % 2);
		s /= 2;
	}
}

ll hap(int s, int e) {
	ll ret = 0;
	while (s <= e) {
		if (s % 2 == 1) ret += tree[s];
		if (e % 2 == 0) ret += tree[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

void update(int k, ll v) {
	ll before = tree[k];
	tree[k] = v;
	k /= 2;
	while(k > 0) {
		tree[k] -= before;
		tree[k] += v; 
		k /= 2;
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M >> K;
	while (N > start) start *= 2;
	last = start + N;
	for (int i = start; i < last; ++i) cin >> tree[i];
	init(start, last);
	for(int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if(a == 1) update(start - 1 + b, c);
		else cout << hap(start - 1 + b, start - 1 + c) << "\n";
	}
}
