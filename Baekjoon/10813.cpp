#include <bits/stdc++.h>

using namespace std;

int arr[104];
int N, M;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) arr[i] = i;
	int a, b, tmp;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b;
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}	
	for(int i = 1; i <= N; ++i) cout << arr[i] << " ";
}
