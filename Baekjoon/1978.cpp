#include <bits/stdc++.h>

using namespace std;
set<int> st;
int N, v, result = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	
	bool flag;
	for(int i = 2; i <= 1000; ++i) {
		flag = true;
		for(int j = 2; j < i; ++j) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if(flag) {
			st.insert(i);
		}
	}
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> v;
		if(st.find(v) != st.end()) ++result;
	}
	cout << result;
}
