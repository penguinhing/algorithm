#include <bits/stdc++.h>

using namespace std;
int N, mx, result = INT_MIN;
int arr[1001];
int cnt[1001];

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	for(int i = 0; i < N; ++i) {
		mx = 0;
		for(int j = 0; j < i; ++j) {
			if(arr[j] < arr[i] && mx < cnt[j]) mx = cnt[j];
		}
		cnt[i] = mx + 1;
		result = max(cnt[i], result);
	}
	cout << result;
}
