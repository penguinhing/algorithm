#include <bits/stdc++.h>

using namespace std;

int N;

class Pos {
	public:
		int x;
		int y;
		Pos() {}		
		Pos(int x, int y) {
			this->x = x;
			this->y = y;
		}
	bool operator <(Pos &pos) {
		if(this->x == pos.x) {
			return this->y < pos.y;
		}
		return this->x < pos.x;
	}
};

int main() {
	cin >> N;
	Pos *p = new Pos[N];
	int x, y;
	for(int i = 0; i < N; ++i) {
		cin >> x >> y;
		p[i] = Pos(x, y);
	}
	sort(p, p + N);
	for(int i = 0; i < N; ++i) {
		cout << p[i].x << " " << p[i].y << "\n";
	}
}
