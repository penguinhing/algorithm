#include <bits/stdc++.h>

using namespace std;

int arr[7] = { 2, 3, 5, 7, 11, 13, 17 };
double score[2], dp[20][2][20], hapA = 0.0, hapB = 0.0;;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> score[0] >> score[1];
	score[0] = score[0] * 0.01;
	score[1] = score[1] * 0.01;

	dp[1][0][0] = 1 - score[0];
	dp[1][1][0] = 1 - score[1];
	dp[1][0][1] = score[0];
	dp[1][1][1] = score[1];
	for (int i = 2; i <= 18; ++i) {
		dp[i][0][0] = dp[i - 1][0][0] * (1 - score[0]);
		dp[i][1][0] = dp[i - 1][1][0] * (1 - score[1]);
	}
	
	for (int i = 2; i <= 18; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 1; k <= i; ++k) {
				dp[i][j][k] = (dp[i - 1][j][k - 1] * score[j]) + (dp[i - 1][j][k] * (1 - score[j])) ;
			}
		}
	}
	for (int i = 0; i < 7; ++i) {
		hapA += dp[18][0][arr[i]];
		hapB += dp[18][1][arr[i]];
	}
	cout << fixed << setprecision(16) << 1 - (1 - hapA) * (1 - hapB);
}
