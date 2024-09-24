#include <bits/stdc++.h>

using namespace std;

int N, a;
int result[1000004] = { 0 };

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	int len = 0;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		auto it = lower_bound(result, result + len, a);
		if (*it == 0) ++len;
		*it = a;
	}
	cout << len;
}
