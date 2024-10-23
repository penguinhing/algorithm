#include<bits/stdc++.h>
using namespace std;

int N, M, K, result = 0;
string S;

int main(){
	cin >> N >> M >> S;
	for(int i = 0; i < M - 2; ++i) {
		if (S[i] == 'O') continue;
		K = 0;
		while(S[i + 1] == 'O' && S[i + 2] == 'I') {
			++K;
			if(K == N) {
				++result; --K;
			}
			i += 2;
		}
	}
	cout << result;
	return 0; 
}
