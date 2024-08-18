#include <bits/stdc++.h>

using namespace std;
map<string, double> mp;
int N;
double hap = 0.0f;
double result = 0.0f;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	mp.insert({"A+", 4.5}); mp.insert({"A0", 4.0}); mp.insert({"B+", 3.5}); mp.insert({"B0", 3.0}); mp.insert({"C+", 2.5});
	mp.insert({"C0", 2.0}); mp.insert({"D+", 1.5}); mp.insert({"D0", 1.0}); mp.insert({"F", 0.0f});
	string lecture, rank;
	double score;
	for(int i = 0; i < 20; ++i) {
		cin >> lecture >> score >> rank;
		if(rank == "P") continue;
		hap += score;
		result += (score * mp[rank]);
	}
	cout << fixed << setprecision(6) << (result / hap);
}
