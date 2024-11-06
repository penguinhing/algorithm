#include <bits/stdc++.h>

using namespace std;
string N;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N.length(); ++i) {
		if(N[i] >= 'a') cout << (char)(N[i] - 32);
		else cout << (char)(N[i] + 32);
	}
}
