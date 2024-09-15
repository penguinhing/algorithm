#include <bits/stdc++.h>

using namespace std;

int field[200][200] = { 0 };
int x, y, d, g, N, ny, nx, result = 0;
vector<int> arrow[4][11];
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};

void create(int d) {
	arrow[d][0].push_back(d);
	arrow[d][1].push_back((d + 1) % 4);
	arrow[d][2].push_back( (arrow[d][1][0] + 1) % 4);
	arrow[d][2].push_back(arrow[d][1][0]);
	for(int i = 3; i <= 10; ++i) {
		for(int j = arrow[d][i-1].size() - 1; j >= 0 ; --j) {
			arrow[d][i].push_back((arrow[d][i-1][j] + 1) % 4);
		}
		for(int j = 0; j < arrow[d][i-1].size(); ++j) {
			arrow[d][i].push_back(arrow[d][i-1][j]);
		}
	}
}

void draw(int x, int y, int d, int g) {
	field[y][x] = 1;
	ny = y, nx = x;
	for(int i = 0; i <= g; ++i) {
		for(int j = 0; j < arrow[d][i].size(); ++j) {
			if(arrow[d][i][j] == 0) ++nx;
			else if(arrow[d][i][j] == 1) --ny;
			else if(arrow[d][i][j] == 2) --nx;
			else if(arrow[d][i][j] == 3) ++ny;
			field[ny][nx] = 1;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < 4; ++i) create(i);

	for(int i = 0; i < N; ++i) {
		cin >> x >> y >> d >> g;
		draw(x, y, d, g);
	}
	
	bool flag;
	for(int i = 0; i < 200; ++i) {
		for(int j = 0; j < 200; ++j) {
			if(field[i][j] == 0) continue;
			flag = true;
			for(int d = 0; d < 3; ++d) {
				ny = i + dy[d];
				nx = j + dx[d];
				if(200 <= ny || nx >= 200 || field[ny][nx] == 0) {
					flag = false; break;
				}
			}
			if(flag) ++result;
		}
	}
	cout << result;
	
}
