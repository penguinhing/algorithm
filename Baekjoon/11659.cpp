#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;

int arr[100004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] = arr[i-1] + arr[i];
	}
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << arr[b] - arr[a-1] << "\n";
	}
}
