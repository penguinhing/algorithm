#include <bits/stdc++.h>

using namespace std;

int N, result = 0, ny, nx;
vector<int> v;
int field[30][30] = { 0 };
int visited[30][30] = { 0 };
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	int count = 0;
	while(!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		++count;
		for(int i = 0; i < 4; ++i) {
			ny = pos.first + dy[i];
			nx = pos.second + dx[i];
			if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if(visited[ny][nx] == 1 || field[ny][nx] == 0) continue;
			q.push({ny, nx});
			visited[ny][nx] = 1;			
		}
	}
	return count;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	string a;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		for(int j = 0; j < a.length(); ++j) field[i][j] = a[j] - '0';
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(field[i][j] == 0 || visited[i][j] == 1) continue;
			v.push_back(bfs(i, j));
			++result;
		}
	}
	sort(v.begin(), v.end());
	cout << result << "\n";
	for(int i : v) cout << i << "\n";
	
}
