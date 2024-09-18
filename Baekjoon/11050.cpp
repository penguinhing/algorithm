#include <bits/stdc++.h>

using namespace std;
int N, K;

int factorial(int n) {
	if(n == 1 || n == 0) return 1;
	return n * factorial(n - 1);
	
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	cout << (factorial(N) / (factorial(N-K) * factorial(K)));
}
