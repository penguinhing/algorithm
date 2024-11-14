#include <bits/stdc++.h>

using namespace std;
int N, M, arr[10004], l = 0, r = 0, ret = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	
	int hap = 0;
	while(true) {
		if(hap < M) hap += arr[r++];
		else if(hap > M) hap -= arr[l++];
		if(hap == M) {
			++ret;
			hap += arr[r++];
		}
		if(r >= N) {
			while(l < N) {
				hap -= arr[l++];
				if(hap == M) ++ret;
			}
			break;
		}
	}
	cout << ret;
}
