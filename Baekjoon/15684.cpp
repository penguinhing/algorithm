#include <bits/stdc++.h>

using namespace std;

int N, M, H;
int visited[35][35];
int limit;

void print(int m) {
	cout << m;
	exit(0);
}

bool check() { // i번 사다리 결과가 i 인지 확인 
	for(int i = 1; i < N; ++i) {
		int now_pos = i;
		for(int j = 1; j <= H; ++j) {
			if(visited[j][now_pos-1] == 1) {
				--now_pos;
			}
			else if(visited[j][now_pos] == 1) {
				++now_pos;
			}
		}
		if(now_pos != i) return false;
	}
	return true;
}

void dfs(int startY, int depth) {
	if(depth >= limit) {
		if(check()) print(depth);
		return;
	}
	
	for(int i = startY; i <= H; ++i) {
		for(int j = 1; j < N; ++j) {
            // 사다리 놓을 수 있는지 판별 
			if(visited[i][j] == 0 && visited[i][j+1] == 0 && visited[i][j-1] == 0)	{ 
				visited[i][j] = 1;
				dfs(i, depth + 1);
				visited[i][j] = 0;
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> N >> M >> H;
	
	int a, b;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		visited[a][b] = 1;
	}
	for(limit = 0; limit <= (H * (N - 1)) - M; ++limit) {
		if(limit > 3) print(-1);
		dfs(1, 0);
	}
	cout << -1;
}
