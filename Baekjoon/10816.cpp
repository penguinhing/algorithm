#include <bits/stdc++.h>

using namespace std;
int N, M, v;
map<int, int> mp; 

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		++mp[v];
	}
	cin >> M;
	for(int i = 0; i < M; ++i) {
		cin >> v;
		cout << mp[v] << " ";
	}
}
