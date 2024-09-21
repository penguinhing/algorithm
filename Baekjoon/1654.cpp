#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int K, N, a;
ll lo, hi, mid, hap = 0, result = 0;
vector<int> v;

bool check(ll mid) {
	int num = 0;
	for(int i = 0; i < v.size(); ++i) num += v[i] / mid;
	return num >= N;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> K >> N;
	
	for(int i = 0; i < K; ++i) {
		cin >> a; v.push_back(a);
		hap += a;
	}
	lo = 1; hi = hap;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			result = max(result, mid);
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << result;
}
