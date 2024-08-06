#include <bits/stdc++.h>

using namespace std;

int result[104], N, M;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	int a, b, c;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		for(int j = a; j <= b; ++j) result[j] = c;
	}
	for(int i = 1; i <= N; ++i) cout << result[i] << " ";
}
