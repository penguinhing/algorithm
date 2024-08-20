#include <bits/stdc++.h>

using namespace std;
int field[104][104];
int N, result = 0;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	int a, b, count;
	for(int z = 0; z < N; ++z) {
		cin >> a >> b;
		count = 0;
		for(int i = b; i < b + 10; ++i) {
			for(int j = a; j < a + 10; ++j) {
				if(field[i][j] == 1) continue;
				field[i][j] = 1; ++count;
				
			}
		}
		result += count;
	}
	cout << result;
}
