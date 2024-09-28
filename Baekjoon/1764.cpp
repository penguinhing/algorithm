#include <bits/stdc++.h>

using namespace std;
int N, M;
string a;
vector<string> result;
set<string> st;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		st.insert({a});
	}
	for(int j = 0; j < M; ++j) {
		cin >> a;
		if (st.find(a) != st.end()) result.push_back(a);
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for(string c : result) cout << c << "\n";
}
