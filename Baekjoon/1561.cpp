#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;
ll a, hi, lo, mid, t = LLONG_MAX, result; 
vector<ll> ma;

bool check(ll mid) {
	ll d = M;
	for(int i = 0; i < M; ++i) d += mid / ma[i];
	return N <= d;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		cin >> a; ma.push_back(a);
	}
	if(N <= M) {
		cout << N; return 0;
	}
	
	lo = 1; hi = 60000000004;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if(check(mid)) {
			hi = mid - 1;
			t = min(mid, t);
		} else lo = mid + 1;
	}
	a = M;
	for(int i = 0; i < M; ++i) {
		a += (t - 1) / ma[i];
	}
	for(int i = 0; i < M; ++i) {
		if(t % ma[i] == 0) ++a;
		if(a == (ll)N) {
			cout << i+1; return 0;
		}
	}
	
}
