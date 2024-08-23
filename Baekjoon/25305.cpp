#include <bits/stdc++.h>

using namespace std;
int n, k, v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> n >> k;
	vector<int> result;
	for(int i = 0; i < n; ++i) {
		cin >> v;
		result.push_back(v);
	}	
	sort(result.begin(), result.end());
	cout << result[n - k];
	
}
