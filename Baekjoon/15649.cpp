#include <bits/stdc++.h>

using namespace std;
int N, M;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
map<string, int> mp;

int main() {
	cin >> N >> M;
	string tmp;
	do {
		tmp = "";
		for(int i = 0; i < M; ++i) {
			tmp += arr[i] + '0';
			tmp += ' ';
		}
		mp.insert({tmp, 1});
	} while(next_permutation(arr, arr + N));
	
	
	for(auto it : mp) {
		cout << it.first << "\n";
	}
}
