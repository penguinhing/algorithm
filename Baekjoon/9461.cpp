#include <bits/stdc++.h>

using namespace std;   
int T, N;
long long arr[110] = {0, 1, 1, 1};

int main(){
    cin.tie(0); ios::sync_with_stdio(NULL);
    cin >> T;
    for(int d = 0; d < T; ++d) {
	    cin >> N;
	    if(N <= 3) {
	    	cout << 1 << "\n"; continue;
		}
		for(int i = 4; i <= N; ++i) arr[i] = arr[i-2] + arr[i-3];
		
		cout << arr[N] << "\n";	
	}
} 
