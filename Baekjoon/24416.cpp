#include <bits/stdc++.h>

using namespace std;
int N, _a = 1;

int a(int N) {
	if(N == 1 || N == 2) return 1;
	++_a;
	return a(N - 1) + a(N - 2);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	a(N);
	cout << _a << " " << N - 2;
}
