#include <bits/stdc++.h>

using namespace std;
int N;
int arr[1000004];

int go(int x) {
	if(arr[x] != 0) return arr[x];
	if(x == 1) return 0;
	int v = go(x - 1);
	if(x % 2 == 0) v = min(v, go(x / 2));
	if(x % 3 == 0) v = min(v, go(x / 3));
	arr[x] = 1 + v;
	return arr[x];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	arr[2] = 1; arr[3] = 1;
	cout << go(N);
}
