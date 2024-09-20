#include <bits/stdc++.h>

using namespace std;
string N;
deque<string> dq;
int value, result;

void calc(string v) {
	if (!dq.empty() && dq.back() == "+") {
		dq.pop_back();
		value = stoi(dq.back()) + stoi(v);
		dq.pop_back();
		dq.push_back(to_string(value));
	}
	else dq.push_back(v);
}

int main() {
	cin >> N;
	string v = "";
	for (int i = 0; i < N.length(); ++i) {
		if (N[i] == '+' || N[i] == '-') {
			calc(v);
			v = "";
			string opr = ""; opr += N[i];
			dq.push_back(opr);
		}
		else v += N[i];
	}
	calc(v);
	result = stoi(dq.front()); dq.pop_front();
	while (!dq.empty()) {
		if (dq.front() != "-") result -= stoi(dq.front());
		dq.pop_front();
	}
	cout << result;
}
