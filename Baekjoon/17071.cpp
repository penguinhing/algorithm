#include <bits/stdc++.h>

using namespace std;
int N, K;
int result;
int ms = 0;
int sni[600004][2];

int bfs() {
	if (N == K) return 0;
	queue<pair<int, int>> q;
	q.push({N, 0});
	int vs[3], idx;
	sni[N][0] = 1;
	int nm = -1;
	while(!q.empty()) {
		pair<int, int> v = q.front(); q.pop();
		if (v.second != nm) { // 현재 시간 저장 
			nm = v.second;
			ms = ms + nm;
		}
		
		if(K+ms > 500000) return -1;
		if(sni[K+ms][nm % 2]) {
			return nm;
		}

		vs[0] = max(0, v.first - 1);
		vs[1] = v.first + 1;
		vs[2] = v.first * 2;
		
		for(int i = 0; i < 3; ++i) {
			if(vs[i] > 500000) continue;
			idx = ((v.second + 1) % 2);
			if(sni[vs[i]][idx] == 0) { // 홀짝 여부가 저장되지 않은 경우 
				sni[vs[i]][idx] = 1; // 0 짝수 1 홀수
				q.push({vs[i], v.second + 1});
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	int result = bfs();
	cout << result << "\n";
}
