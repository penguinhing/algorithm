#include <bits/stdc++.h>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

struct Piece {
	int number;
	int arrow;
};

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int N, K, visited[15][15], a, b, c, ny, nx, result;
vector<Piece> field[15][15];

void go(int m) { 
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int x = 0; x < field[i][j].size(); ++x) {
				if(field[i][j][x].number != m) continue;
				ny = i + dy[field[i][j][x].arrow];
				nx = j + dx[field[i][j][x].arrow];
				if(ny > N || nx > N || ny < 1 || nx < 1 || visited[ny][nx] == BLUE) {
					field[i][j][x].arrow ^= 1;
					ny = i + dy[field[i][j][x].arrow];
					nx = j + dx[field[i][j][x].arrow];
					if(ny > N || nx > N || ny < 1 || nx < 1 || visited[ny][nx] == BLUE) return;
				}
				if(visited[ny][nx] == WHITE) {
					for(int d = x; d < field[i][j].size(); ++d) field[ny][nx].push_back(field[i][j][d]);	
				}
				else if(visited[ny][nx] == RED) {
					for(int d = field[i][j].size() - 1; d >= x; --d) field[ny][nx].push_back(field[i][j][d]);
				}
				if(field[ny][nx].size() >= 4){
					cout << result;
					exit(0);
				}
				field[i][j].erase(field[i][j].begin() + x, field[i][j].end());
				return;
			}
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) cin >> visited[i][j];
	}
	for(int i = 1; i <= K; ++i) {
		cin >> a >> b >> c;
		Piece p{i, c - 1};
		field[a][b].push_back(p);
	}
	for(int i = 1; i <= 1000; ++i) {
		result = i;
		for(int j = 1; j <= K; ++j) go(j);
	}
	cout << -1;
}
