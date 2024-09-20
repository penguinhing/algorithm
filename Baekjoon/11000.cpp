#include <bits/stdc++.h>

using namespace std;
int N, a, b;
pair<int, int> t;
vector<pair<int ,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for(int i = 1; i < v.size(); ++i) {
		 t = v[i];
		 if (pq.top() <= t.first) pq.pop();
		 pq.push(t.second);
	}
	cout << pq.size();
}
