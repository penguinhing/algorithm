#include <bits/stdc++.h>

using namespace std;
int N, a;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		if (a == 0) {
			cout << (pq.empty() ? 0 : pq.top().second) << "\n";
			if (!pq.empty()) pq.pop();
		}
		else pq.push({ abs(a), a });
	}
}