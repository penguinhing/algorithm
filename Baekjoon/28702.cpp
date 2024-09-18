#include <bits/stdc++.h>

using namespace std;
string a, b, c;

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> a >> b >> c;
	int num;
	int cnt = 0;
	if(atoi(c.c_str())) num = atoi(c.c_str()) + 1;
	else if(atoi(b.c_str())) num = atoi(b.c_str()) + 2;
	else if(atoi(a.c_str())) num = atoi(a.c_str()) + 3;
	
	if(num % 3 == 0 && num % 5 == 0 ) cout << "FizzBuzz";
	else if(num % 3 == 0) cout << "Fizz";
	else if(num % 5 == 0) cout << "Buzz";
	else cout << num;
}
