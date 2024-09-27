#include <bits/stdc++.h>

using namespace std;
int A, B, v;
int visited[100004];

int bfs() {
	queue<int> q;
	q.push(A);
	visited[A] = 1;
	while(!q.empty()) {
		v = q.front(); q.pop();
		if(v == B) return visited[B] - 1;
		if (v * 2 <= 100000 && visited[v * 2] == 0) {
			q.push(v * 2);
			visited[v * 2] = visited[v] + 1;
		}
		if (v + 1 <= 100000 && visited[v + 1] == 0) {
			q.push(v + 1);
			visited[v + 1] = visited[v] + 1;			
		}
		if (v - 1 >= 0 && visited[v - 1] == 0) {
			q.push(v - 1);
			visited[v - 1] = visited[v] + 1;			
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> A >> B;
	cout << bfs();
}
