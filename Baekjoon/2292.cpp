#include <bits/stdc++.h>

using namespace std;
int N;

int main() {
	cin >> N;
	int v = 1;
	int cnt = 1;
	while(v < N) v += 6 * cnt++;
	cout << cnt;
}
