#include <bits/stdc++.h>

using namespace std;
int N, v, result = -1000;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	int sum = 0;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		sum += v;
		result = max(sum, result);
		if(sum < 0) sum = 0;
	}
	cout << result;
}
