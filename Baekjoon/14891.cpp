#include <bits/stdc++.h>

using namespace std;
int K, a, b, result = 0, npos, arrow;
string cog[5], tmp;

void rotate(int number, int direction) {
	queue<pair<int, int>> q;
	int visited[5] = { 0 };
	visited[number] = 1;
	q.push({number, direction});
	while(!q.empty()) {
		npos = q.front().first;
		arrow = q.front().second; q.pop();
		
		if(npos-1 >= 0 && visited[npos-1] == 0 && cog[npos-1][2] != cog[npos][6]) {
			q.push({npos-1, arrow * -1});
			visited[npos-1] = 1;
		}
		if(npos+1 < 4 && visited[npos+1] == 0 && cog[npos+1][6] != cog[npos][2]) {
			q.push({npos+1, arrow * -1});
			visited[npos+1] = 1;
		}
		
		tmp = "";
		if(arrow == 1) {
			tmp += cog[npos][cog[npos].length()-1];
			for(int i = 0; i < cog[npos].length()-1; ++i) tmp += cog[npos][i];
		}
		else {
			for(int i = 1; i < cog[npos].length(); ++i) tmp += cog[npos][i];
			tmp += cog[npos][0];
		}
		cog[npos] = tmp;
	}
}


int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	for(int i = 0; i < 4; ++i) cin >> cog[i];
	cin >> K;
	for(int i = 0; i < K; ++i) {
		cin >> a >> b;
		rotate(a-1, b);
	}
	for(int i = 0; i < 4; ++i) {
		result += ((int) (cog[i][0]-'0') << i);
	}
	cout << result;
}
