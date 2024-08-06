#include <bits/stdc++.h>

using namespace std;

int N;
typedef long long ll;

ll fac(int N) {
	if (N <= 1) return 1;
	return N * fac(N - 1);
}

int main() {
	cin >> N;
	cout << fac(N);
}
