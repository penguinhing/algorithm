#include <bits/stdc++.h>

using namespace std;
int N, a, b, lis[104] = { 0 }, range = 0, cnt = 0;
vector<pair<int, int>> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b; v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i) {
		auto it = lower_bound(lis, lis + range, v[i].second);
		if(*it == 0) ++range;
		*it = v[i].second;
	}
	for(int i = 0; i < N; ++i) {
		if(lis[i] == 0) break;
		++cnt;
	}
	cout << N - cnt;
}

