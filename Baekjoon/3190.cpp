#include <bits/stdc++.h>

using namespace std;
int N, K, L, a, b, s, x, y, result = 0;
queue<pair<int, int>> history;
char d;
int arrow = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int field[102][102];

void end_game() {
	cout << result;
	exit(0);
}

void move() {
	++result;
	x += dx[arrow];
	y += dy[arrow];
	
	if(y <= 0 || x <= 0 || y > N || x > N) end_game();
	if(field[y][x] == 7) end_game();
	
	if(field[y][x] != 1) {
		field[history.front().first][history.front().second] = 0;
		history.pop();
	}
	
	field[y][x] = 7;
	history.push({y, x});
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	y = 1; x = 1;
	field[1][1] = 7;
	history.push({1, 1});
	cin >> N >> K;
	for(int i = 0; i < K; ++i) {
		cin >> a >> b;
		field[a][b] = 1;
	}
	cin >> L;
	int time = 0;
	for(int i = 0; i < L; ++i) {
		cin >> s >> d;
		for(int j = 0; j < abs(s - time); ++j) move();
		
		if (d == 'D' && arrow == 0) arrow = 2;
		else if (d == 'D' && arrow == 2) arrow = 1;
		else if (d == 'D' && arrow == 1) arrow = 3;
		else if (d == 'D' && arrow == 3) arrow = 0;

		if (d == 'L' && arrow == 0) arrow = 3;
		else if (d == 'L' && arrow == 3) arrow = 1;
		else if (d == 'L' && arrow == 1) arrow = 2;
		else if (d == 'L' && arrow == 2) arrow = 0;
		time += result - time;
	}
	while (true) move();
}
