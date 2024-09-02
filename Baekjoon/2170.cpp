#include <bits/stdc++.h>

using namespace std;
int N, a, b, tmp;
long long result = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		if(a == b) continue;
		if(a > b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		
		pq.push({a, b});
	}
	
	int l = INT_MIN, r = INT_MIN;
	while(pq.size()) {
		pair<int, int> pos = pq.top(); pq.pop();
		if(pos.first <= r) {
			if(pos.second <= r) continue;
	
			result += pos.second - r;
		}
		else {
			result += pos.second - pos.first;
		}
		l = pos.first;
		r = pos.second;
	}
	cout << result;
}
