#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll T, N, M, result, k;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	while(T--) {
		cin >> N >> M;
		result = 1;
		k = 1;
		for(int i = M; i > M - N; --i) {
			result *= i;
			result /= k++;
		}
		cout << result << "\n";
	}
}
