#include <bits/stdc++.h>

using namespace std;

long long N, l, r;
long long result = 0;
long long num[100004];
set<int> agg;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> num[i];
	
	l = 0; r = 0;
	agg.insert(num[0]);
	while (true) {
		if(r == N-1) {
			result += (r - l + 1) * (r - l + 1 + 1) / 2;
			break;
		}
		if(agg.find(num[r + 1]) != agg.end()) {
			result += r - l + 1;
			agg.erase(num[l++]);
		} else{
			agg.insert(num[++r]);
		}
	}
	cout << result;
}
