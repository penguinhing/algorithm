#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll S, C, mx = 0;
ll pa[1000004];
ll lo, hi, mid, result, cnt = 0;

bool check(ll mid) {
	ll num = 0;
	ll tmp = 0;
	ll startIdx = S;
	for(int i = 0; i < S; ++i) {
		if(num + (pa[i] / mid) > C) {
			tmp += pa[i] - (mid * ((pa[i] / mid) - (num + (pa[i] / mid) - C)));
			num = C;
			startIdx = i + 1;
			break;
		}else {
			num += pa[i] / mid;
			tmp += pa[i] % mid;
		}
	}
	if(num >= C && mx < mid) {
		for(int i = startIdx; i < S; ++i) {
			tmp += pa[i];
		}
		result = tmp;
		mx = mid;
	}
	return num >= C;
}

int main() {
	cin >> S >> C;
	for(int i = 0; i < S; ++i) {
		cin >> pa[i]; mx = max(mx, pa[i]);
	}
	lo = 1; hi = mx;
	mx = -1;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << result;
}
