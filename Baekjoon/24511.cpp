#include <bits/stdc++.h>

using namespace std;
int N, M, V, input_arr[100004];
bool isQ[100004];
queue<int> q;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> V;
		if(V == 0) isQ[i] = true;
	}
	for(int i = 0; i < N; ++i) cin >> input_arr[i];
	for(int i = N - 1; i >= 0; --i) {
		if(isQ[i]) q.push(input_arr[i]);
	}
	cin >> M;
	for(int i = 0; i < M; ++i) {
		cin >> V;
		q.push(V);
		cout << q.front() << " ";
		q.pop();
	}
}
