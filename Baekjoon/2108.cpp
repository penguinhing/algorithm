#include <bits/stdc++.h>

using namespace std;
int N, a, mx = INT_MIN;
vector<int> v;
vector<int> t;
map<int, int> mp;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		v.push_back(a);
		++mp[a];
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	int zxc = round(sum / (float)N);
	cout << zxc << "\n";
	
	sort(v.begin(), v.end());
	cout << v[N / 2] << "\n";
	
	for(auto it : mp) {
		if (mx < mp[it.first]) {
			mx = mp[it.first];
			t.clear(); t.push_back(it.first);
			continue;
		}
		if (mx == mp[it.first]) t.push_back(it.first);
	}
	if(t.size() > 1) {
		sort(t.begin(), t.end());
		cout << t[1] << "\n";
	} else cout << t[0] << "\n";
	
	cout << v[v.size()-1] - v[0] << "\n";
}
