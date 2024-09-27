#include <bits/stdc++.h>

using namespace std;
int N, T;
int arr[10002];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	fill(arr, arr + 10002, 1);
	for (int i = 2; i <= 10000; ++i) arr[i] += arr[i - 2];
	for (int i = 3; i <= 10000; ++i) arr[i] += arr[i - 3];
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << arr[N] << "\n";
	}
}
