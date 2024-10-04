#include <bits/stdc++.h>

using namespace std;

string zfill(string a, int len) {
	string tmp = "";
	for (int i = 0; i < len - a.length(); ++i) tmp += '0';
	tmp += a;
	return tmp;
}

string ps(string a, string b) {
	int mxlen = max(a.length(), b.length());
	if (a.length() != mxlen) a = zfill(a, mxlen);
	if (b.length() != mxlen) b = zfill(b, mxlen);
	bool carry = false;
	int value;
	string ret = "", svalue;
	for (int i = mxlen - 1; i >= 0; --i) {
		value = (a[i] - '0') + (b[i] - '0') + ((carry) ? 1 : 0);
		carry = value >= 10;
		svalue = to_string(value);
		ret += svalue[svalue.length() - 1];
	}
	if (carry) ret += '1';
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << ps(a, b);
}
