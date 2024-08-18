#include <bits/stdc++.h>

using namespace std;
string A, B, mx, mn, tmp = "";
vector<int> result;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> A >> B;
	
	mn = (A.length() > B.length()) ? B : A;
	mx = (A == mn) ? B : A;
	
	for(int i = 0; i < mx.length(); ++i) {
		if (mx.length() - mn.length() <= i) {
			tmp += mn[i - (mx.length() - mn.length())];
		}else tmp += "0";
	}
	mn = tmp;
	int tmp, up = 0;
	for (int i = mn.length() - 1; i >= 0; --i) {
		tmp = ((int)mn[i] - '0') + ((int)mx[i] - '0') + up;
		if (tmp >= 10) {
			result.push_back(tmp - 10);
			up = 1;
		}
		else {
			result.push_back(tmp);
			up = 0;
		}
	}
	if (up) result.push_back(up);
	reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i) cout << result[i];

}
