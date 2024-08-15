#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	int idx = 0;
	string S;
	bool result = false;
	cin >> S;
	while(true) {
		if(idx >= S.length()) {
			result = true; break;
		}
		if(((S[idx] == 'p' || S[idx] == 'i') && idx+1 >= S.length()) || (S[idx] == 'c' && idx+2 >= S.length())) break;
		if( (S[idx] == 'p' && S[idx+1] == 'i') || (S[idx] == 'k' && S[idx+1] == 'a')) idx += 2;
		else if(S[idx] == 'c' && S[idx+1] == 'h' && S[idx+2] == 'u') idx += 3;
		else break;
	}
	cout << (result ? "YES" : "NO");
}
