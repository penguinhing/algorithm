#include <bits/stdc++.h>

using namespace std;
int N, M, a, b;
int arr[104];
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) arr[i] = i;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		reverse(&arr[a], &arr[b]+1);
	}
	for(int i = 1; i <= N; ++i) cout << arr[i] << " ";
}
