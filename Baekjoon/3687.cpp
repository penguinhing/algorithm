#include <bits/stdc++.h>

using namespace std;
string maxValues[104], minValues[104][2], k;
int T, N;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	maxValues[2] = '1'; maxValues[3] = '7';
	for(int i = 4; i <= 100; ++i) maxValues[i] = maxValues[i - 2] + '1';
	
	minValues[2][0] = "1";
	minValues[3][0] = "7";
	minValues[4][0] = "4";
	minValues[5][0] = "2";
	minValues[6][0] = "6";
	minValues[6][1] = "0";
	minValues[7][0] = "8";
	
	for(int i = 8; i <= 100; ++i) {
		for(int j = 2; j <= 7; ++j) {
			if (i - j < 2) continue;
			for(int z = 0; z <= 1; ++z) {
				if (minValues[i - j][z].empty()) continue;
				k = minValues[j][0];
				k += minValues[i - j][z];
				if(minValues[i][0].empty()) minValues[i][0] = k;
				else minValues[i][0] = to_string(min(stoll(minValues[i][0]), stoll(k)));			
			}
		}
		for(int j = 2; j <= 7; ++j) {
			if (i - j < 2 || minValues[j][1].empty()) continue;
			for(int z = 0; z <= 1; ++z) {
				if (minValues[i - j][z].empty()) continue;
				k = minValues[j][1];
				k += minValues[i - j][z];
				if(minValues[i][1].empty()) minValues[i][1] = k;
				else {
					string tmp1 = "1", tmp2 = "1";
					tmp1 += k;
					tmp2 += minValues[i][1];
					if(stoll(tmp1) < stoll(tmp2)) minValues[i][1] = k;
				}			
			}
		}
	}	
	for(int i = 0; i < T; ++i) {
		cin >> N;
		cout << minValues[N][0] << " " << maxValues[N] << "\n";
	}
}
