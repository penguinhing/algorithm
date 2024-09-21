#include <bits/stdc++.h>

using namespace std;
int T, H, W, N, tmp, cnt;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	for(int d = 0; d < T; ++d) {
		cin >> H >> W >> N;

		cnt = 0;
		for(int i = 1; i <= W; ++i) {
			tmp = i;
			for(int j = 1; j <= H; ++j) {
				tmp += 100; ++cnt;
				if(cnt == N) break;
			}
			if(cnt == N) {
				cout << tmp << "\n";break;
			}
		}

	}
}
