#include <bits/stdc++.h>

using namespace std;
int N, v, last = 1;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	stack<int> st;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		st.push(v);
		while(!st.empty() && st.top() == last) {
			st.pop();
			++last;
		} 
	}
	cout << (st.size() ? "Sad" : "Nice");
}
