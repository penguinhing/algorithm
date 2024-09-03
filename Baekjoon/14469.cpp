#include <bits/stdc++.h>

using namespace std;
int N, a, b, total = 0;
vector<pair<int, int>> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	for(pair<int, int> value : v) {
		if(total >= value.first) total += value.second;
		else total = value.first + value.second;
	}
	
	cout << total;

}
