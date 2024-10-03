#include <bits/stdc++.h>

using namespace std;
int N;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	
	do {
		for(int i = 0; i < N; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while(next_permutation(arr, arr + N));
	
}
