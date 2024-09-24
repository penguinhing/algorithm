#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[1004];
int arr[1004];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		int len = 0;
		int mx = -1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && cnt[j] > mx) {
				len = cnt[j];
				mx = cnt[j];
			}
		}
		cnt[i] = len + arr[i];
	}
	cout << *max_element(&cnt[0], &cnt[1004]);
}
