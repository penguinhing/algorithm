#include <bits/stdc++.h>

using namespace std;
int T, A, B, v, result;


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	for(int d = 0; d < T; ++d) {
		result = 0;
		vector<int> _a;
		vector<int> _b;
		cin >> A >> B;
		for(int i = 0; i < A; ++i) cin >> v, _a.push_back(v);
		for(int i = 0; i < B; ++i) cin >> v, _b.push_back(v);
		
		sort(_b.begin(), _b.end());
		
		for(int i = 0; i < A; ++i) {
			auto it = lower_bound(_b.begin(), _b.end(), _a[i]) - _b.begin();
			result += it;
		}
		cout << result << "\n";
	}
}
