#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int v[6] = {1, 1, 2, 2, 2, 8};
	int n;
	for(int i = 0; i < 6; ++i) {
		cin >> n;
		cout << v[i] - n << " ";
	}
}
