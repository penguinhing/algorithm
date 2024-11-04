#include <bits/stdc++.h>

using namespace std;
int T, M, N, x, y, k;

int go() {
	k = x;
	while(k <= N * M) {
		if( (k - x) % N == 0 && (k  - y) % M == 0) return k;
		k += N;
	}
	return -1;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	while(T--) {
		cin >> N >> M >> x >> y;
		cout << go() << "\n";
	}
}
