#include <bits/stdc++.h>

using namespace std;
int N , result = 0;
vector<string> words;
priority_queue<pair<int, char>> pq;
string v;
map<char, int> mp;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i)  {
		cin >> v;
		words.push_back(v);
	}
	
	for(int i = 0; i < words.size(); ++i) {
		int sq = words[i].length() - 1;
		for(int j = 0; j < words[i].length(); ++j) {
			mp[words[i][j]] += pow(10, sq--);
		}
	}
	
	for(auto it : mp) pq.push({mp[it.first], it.first});
	
	int start = 9;
	while(!pq.empty()) {
		mp[pq.top().second] = start--;
		pq.pop();
	}
	
	for(int i = 0; i < words.size(); ++i) {
		string sq = "";
		for(int j = 0; j < words[i].length(); ++j) {
			sq += to_string(mp[words[i][j]]);
		}
		result += stoi(sq);
	}
	cout << result;
}
