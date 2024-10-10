#include <bits/stdc++.h>

using namespace std;
int N, L[22], K[22];
int result = 0;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> L[i];
	for(int i = 0; i < N; ++i) cin >> K[i];
	for(int i = 1; i < (1 << N); ++i) {
		int health = 100;
		int value = 0;
		for(int j = 0; j < N; ++j) {
			if((1 << j) & i) {
				health -= L[j];
				value += K[j];
			}
		}
		if(health <= 0) continue;
		result = max(result, value);
	}
	cout << result;
}
