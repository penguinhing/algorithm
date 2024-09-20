#include <bits/stdc++.h>

using namespace std;
int N, v, result = 0;
priority_queue<int, vector<int>, greater<int>> pqA;
priority_queue<int> pqB;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v; pqA.push(v);
	}
	for(int i = 0; i < N; ++i) {
		cin >> v; pqB.push(v);
	}
	while(!pqB.empty()) {
		result += pqB.top() * pqA.top();
		pqB.pop(); pqA.pop();
	}
	cout << result;
}

