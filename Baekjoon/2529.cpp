#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char bracket[10];
int k;
ll v;
string resultMx, resultMn;
ll mn = LLONG_MAX;
ll mx = LLONG_MIN;


bool check() {
	for(int i = 0; i < k; ++i) {
		if (bracket[i] == '>') {
			if(!(arr[i] > arr[i+1])) return false;
		}
		if (bracket[i] == '<') {
			if(!(arr[i] < arr[i+1])) return false;
		}
	}
	return true;
}


void combi(int n, int r, int depth) {
	if(depth == r) {
		if(check()) {
			string tmp;
			for(int i = 0; i < r; ++i) tmp += to_string(arr[i]);
			v = stoll(tmp);
			if(mx < v) {
				mx = v;
				resultMx = tmp;
			}
			if(mn > v) {
				mn = v;
				resultMn = tmp;
			}
		
		}
		return;
	}
	for(int i = depth; i < n; ++i) {
		swap(arr[i], arr[depth]);
		combi(n, r, depth + 1);
		swap(arr[i], arr[depth]);
	}
	
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> k;
	for(int i = 0; i < k; ++i) cin >> bracket[i];
	combi(10, k+1, 0);
	cout << resultMx << "\n";
	cout << resultMn;
}
