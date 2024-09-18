#include <bits/stdc++.h>

using namespace std;
int nums[1000001] = { 0 };
int A, B;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	nums[1] = 1;
	for(int i = 2; i <= 1000000; ++i) {
		if(nums[i] != 0) continue;
		for(int j = i + i; j <= 1000000; j += i) nums[j] = 1;
	}
	cin >> A >> B;
	for(int i = A; i <= B; ++i) {
		if(nums[i] == 0) cout << i << "\n";
	}
}
