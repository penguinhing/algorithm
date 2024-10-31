#include <bits/stdc++.h>

using namespace std;
int N, v;
set<int> st;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		st.insert(v);
	}
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		if(st.find(v) != st.end()) cout << "1 ";
		else cout << "0 ";
	}
}
