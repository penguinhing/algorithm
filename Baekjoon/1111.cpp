#include <bits/stdc++.h>

using namespace std;
int N, arr[53];
set<int> result;

void dfs(int a, int b, int depth)  {
	if(depth == N) {
		result.insert(arr[N - 1] * a + b);
		return;
	}
	if(arr[depth - 1] * a + b == arr[depth]) dfs(a, b, depth + 1);
	else return;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	if(N == 1) {
		cout << "A"; return 0;
	}
	for(int i = -200; i <= 200; ++i) {
		int a = arr[0] * i;
		int b = arr[1];
		int value;
		if(a < b) {
			if(a < 0 && b >= 0) value = abs(a) + abs(b);
			else value = abs(abs(a) - abs(b));
		}
		else if (a > b) {
			if(a > 0 && b < 0) value = abs(abs(a) + abs(b)) * -1;
			else value = abs(abs(a) - abs(b)) * -1;
		}
		else value = 0;
		dfs(i, value, 1);
	}
	if(result.size() > 1) cout << "A";
	else if(result.size() == 0) cout << "B";
	else {
		for(int a : result) cout << a;
	}
}
