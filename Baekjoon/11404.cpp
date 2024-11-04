#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int dist[101][101], N, M, a, b, c;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	fill(&dist[0][0], &dist[100][101], INF);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) dist[i][i] = 0;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for(int k = 1; k <= N; ++k) {
		for(int s = 1; s <= N; ++s) {
			for(int e = 1; e <= N; ++e) {
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
			}
		}
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			if(dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}
