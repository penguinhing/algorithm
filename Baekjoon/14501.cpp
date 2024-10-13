#include<bits/stdc++.h>
using namespace std;
int N, a, b, result = 0;
vector<pair<int, int>> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	for (int i = 0; i < (1 << N); ++i) {
		int ret = 0, lastDay = 0;
		for (int j = 0; j < N; ++j) {
			if (j + v[j].first > N) continue;
			if (i & (1 << j) && j >= lastDay) {
				lastDay = j + v[j].first;
				ret += v[j].second;
			}
		}
		result = max(ret, result);
	}
	cout << result;
}
