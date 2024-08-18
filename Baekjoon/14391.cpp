#include <bits/stdc++.h>

using namespace std;
int row, col;
char field[6][6];
int visited[6][6];
int result = INT_MIN;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> row >> col;
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) cin >> field[i][j];
	}
	int _r, _c;
	for(int i = 0; i < (1 << (row*col)); ++i) {
		for(int j = 0; j < (row * col); ++j) {
			if((1 << j) & i) {
				_r = j / col;
				_c = j % col;
				visited[_r][_c] = 1;
			}
		}
		int hap = 0;
		for(int r = 0; r < row; ++r) {
			string value = "0";
			for(int c = 0; c < col; ++c) {
				if(visited[r][c] == 1) {
					hap += stoi(value);
					value = "0";
				} else value += field[r][c];
			}
			hap += stoi(value);
		}
		
		for(int c = 0; c < col; ++c) {
			string value = "0";
			for(int r = 0; r < row; ++r) {
				if(visited[r][c] == 0) {
					hap += stoi(value);
					value = "0";
				} else value += field[r][c];
			}
			hap += stoi(value);
		}
		fill(&visited[0][0], &visited[5][6], 0);
		result = max(hap, result);
	}
	cout << result;	
}
