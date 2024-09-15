#include <bits/stdc++.h>

using namespace std;
int N, M, K, v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		queue<pair<int, bool>> q;
		priority_queue<int> pq;
		
		cin >> M >> K;
		for(int j = 0; j < M; ++j) {
			cin >> v;
			if(j == K) q.push({v, true});
			else q.push({v, false});
			pq.push(v);
		}
		int count = 0;
		while(!q.empty()) {
			if(q.front().first < pq.top()) {
				q.push(q.front());
			}
			else {
				++count;
				pq.pop();
				if(q.front().second) {
					cout << count << "\n";
					break;
				}
			}
			q.pop();
		}
	}
	
}
