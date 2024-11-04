#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N, M, a, b, c, dist[1004], start, last, cost, idx;
map<int, map<int, int>> mp;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	fill(dist, dist + 1004, INF);
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		if(mp[a].find(b) != mp[a].end()) mp[a][b] = min(mp[a][b], c);
		else mp[a][b] = c;
	}
	cin >> start >> last;
	pq.push({0, start});
	dist[start] = 0;
	while(!pq.empty()) {
		idx = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		for(auto it : mp[idx]) {
			if (dist[it.first] > cost + mp[idx][it.first]) {
				dist[it.first] = cost + mp[idx][it.first];
				pq.push({dist[it.first], it.first});
			}
		}
	}
	cout << dist[last];
}
