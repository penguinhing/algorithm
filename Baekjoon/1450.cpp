#include <bits/stdc++.h>

using namespace std;
int N, C, arr[32], result = 0;
vector<int> v1, v2;

void go(int here, int end, vector<int> &v, int sum) {
	if(sum > C) return;
	if(end < here) {
		v.push_back(sum);
		return;
	}
	go(here + 1, end, v, sum + arr[here]);
	go(here + 1, end, v, sum);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> C;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	go(0, N / 2 - 1, v1, 0);
	go(N / 2, N - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(int v : v1) {
		if(C - v >= 0) result += (int) (upper_bound(v2.begin(), v2.end(), C - v) - v2.begin());	
	}
	cout << result;
}
