#include <bits/stdc++.h>

using namespace std;

int M, result;

vector<string> split(string s, char c) {
	vector<string> result;
	string tmp = "";
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == c) {
			result.push_back(tmp);
			tmp = "";
		}
		else tmp += s[i];
	}
	result.push_back(tmp);
	return result;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> M;
	cin.ignore();
	string input;
	for (int i = 0; i < M; ++i) {
		getline(cin, input);
		vector<string> command = split(input, ' ');
		if (command[0] == "add") result |= 1 << (stoi(command[1]) - 1);
		if (command[0] == "remove") result &= ~(1 << (stoi(command[1]) - 1));
		if(command[0] == "check") cout << ((result & (1 << (stoi(command[1]) - 1))) ? 1 : 0) << "\n";
		if (command[0] == "toggle") result ^= 1 << (stoi(command[1]) - 1);
		if (command[0] == "all") result = (1 << 20) - 1;
		if (command[0] == "empty") result = 0;
	}
}
