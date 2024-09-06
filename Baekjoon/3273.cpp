#include <bits/stdc++.h>

using namespace std;
long long N, X, l, r;
vector<long long> v;
long long result = 0;
int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int a;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		v.push_back(a);
	}
	cin >> X;
	sort(v.begin(), v.end());
	
	l = 0; r = v.size()-1;
	while(true) {
		if (l == r) break;
		if(v[l]+v[r] == X) {
			++result;
		}
		if(v[l]+v[r] >= X) --r;
		else ++l;
	}
	cout << result;
}
