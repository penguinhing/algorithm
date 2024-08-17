#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int N; cin >> N;
	string s;
	for(int i = 0; i < N; ++i) {
		cin >> s;
		cout << s[0] << s[s.length()-1] << "\n";
	}
}
