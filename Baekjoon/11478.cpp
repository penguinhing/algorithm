#include <bits/stdc++.h>

using namespace std;
string N;
set<string> v;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int _size = 1; _size <= N.length(); ++_size) {
		for (int i = 0; i < N.length(); ++i) {
			if(i + _size > N.length()) continue;
			v.insert(N.substr(i, _size));
		}
	}
	cout << v.size();
}
