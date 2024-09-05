#include <bits/stdc++.h>

using namespace std;
int N, result = 0, total = 0, l, r, p;
bool de[4000004];
int num[2000004];
vector<int> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 2; i <= N; ++i) {
		if(de[i]) continue;
		int mul = 2;
		for(int j = i * mul; j <= N; j = i * mul) {
			de[j] = true;
			++mul;
		}
	}
	for(int i = 2; i <= N; ++i) {
		if(!de[i]) num[p++] = i;
	}
	
	total = num[0];
	while(true) {
		if(total == N) {
			++result;
		}
		if(l == p) break;
		if(total < N && r+1 < p) {
			total += num[++r];
		}
		else {
			total -= num[l++];
		}
	}
	cout << result;
}
