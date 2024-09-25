#include <bits/stdc++.h>

using namespace std;
int N, lo, hi, mid;
int arr[1000004];
vector<int> nums;
set<int> tmp;

int print(int value) {
	lo = 1; hi = nums.size();
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (value < nums[mid]) {
			hi = mid - 1;
		}
		else if (value > nums[mid]) lo = mid + 1;
		else return mid - 1;
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		tmp.insert(arr[i]);
	}
	nums.push_back(-1);
	for (int i : tmp) nums.push_back(i);
	sort(nums.begin() + 1, nums.end());
	for (int i = 1; i <= N; ++i) {
		cout << print(arr[i]) << " ";
	}
}
