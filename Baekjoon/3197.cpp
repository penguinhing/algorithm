#include <bits/stdc++.h>

using namespace std;

int R, C;
char field[1504][1504];

queue<pair<int, int>> posSwan;
queue<pair<int, int>> tmpSwan;
queue<pair<int, int>> posWater;
queue<pair<int, int>> tmpWater;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int ny, nx;
int finY, finX;

void QClear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}

bool swanBFS() {
	while(!posSwan.empty()) {
		pair<int, int> pos = posSwan.front(); posSwan.pop();
		for(int i = 0; i < 4; ++i) {
			ny = dy[i] + pos.first;
			nx = dx[i] + pos.second;
			if(ny == finY && nx == finX) return true;
			if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if(field[ny][nx] == '.') {
				field[ny][nx] = 'L';
				posSwan.push({ny, nx});
			}
			else if(field[ny][nx] == 'X') {
				field[ny][nx] = 'x';
				tmpSwan.push({ny, nx});
			}
		}
	}
	posSwan = tmpSwan;
	QClear(tmpSwan);
	return false;
}

void water_melting() {
	while(!posWater.empty()) {
		pair<int, int> pos = posWater.front(); posWater.pop();
		for(int i = 0; i < 4; ++i) {
			ny = dy[i] + pos.first;
			nx = dx[i] + pos.second;
			if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if(field[ny][nx] == 'X' || field[ny][nx] == 'x') {
				tmpWater.push({ny, nx});
				field[ny][nx] = '.';
			}
		}
	}
	posWater = tmpWater;
	QClear(tmpWater);
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cin >> field[i][j];
			if(field[i][j] == 'L' && posSwan.size() == 0) posSwan.push({i, j});
			else if (field[i][j] == 'L') {
				finY = i;
				finX = j;
				posWater.push({i, j});
			}
			else if(field[i][j] == '.') posWater.push({i, j});
		}
	}

	int result = 0;
	while(true) {
		if(swanBFS()) {
			cout << result; break;
		}
	   water_melting();
	   ++result;
	}
}
