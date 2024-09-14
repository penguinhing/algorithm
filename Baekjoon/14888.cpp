#include <bits/stdc++.h>

using namespace std;
int mn = INT_MAX, mx = INT_MIN;
int N, a;
int v[15];
vector<char> opr;
vector<int> nx;

int calc(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> v[i];

	char ops[4] = {'+', '-', '*', '/'};
	for(int i = 0; i < 4; ++i) {
		cin >> a;
		for(int j = 0; j < a; ++j) opr.push_back(ops[i]);
	}
	for(int i = 0; i < N-1; ++i) nx.push_back(i);
	
	do {
		stack<int> st;
		st.push(v[0]);
		for(int i = 0; i < N - 1; ++i) {
			int result = calc(st.top(), v[i+1], opr[nx[i]]);
			st.push(result);
		}
		mn = min(st.top(), mn);
		mx = max(st.top(), mx);
	} while(next_permutation(nx.begin(), nx.end()));
	
	cout << mx << "\n" << mn;
}
