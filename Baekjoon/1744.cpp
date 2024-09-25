#include <bits/stdc++.h>

using namespace std;
int N, a, result = 0;
vector<int> v;
stack<int> ast, bst;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a; v.push_back(a);
	}
	sort(v.begin(), v.end());
	int boundary = -1;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] < 0) boundary = i;
	}
	if (boundary != -1) reverse(v.begin(), v.begin() + boundary + 1);
	
	for (int i = v.size() - 1; i > boundary; --i) {
		if(ast.empty()) {
			ast.push(v[i]); continue;
		}
		if(v[i] >= 2) {
			result += v[i] * ast.top();
			ast.pop();
			continue;
		}
		ast.push(v[i]);
	}
	for(int i = boundary; i >= 0; --i) {
		if(bst.empty()) {
			bst.push(v[i]); continue;
		}
		result += v[i] * bst.top();
		bst.pop();
	}
	if(!bst.empty()) {
		if( (!ast.empty() && ast.top() != 0) || ast.empty()) result += bst.top();
	}
	while(!ast.empty()) {
		result += ast.top();
		ast.pop();
	}
	cout << result;
}
