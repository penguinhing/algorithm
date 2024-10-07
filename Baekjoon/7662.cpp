#include <bits/stdc++.h>

using namespace std;

int T, N, a;
int removed[1000004];
char opr;
priority_queue<pair<int, int>> mxQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnQ;

void sync() {
	while (!mxQ.empty() && removed[mxQ.top().second]) mxQ.pop();
	while (!mnQ.empty() && removed[mnQ.top().second]) mnQ.pop();
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	for (int d = 0; d < T; ++d) {
		cin >> N;
		memset(removed, 0, sizeof(removed));
		for (int i = 0; i < N; ++i) {
			cin >> opr >> a;
			if (opr == 'I') {
				mxQ.push({ a, i });
				mnQ.push({ a, i });
			}
			else if (opr == 'D') {
				sync();
				if (a == 1 && !mxQ.empty()) {
					removed[mxQ.top().second] = 1;
					mxQ.pop();
				}
				else if (!mnQ.empty()) {
					removed[mnQ.top().second] = 1;
					mnQ.pop();
				}

			}
		}
		sync();
		if (mxQ.empty() || mnQ.empty()) cout << "EMPTY\n";
		else cout << mxQ.top().first << " " << mnQ.top().first << "\n";
		priority_queue<pair<int, int>> tmp1;
		mxQ = tmp1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp2;
		mnQ = tmp2;
	}
}
