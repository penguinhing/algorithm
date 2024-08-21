#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	vector<int> result;
	int a, total = 0;
	for(int i = 0; i < 5; ++i) {
		cin >> a; result.push_back(a);
		total += a;
	}
	sort(result.begin(), result.end());
	cout << total / 5 << "\n";
	cout << result[2];
}
