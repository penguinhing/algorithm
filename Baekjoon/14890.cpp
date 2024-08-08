#include <bits/stdc++.h>

using namespace std;
int N, L;
int result = 0;
int field[104][104];
int visited[104][104];

bool colCheck(int y, int x) {
	if (abs(field[y-1][x] - field[y][x]) > 1) return false;
	
	
	if(field[y-1][x] < field[y][x]) {
		if (y - L < 0) return false;
		
		for(int k = y - L; k < y; ++k) {
			if(visited[k][x] == 1) return false;
			visited[k][x] = 1;
		}
	}
	else if(field[y-1][x] > field[y][x]) {
		if (y + L - 1 >= N) return false;
		
		for(int k = y; k < y + L; ++k) {
			if(visited[k][x] == 1) return false;
			visited[k][x] = 1;
		}
	}
	return true;	
	
}

bool rowCheck(int y, int x) {
	if (abs(field[y][x-1] - field[y][x]) > 1) return false;
	if(field[y][x-1] < field[y][x]) {
		if (x - L < 0) return false;
		
		for(int k = x - L; k < x; ++k) {
			if(visited[y][k] == 1) return false;
			visited[y][k] = 1;
		}
	}
	else if(field[y][x-1] > field[y][x]) {
		if (x + L - 1 >= N) return false;
		
		for(int k = x; k < x + L; ++k) {
			if(visited[y][k] == 1) return false;
			visited[y][k] = 1;
		}
	}
	return true;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> L;
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cin >> field[i][j];
		}
	}
	
	int count;
	for(int i = 0; i < N; ++i) {
		count = 2;
		for(int j = 0; j < N; ++j) visited[i][j] = 0;
		for(int j = 1; j < N; ++j) {
			if(!rowCheck(i, j)) {
				--count; break;
			}
		}
		
		for(int j = 0; j < N; ++j) visited[j][i] = 0;
		for(int j = 1; j < N; ++j) {
			if(!colCheck(j, i)) {
				--count; break;
			}
		}
		result += count;
	}
	cout << result;		
}
