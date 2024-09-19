#include <bits/stdc++.h>

using namespace std;
int T, N, M, v, l, r, mid;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(NULL);
	cin >> T;
	for(int d = 0; d < T; ++d) {
		vector<int> A;
		cin >> N;
		for(int i = 0; i < N; ++i) {
			cin >> v;
			A.push_back(v);
		}
		sort(A.begin(), A.end());
		
		cin >> M;
		for(int i = 0; i < M; ++i) {
			cin >> v;
			l = 0; r = A.size() - 1;
			bool find = false;
			while(l <= r) {
				mid = (l + r) / 2;
				if(A[mid] == v) {
					find = true; break;
				}
				if(A[mid] > v) r = mid - 1;
				else l = mid + 1;
			}
			cout << ((find ? 1 : 0)) << "\n";
			
		}
		
			
	}
}
