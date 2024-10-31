#include <bits/stdc++.h>

using namespace std;
set<string> en;
string a, b;
vector<string> pr;
int N;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a >> b;
		if(b == "enter") en.insert(a);
		else en.erase(a);
	}	
	for(auto it : en) pr.push_back(it);
	sort(pr.begin(), pr.end());
	reverse(pr.begin(), pr.end());
	for(auto p : pr) cout << p << "\n";
}
