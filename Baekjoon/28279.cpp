#include <bits/stdc++.h>

using namespace std;
int N, a, b;
deque<int> dq;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	while(N--)	 {
		cin >> a;
		if(a == 1) {
			cin >> b;
			dq.push_front(b);
		}
		if(a == 2) {
			cin >> b;
			dq.push_back(b);
		}
		if(a == 3) {
			if(dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if(a == 4) {
			if(dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if(a == 5) cout << dq.size() << "\n";
		if(a == 6) cout << dq.empty() << "\n";
		if(a == 7) {
			if(dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		if(a == 8) {
			if(dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}
}
