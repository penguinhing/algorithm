#include <bits/stdc++.h>

using namespace std;
int N, a, b;
int score[2] = {100, 100};
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		if(a > b) score[1] -= a;
		else if(a < b) score[0] -= b;
	}
	cout << score[0] << "\n" << score[1];
}
