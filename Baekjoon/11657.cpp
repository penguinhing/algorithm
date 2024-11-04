#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
ll N, M, a, b, c, dist[504], from, to, cost;
pair<pair<ll, ll>, ll> v[6004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		v[i].first.first = a;
		v[i].first.second = b;
		v[i].second = c;
	}
	fill(dist, dist + 504, INF);
	dist[1] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j) {
			from = v[j].first.first;
			to = v[j].first.second;
			cost = v[j].second;
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				if (i == N) {
					cout << "-1";
					return 0;
				}
				dist[to] = dist[from] + cost;
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
}
