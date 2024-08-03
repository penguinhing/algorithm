#include <bits/stdc++.h>

using namespace std;

int N, M, v;
map<int, bool> mp;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		mp.insert({v, true});
	}
	cin >> M;
	for(int i = 0; i < M; ++i) {
		cin >> v;
		cout << mp[v] << "\n";
	}
}
