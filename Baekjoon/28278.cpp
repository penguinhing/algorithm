#include <bits/stdc++.h>

using namespace std;
int N, c = 0; string input;
stack<int> st;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	cin.ignore();
	for(int i = 0; i < N; ++i) {
		getline(cin, input);
		
		if(input.length() >= 3) {
			st.push(stoi(input.substr(2)));
			++c;
		}
		else if (input == "2") {
			if(st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";--c;
				st.pop();
			}
		}
		else if(input == "3") cout << c << "\n";
		else if (input == "4") cout << (int)st.empty() << "\n";
		else if(input == "5") cout << (st.empty() ? -1 : st.top()) << "\n";
		
	}	
}
