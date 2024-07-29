#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num;
vector<char> opr;
int result = INT_MIN;
int max_bracket;
vector<int> brIdx;

int calc(int a, char op, int b) {
	if(op == '*') return a * b;
	if(op == '+') return a + b;
	if(op == '-') return a - b;
}

int totalCalc() {
	vector<int> _num;
	vector<char> _opr;
	for(int i = 0; i < num.size(); ++i) _num.push_back(num[i]);
	for(int i = 0; i < opr.size(); ++i) _opr.push_back(opr[i]);
	
	int idx, hap;
	for(int i = 0; i < brIdx.size(); ++i) {
		idx = brIdx[i];
		hap = calc(_num[idx], _opr[idx], _num[idx+1]);
		_num[idx] = hap;
		_num[idx+1] = 0;
		_opr[idx] = '+';
	}
	
	for(int i = 0; i < _num.size()-1; ++i) {
		hap = calc(_num[i], _opr[i], _num[i+1]);
		_num[i+1] = hap;
	}
	
	return _num[_num.size()-1];
}

void rec(int startIdx, int bracket) {
	if(bracket == max_bracket) {
		result = max(result, totalCalc()); return; 
	}
	if (startIdx+1 >= num.size()) return;
	
	for(int i = startIdx; i < num.size()-1; ++i) {
		brIdx.push_back(i);
		rec(i + 2, bracket+1);
		brIdx.pop_back();
	}
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N;
	char c;
	int b = 0;
	int count = 0;
	for(int i = 0; i < N; ++i) {
		cin >> c;
		if (c == '*' || c == '-' || c == '+') opr.push_back(c);
		else {
			num.push_back(c - '0');
			++count;
			if(count == 2) {
				++b;
				count = 0;
			}
		}
	}
	for(max_bracket = 1; max_bracket <= b; ++max_bracket) {
		rec(0, 0);
	}
	if(N == 1) cout << num[0];
	else cout << result;	
}
