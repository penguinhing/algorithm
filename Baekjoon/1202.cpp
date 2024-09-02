#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N, K;
vector<pair<ll, ll>> dia;
vector<ll> bag;
priority_queue<ll> pq;
ll result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	ll a, b, c;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		dia.push_back({ a, b });
	}
	for (int i = 0; i < K; ++i) {
		cin >> c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end());
	sort(dia.begin(), dia.end());



	int j = 0;
	for (ll weight : bag) {

		for (int i = j; i < dia.size(); ++i) {
			if (weight < dia[i].first) {
				j = i;
				break;
			}
			pq.push(dia[i].second);
			if (dia.size() - 1 == i) j = dia.size();
		}

		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}
