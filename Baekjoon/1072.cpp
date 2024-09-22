#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll X, Y, per, result = LLONG_MAX, mid, lo, hi;

bool check(ll mid) {
	ll a = X + mid, b = Y + mid;
	return per != ((ll)b * 100 / a);
}

int main() {
	cin >> X >> Y;
	per = Y * 100 / X;
	lo = 1, hi = INT_MAX;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			result = min(result, mid);
			hi = mid - 1;
		} else lo = mid + 1;
	}
	if (X == Y || result == LLONG_MAX) cout << -1;
	else cout << result;
}
