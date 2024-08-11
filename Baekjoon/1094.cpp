#include <bits/stdc++.h>

using namespace std;

int main() {
	int X;
	cin >> X;
	int result = 0;
	for(int i = 0; i < 7; ++i) {
		if((1 << i) & X) ++result;
	}
	cout << result;
}
