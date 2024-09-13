#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> v;
vector<int> result;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) v.push_back(i);

	int count = 0;
	int idx = 0;
	int death = 0;
	while (death != N) {
		if (v[idx] == -1) {
			idx = (idx + 1 >= N) ? 0 : idx + 1;
			continue;
		}
		++count;
		if (count == K) {
			count = 0;
			result.push_back(v[idx]);
			v[idx] = -1;
			++death;
		}
		idx = (idx + 1 >= N) ? 0 : idx + 1;
	}
	cout << "<";
	for (int i = 0; i < N; ++i) {
		if(i == N-1) cout << result[i] << ">";
		else cout << result[i] << ", ";
	}

}
