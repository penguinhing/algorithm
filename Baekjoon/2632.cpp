#include <bits/stdc++.h>

using namespace std;
int N, k, tmp, value, result = 0;
vector<int> v[2];
int nsum[2][2100] = { 0 }, input[2];
map<int, int> mp[2];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	cin >> input[0] >> input[1];
	v[0].push_back(-1); v[1].push_back(-1);
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= input[i]; ++j) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	for (int i = 0; i < 2; ++i) {
		tmp = v[i].size() - 1;
		for (int j = 1; j <= tmp; ++j) {
			v[i].push_back(v[i][j]);
		}
		for (int j = 1; j <= v[i].size() - 1; ++j) {
			nsum[i][j] = nsum[i][j - 1] + v[i][j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= input[i]; ++j) {
			for (int l = 1; l <= input[i]; ++l) {
				value = nsum[i][l + j - 1] - nsum[i][l - 1];
				mp[i][value]++;
				if (j == input[i]) break;
			}
		}
	}
	result += mp[0][N] + mp[1][N];
	for (auto it : mp[0]) {
		if (N <= it.first) continue;
		result += mp[0][it.first] * mp[1][N - it.first];
	}
	cout << result;
}
