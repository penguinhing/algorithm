#include <bits/stdc++.h>

using namespace std;
int A, B, C;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> A >> B >> C;
	cout << A + B - C << "\n";
	string t = "";
	t += to_string(A); t += to_string(B);
	cout << stoi(t) - C;
}
