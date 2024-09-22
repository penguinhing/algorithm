#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Obj {
	int type;
	int a;
	int h;
};

int N, at;
ll lo, hi, mid, result = LLONG_MAX;
vector<Obj> mob;

bool check(ll mid) {
	ll tmpAt = at, damage;
	ll maxHealth = mid;
	for (Obj m : mob) {
		if (m.type == 1) {
			damage = ((m.h / tmpAt) + ((m.h % tmpAt >= 1) ? 1 : 0) - 1) * m.a;
			mid -= damage;
			if (mid <= 0) return false;
		}
		else {
			tmpAt += m.a;
			mid = min(maxHealth, mid + m.h);
		}
	}
	return true;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> at;
	for (int i = 0; i < N; ++i) {
		Obj m;
		cin >> m.type >> m.a >> m.h;
		mob.push_back(m);
	}
	lo = 1; hi = LLONG_MAX - 1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			result = min(mid, result);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << result;
}
