#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, e, f, x, y;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> a >> b >> c >> d >> e >> f;
	
	for(int x = -999; x <= 999; ++x) {
		for(int y = -999; y <= 999; ++y) {
			if( (a * x) + (b * y) == c && (d * x) + (e * y) == f) {
				cout << x << " " << y;
				return 0;
			}
		}
	}
}
