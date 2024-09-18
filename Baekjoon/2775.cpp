#include <bits/stdc++.h>

using namespace std;
int arr[15][15];
int T, a, b;

int main() {
	for(int i = 1; i <= 14; ++i) arr[0][i] = i;
	
	for(int i = 1; i <= 14; ++i) {
		int cnt = 0;
		for(int j = 1; j <= 14; ++j) {
			cnt += arr[i-1][j];
			arr[i][j] = cnt;
		}
	}
	cin >> T;
	for(int i = 0; i < T; ++i) {
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
}
