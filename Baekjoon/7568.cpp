#include <bits/stdc++.h>

using namespace std;
int N, a, b;
vector<pair<int, int>> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	for(int i = 0; i < v.size(); ++i) {
		int count = 0;
		for(int j = 0; j < v.size(); ++j) {
			if(i == j) continue;
			if(v[i].first < v[j].first && v[i].second < v[j].second) ++count;
		}
		cout << count + 1 << " ";
	}
}
