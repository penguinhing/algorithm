#include <bits/stdc++.h>

using namespace std;
int A, B, v, result = 0;

vector<int> _a;
vector<int> _b;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> A >> B;
	for(int i = 0; i < A; ++i) cin >> v, _a.push_back(v);
	for(int i = 0; i < B; ++i) cin >> v, _b.push_back(v);
	sort(_b.begin(), _b.end());
	for(int i = 0; i < _a.size(); ++i) {
		auto it = lower_bound(_b.begin(), _b.end(), _a[i]) - _b.begin();
		if(_a[i] == _b[it]) ++result;
	}
	cout << A + B - result * 2;
}
