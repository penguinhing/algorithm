#include <bits/stdc++.h>

using namespace std;
int N, K, result = 0;
int tap[104];
vector<int> v;
set<int> flug;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> K;
	int a;
	for(int i = 0; i < K; ++i) {
		cin >> a;
		v.push_back(a);
		++tap[a];
	}
	for(int i = 0; i < v.size(); ++i) {
		if(flug.size() < N) flug.insert(v[i]);
		else if (flug.find(v[i]) == flug.end()) {
			 for(auto it : flug) {
			 	if(tap[it] == 0) {
			 		flug.erase(it); break;
				 }
			 }
			 if(flug.size() == N) {
				 set<int> pair_set;
				 for(int j = i+1; j < v.size(); ++j) {
				 	if(pair_set.find(v[j]) == pair_set.end() && flug.find(v[j]) != flug.end()) {
				 		pair_set.insert(v[j]);
				 		if(pair_set.size() == flug.size()) {
				 			flug.erase(v[j]);
				 			break;
						 }
					 }
				 }
			 }
			flug.insert(v[i]);
			++result;
		}
		--tap[v[i]];
	}
	cout << result;
}
