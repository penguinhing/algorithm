#include <bits/stdc++.h>

using namespace std;

int N, len = 0, idx, mxIdx, tmpIdx;
vector<int> result;

int lis[1000004];
int lisIdx[1000004];

int arr[1000004];
int history[1000004];

int search(int value) {
	int lo = 1, hi = len;
	int idx = -1, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (lis[mid] < value) {
			lo = mid + 1;
			idx = lisIdx[mid];
		}
		else hi = mid - 1;

	}
	return idx;
}

int main() {
	fill(&history[0], &history[1000004], -1);
	fill(&lis[0], &lis [1000004], -1000000004);
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];

		idx = search(arr[i]);
		if (idx != -1) history[i] = idx;

		auto it = lower_bound(lis + 1, lis + 1 + len, arr[i]);
		if (*it == -1000000004) {
			++len;
			mxIdx = i;
		}
		*it = arr[i];
		lisIdx[it - lis] = i;
	}

	tmpIdx = mxIdx;
	while (tmpIdx != -1) {
		result.push_back(arr[tmpIdx]);
		tmpIdx = history[tmpIdx];
	}
	reverse(result.begin(), result.end());
	cout << len << "\n";
	for (int c : result) cout << c << " ";
}
