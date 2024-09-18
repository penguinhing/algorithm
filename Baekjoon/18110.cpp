#include <bits/stdc++.h>

using namespace std;
int N, a;
vector<int> v;

int main() {
	cin >> N;
	if(N == 0) {
		cout << 0; exit(0);
	}
	for(int i = 0; i < N; ++i) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ex = round(N * 0.15f);
	int hap = 0;
	for(int i = ex; i < N - ex; ++i) {
		hap += v[i];
	}
	double avg = hap / (double)(N - ex * 2);
	cout << round(avg);
}
