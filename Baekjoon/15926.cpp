#include <bits/stdc++.h>

using namespace std;
int N, value, result = 0;
stack<pair<char, int>> st;
map<int, int> mp;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	char c;
	for(int i = 0; i < N; ++i) {
		cin >> c;		
		if(st.empty()) st.push({c, i});
		else if (st.top().first == '(' && c == ')') {
			value = 2;
			for(int j = i; j > st.top().second; --j) {
				if(mp.find(j) != mp.end()) {
					value += mp[j];
					break;
				}
			}
			if(mp.find(st.top().second-1) != mp.end()) 
				mp[i] = value + mp[st.top().second-1];
			else mp[i] = value;
			st.pop();
		}
		else st.push({c, i});
	}
	for(auto it : mp) result = max(it.second, result);
	cout << result;
}
