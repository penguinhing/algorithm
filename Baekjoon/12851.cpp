#include <bits/stdc++.h>

using namespace std;
int N, K;
pair<int, int> result = {-1, -1};
int visited[200004];
map<pair<int, int>, int> mp;

int bfs() {
	queue<pair<int, int>> q;
	q.push({N, 0});
	int vs[3];
	visited[N] = 1;
	mp[{N, 0}] = 1;
	while(!q.empty()) {
		pair<int, int> v = q.front(); q.pop();
		if(v.first == K) return v.second;
		
		vs[0] = max(0, v.first - 1);
		vs[1] = min(200000, v.first + 1);
		vs[2] = min(200000, v.first * 2);
		
		for(int i = 0; i < 3; ++i) {
			if (visited[vs[i]] == 0) {
				q.push({vs[i], v.second + 1});
				visited[vs[i]] = 1;
			}
			mp[{vs[i], v.second+1}] += mp[{v.first, v.second}];
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	int result = bfs();
	cout << result << "\n";
	cout << mp[{K, result}];
}
