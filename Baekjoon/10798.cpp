#include <bits/stdc++.h>

using namespace std;
char n[5][15];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	for(int i = 0; i < 5; ++i) {
		cin >> n[i];
	}
	for(int i = 0; i < 15; ++i) {
		for(int j = 0; j < 5; ++j) {
			if(n[j][i] == '\0') continue;
			cout << n[j][i];
		}	
	}
}
