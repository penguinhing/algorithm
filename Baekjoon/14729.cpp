#include <bits/stdc++.h>

using namespace std;
int N;
float score;
vector<float> lst;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> score;
		lst.push_back(score);
	}
	
	sort(lst.begin(), lst.end());
	
	for(int i = 0; i < 7; ++i) {
		cout << fixed << setprecision(3) << lst[i] << "\n";
	}
	
}
