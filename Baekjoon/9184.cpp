#include <bits/stdc++.h>

using namespace std;
int a, b, c;
map<int, map<int, map<int, int>>> dp;

int w(int a, int b, int c) {
	if (dp[a][b].find(c) != dp[a][b].end()) return dp[a][b][c];
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	else if(a > 20 || b > 20 || c > 20) dp[a][b][c] = w(20, 20, 20);
	else if(a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c- 1);
	return dp[a][b][c];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	while (true) {
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}
