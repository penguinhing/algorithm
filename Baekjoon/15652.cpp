#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> v;
void combi(int start, int depth) {
	if(depth == M) {
		for(int i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = start; i <= N; ++i) {
		v.push_back(i);
		combi(i, depth + 1);
		v.pop_back();
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	combi(1, 0);
}
