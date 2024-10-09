#include <bits/stdc++.h>

using namespace std;

int N, M;
string a, b;
map<string, string> mp;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		mp.insert({a, b});
	}
	for(int i = 0; i < M; ++i) {
		cin >> a;
		cout << mp[a] << "\n";
	}
}
