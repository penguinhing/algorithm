#include <bits/stdc++.h>

using namespace std;
string N, boom;
string result = "";

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> boom;
	for(char c : N) {
		result += c;
		if(result.size() >= boom.size() && result.substr(result.size() - boom.size(), boom.size()) == boom) {
			result.erase(result.size() - boom.size(), boom.size());
		}
	}
	cout << (result.size() ? result : "FRULA");
}
