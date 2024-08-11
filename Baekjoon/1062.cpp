#include <bits/stdc++.h>

using namespace std;

int N, K, idx;

int words[50];
int learn = 532741;
int result = INT_MIN;

void dfs(char c, int depth) {
	if(depth > K - 5) {
		int count = 0;
		for(int i = 0; i < N; ++i) {
			if((learn & words[i]) == words[i]) {
				++count;
			}
		}
		result = max(result, count);
		return;
	}
	
	for(char i = c; i <= 'z'; ++i) {
		if(i == 'a' || i == 'n' || i == 't' || i == 'i' || i == 'c') continue;
		learn |= 1 << (int)(i - 'a');
		dfs(i+1, depth+1);
		learn ^= 1 << (int)(i - 'a');
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	string s;
	int bit;
	for(int i = 0; i < N; ++i) {
		bit = 0;
		cin >> s;
		for(int j = 0; j < s.length(); ++j) {
			bit |= 1 << (int)(s[j] - 'a');
		}
		words[i] = bit;
	}
	if (K < 5) {
		cout << 0; return 0;
	}
	
	dfs('a', 1);
	cout << result;
}
