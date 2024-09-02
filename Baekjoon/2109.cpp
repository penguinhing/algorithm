#include <bits/stdc++.h>

using namespace std;
int N, result = 0;
priority_queue<int> pq;
vector<int> lst[10004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	int a, b;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		lst[b].push_back(a);
	}
	
	for(int i = 10000; i != 0; --i) {
		for(int j = 0; j < lst[i].size(); ++j) {
			pq.push(lst[i][j]);
		}
		if(pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}
