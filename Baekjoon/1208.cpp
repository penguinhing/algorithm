#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N, S, arr[42], result = 0, z = 0;
map<ll, ll> mp;

void go(int init, int cond) {
	for (int i = 1; i < (1 << cond); ++i) {
		ll tmp = 0;
		for (int j = 0; j < cond; ++j) {
			if (i & (1 << j)) tmp += arr[init + j];
		}
		if (init != 0) {
			if (S == tmp) ++z;
			if (tmp == 0) result += mp[S];
			else if (tmp > 0) result += mp[S - tmp];
			else if (tmp < 0) result += mp[abs(tmp) + S];
		}
		else ++mp[tmp];
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	go(0, N / 2);
	go(N / 2, N - N / 2);
	cout << result + mp[S] + z << "\n";
}
