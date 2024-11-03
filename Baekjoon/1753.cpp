#include <bits/stdc++.h>
#define INF 31000000
using namespace std;

int V, E, start, a, b, c, dist[20004], cost, idx;
map<int, map<int, int>> mp;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> V >> E >> start;
	for(int i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		if(mp[a].find(b) != mp[a].end()) mp[a][b] = min(mp[a][b], c);
		else mp[a][b] = c;
	}
	fill(dist, dist + 20004, INF);
	pq.push({0, start});
	dist[start] = 0;
	while(!pq.empty()) {
		cost = pq.top().first;
		idx = pq.top().second;
		pq.pop();
		for(auto it : mp[idx]) {
			if (dist[it.first] > cost + mp[idx][it.first]) {
				dist[it.first] = cost + mp[idx][it.first];
				pq.push({dist[it.first], it.first});
			}
		}
	}
	for(int i = 1; i <= V; ++i) {
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
