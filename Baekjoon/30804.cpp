#include <bits/stdc++.h>

using namespace std;
int N, result = 0, arr[200003], cnt[11], l = 0, r = 0, one, two = 0;

void init() {
	one = arr[0];
	while (two == 0) {
		if (r >= N) {
			cout << N; exit(0);
		}
		if (one != arr[r++]) two = arr[r - 1];
		else ++cnt[one];
	}
	++cnt[two];
	result = max(result, r - l);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	init();
	while (r < N) {
		if (arr[r] != one && arr[r] != two) {
			while (cnt[one] != 0 && cnt[two] != 0) --cnt[arr[l++]];
			if (cnt[one] == 0) one = arr[r];
			else two = arr[r];
		}
		++cnt[arr[r]];
		result = max(result, r - l + 1);
		++r;
	}
	cout << result;
}
