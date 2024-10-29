#include <bits/stdc++.h>

using namespace std;
int N, arr[1004], a[1004], b[1004], mxIdx, mxValue, result = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	for (int i = 0; i < N; ++i) {
		a[i] = 1;
		mxIdx = -1;
		mxValue = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && a[j] >= mxValue) {
				mxIdx = j;
				mxValue = a[j];
			}
		}
		if(mxIdx != -1) a[i] += a[mxIdx];
	}
	for(int i = N - 1; i >= 0; --i) {
		b[i] = 1;
		mxIdx = -1;
		mxValue = 0;
		for(int j = N - 1; j > i; --j) {
			if(arr[j] < arr[i] && b[j] >= mxValue) {
				mxIdx = j;
				mxValue = b[j];
			}
		}
		if(mxIdx != -1) b[i] += b[mxIdx];
	}
	for(int i = 0; i < N; ++i) result = max(a[i] + b[i] - 1, result);
	cout << result;
}
