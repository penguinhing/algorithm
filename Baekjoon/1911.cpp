#include <bits/stdc++.h>

using namespace std;
int N, L, a, b, dis, last, result = 0, tm;
vector<pair<int, int>> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> L;
	
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	
	last = -1;
	for(int i = 0; i < v.size(); ++i) {
		if (last >= v[i].second) continue;
		if(last >= v[i].first) {
			dis = v[i].second - (last + 1);
			last = last + (ceil((double)dis / L) * L);
		} else {
			dis = v[i].second - v[i].first;
			last = v[i].first + (ceil((double)dis / L) * L - 1); 
		}
 		result += ceil((double)dis / L);
	}
	cout << result;
}
