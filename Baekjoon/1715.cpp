#include <bits/stdc++.h>

using namespace std;
int N, v, a, tmp, result = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v; pq.push(v);
	}
	while(pq.size() > 1) {
		tmp = pq.top(); pq.pop();
		a = tmp + pq.top(); pq.pop();
		result += a;
		pq.push(a);
	}
	cout << ((N == 1) ? 0 : result);
}
