#include <bits/stdc++.h>

using namespace std; 

int v[32];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int n;
	for(int i = 0; i < 28; ++i) {
		cin >> n;
		v[n] = 1;
	}
	for(int i = 1; i <= 30; ++i) {
		if (v[i] == 0) cout << i << "\n";
	}
}
