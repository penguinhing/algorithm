#include <bits/stdc++.h>

using namespace std;

int N;
int satisfied[4];
vector<int> lst[17];
vector<int> resultIdx;
int resultMin = INT_MAX;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	cin >> satisfied[0] >> satisfied[1] >> satisfied[2] >> satisfied[3];
	int a, b, c, d, e;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b >> c >> d >> e;
		lst[i].push_back(a); lst[i].push_back(b); lst[i].push_back(c); lst[i].push_back(d); lst[i].push_back(e);
	}
	bool flag;
	for (int i = 1; i < (1 << N); ++i) {
		int m[5] = { 0 };
		vector<int> tempIdx;
		flag = false;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				for (int x = 0; x < 5; ++x) {
					m[x] += lst[j][x];
				}
				tempIdx.push_back(j + 1);
			}
		}

		for (int j = 0; j < 4; ++j) {
			if (m[j] < satisfied[j]) flag = true;
		}
		if (flag) continue;
		sort(tempIdx.begin(), tempIdx.end());
		if(resultMin == m[4]) {
			for(int j = 0; j < resultIdx.size(); ++j) {
				if(tempIdx.size() <= j) {
					resultMin = m[4];
					resultIdx = tempIdx;
					break;
				}
				if(resultIdx[j] < tempIdx[j]) break;
				if(resultIdx[j] > tempIdx[j]) {
					resultMin = m[4];
					resultIdx = tempIdx;
					break;
				}
				
			}
		}
		if (resultMin > m[4]) {
			resultMin = m[4];
			resultIdx = tempIdx;
		}
	}
	if(resultMin == INT_MAX) {
		cout << -1;
	}
	else {
		cout << resultMin << "\n";
		for (int i = 0; i < resultIdx.size(); ++i) cout << resultIdx[i] << " ";	
	}	
}
