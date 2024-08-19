#include <bits/stdc++.h>

using namespace std;
int mx = INT_MIN;
int y, x, v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	for(int i = 1; i <= 9; ++i) {
		for(int j = 1; j <= 9; ++j) {
			cin >> v;
			if(mx < v) {
				mx = v;
				y = i; x = j;
			}
		}
	}
	cout << mx << "\n";
	cout << y << " " << x;
}
