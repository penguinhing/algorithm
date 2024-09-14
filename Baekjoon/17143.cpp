#include <bits/stdc++.h>

using namespace std;

int R, C, M, result = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int visited[104][104] = { 0 };

class Shark {
public:
	int y;
	int x;
	int arrow;
	int speed;
	int size;
	bool dead;

	void move() {
		int remain = this->speed;
		int nx = this->x;
		int ny = this->y;
		while (remain != 0) {
			if(arrow == 1) {
				ny -= remain;
				if(1 > ny) {
					remain = abs(ny) + 1;
					ny = 1;
					this->arrow = 2;
				} else remain = 0;
			}
			else if(arrow == 2) {
				ny += remain;
				if (ny > R) {
					remain = ny - R;
					ny = R;
					this->arrow = 1;
				}
				else remain = 0;		
			}

			if (arrow == 3) {
				nx += remain;
				if (nx > C) {
					remain = nx - C;
					nx = C;
					this->arrow = 4;
				}
				else remain = 0;
			}
			else if (arrow == 4) {
				nx -= remain;
				if (nx < 1) {
					remain = abs(nx) + 1;
					nx = 1;
					this->arrow = 3;
				}
				else remain = 0;
			}
		}
		this->x = nx;
		this->y = ny;
	}
};

Shark shark[10005];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> shark[i].y >> shark[i].x >> shark[i].speed >> shark[i].arrow >> shark[i].size;
		shark[i].dead = false;
		visited[shark[i].y][shark[i].x] = i;
	}
	for (int i = 1; i <= C; ++i) {
		
		for(int j = 1; j <= R; ++j) {
			if(visited[j][i] == 0) continue;
			result += shark[visited[j][i]].size;
			shark[visited[j][i]].dead = true;
			break;
		}
		
		for (int j = 1; j <= M; ++j) {
			if(shark[j].dead) continue;
			shark[j].move();
		}
		
		int tmp[104][104] = { 0 };
		for(int j = 1; j <= M; ++j) {
			if(shark[j].dead) continue;
			if (tmp[shark[j].y][shark[j].x] != 0) {
				int pairIdx = tmp[shark[j].y][shark[j].x];
				if (shark[j].size > shark[pairIdx].size) {
					shark[pairIdx].dead = true;
					tmp[shark[j].y][shark[j].x] = j;
				}
				else shark[j].dead = true;
			}
			else tmp[shark[j].y][shark[j].x] = j;
		}
		for(int j = 1; j <= R; ++j) {
			for(int s = 1; s <= C; ++s) {
				visited[j][s] = tmp[j][s];
			}
		}
	}
	cout << result;
}
