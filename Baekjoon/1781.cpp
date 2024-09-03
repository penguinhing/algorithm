#include <bits/stdc++.h>

using namespace std;
int N, a, b, result = 0;
vector<int> v[200002];
priority_queue<int> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	for(int i = N; i > 0; --i) {
		for(int j = 0; j < v[i].size(); ++j) {
			pq.push(v[i][j]);
		}
		
		if(pq.size()) {
			result += pq.top(); pq.pop();
		}	
	}
	cout << result;
}
