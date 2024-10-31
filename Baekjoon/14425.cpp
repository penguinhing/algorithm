#include <bits/stdc++.h>

using namespace std;
int N, M, result = 0;
set<string> s;
string a;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		s.insert(a);
	}
	for(int i = 0; i < M; ++i) {
		cin >> a;
		if(s.find(a) != s.end()) ++result;
	}
	cout << result;
}
