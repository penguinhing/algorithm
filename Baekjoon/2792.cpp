#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> v;

typedef long long ll;
ll hi, lo, mid, a, result = LONG_LONG_MAX;

bool check(ll mid) {
	ll num = 0;
	for(int i = 0; i < v.size(); ++i) {
		num += v[i] / mid;
		if(v[i] % mid) ++num;
	}
	return N >= num;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> a;
		v.push_back(a);
		hi = max(hi, a);
	}
	lo = 1;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			result = min(result, mid);
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << result;
}
